# valueIterationAgents.py
# -----------------------
# Licensing Information:  You are free to use or extend these projects for
# educational purposes provided that (1) you do not distribute or publish
# solutions, (2) you retain this notice, and (3) you provide clear
# attribution to UC Berkeley, including a link to http://ai.berkeley.edu.
# 
# Attribution Information: The Pacman AI projects were developed at UC Berkeley.
# The core projects and autograders were primarily created by John DeNero
# (denero@cs.berkeley.edu) and Dan Klein (klein@cs.berkeley.edu).
# Student side autograding was added by Brad Miller, Nick Hay, and
# Pieter Abbeel (pabbeel@cs.berkeley.edu).


# valueIterationAgents.py
# -----------------------
# Licensing Information:  You are free to use or extend these projects for
# educational purposes provided that (1) you do not distribute or publish
# solutions, (2) you retain this notice, and (3) you provide clear
# attribution to UC Berkeley, including a link to http://ai.berkeley.edu.
# 
# Attribution Information: The Pacman AI projects were developed at UC Berkeley.
# The core projects and autograders were primarily created by John DeNero
# (denero@cs.berkeley.edu) and Dan Klein (klein@cs.berkeley.edu).
# Student side autograding was added by Brad Miller, Nick Hay, and
# Pieter Abbeel (pabbeel@cs.berkeley.edu).


import mdp, util

from learningAgents import ValueEstimationAgent
import collections

class ValueIterationAgent(ValueEstimationAgent):
    """
        * Please read learningAgents.py before reading this.*

        A ValueIterationAgent takes a Markov decision process
        (see mdp.py) on initialization and runs value iteration
        for a given number of iterations using the supplied
        discount factor.
    """
    def __init__(self, mdp, discount = 0.9, iterations = 100):
        """
          Your value iteration agent should take an mdp on
          construction, run the indicated number of iterations
          and then act according to the resulting policy.

          Some useful mdp methods you will use:
              mdp.getStates()
              mdp.getPossibleActions(state)
              mdp.getTransitionStatesAndProbs(state, action)
              mdp.getReward(state, action, nextState)
              mdp.isTerminal(state)
        """
        self.mdp = mdp
        self.discount = discount
        self.iterations = iterations
        self.values = util.Counter() # A Counter is a dict with default 0

        self.runValueIteration()
        
    def runValueIteration(self):
        "*** YOUR CODE HERE ***"
        # Repetimos o processo varias vezes ate os valores convergirem
        for i in range(self.iterations):
            newValues = util.Counter()  # Dicionario temporario para calcular novos valores

            # Percorre cada estado e recalcula seu valor
            for state in self.mdp.getStates():

                if self.mdp.isTerminal(state):
                    newValues[state] = 0  # Estados finais nao tem futuro valor = 0
                    
                else:
                    # Minhas acoes disponiveis
                    actions = self.mdp.getPossibleActions(state)
                    if not actions:
                        newValues[state] = 0  # Caso nenhuma acao disponivel                    
                    else:
                        # Calcula os Q-values e pega o maximo
                        qVals = [self.computeQValueFromValues(state, action) for action in actions]
                        newValues[state] = max(qVals)

            # Atualiza os valores
            self.values = newValues

            
    def getValue(self, state):
        """
          Return the value of the state (computed in __init__).
        """
        return self.values[state]


    def computeQValueFromValues(self, state, action):
        """
          Compute the Q-value of action in state from the
          value function stored in self.values.
        """
        "*** YOUR CODE HERE ***"
        # Calcula Q(s, a) = quanto de recompensa essa acao traz
        # Formula: media ponderada de recompensa imediata mais valor do proximo estado
        qVal = 0
        
        # Para cada proximo estado possivel e sua probabilidade
        for nextState, prob in self.mdp.getTransitionStatesAndProbs(state, action):
            
            reward = self.mdp.getReward(state, action, nextState)
            # Soma probabilidade vezes recompensa agora mais desconto vezes valor futuro
            qVal += prob * (reward + self.discount * self.values[nextState])
            
        return qVal
        #util.raiseNotDefined()

    def computeActionFromValues(self, state):
        """
          The policy is the best action in the given state
          according to the values currently stored in self.values.

          You may break ties any way you see fit.  Note that if
          there are no legal actions, which is the case at the
          terminal state, you should return None.
        """
        "*** YOUR CODE HERE ***"
        if self.mdp.isTerminal(state):
            return None  # Nao ha acao possivel no final

        # Pega todas as acoes legais e escolhe a melhor com maior Q-value
        # max compara cada acao e retorna a com maior valor
        actions = self.mdp.getPossibleActions(state)
        bestAction = max(actions, key=lambda action: self.computeQValueFromValues(state, action))
        return bestAction
        util.raiseNotDefined()

    def getPolicy(self, state):
        return self.computeActionFromValues(state)

    def getAction(self, state):
        "Returns the policy at the state (no exploration)."
        return self.computeActionFromValues(state)

    def getQValue(self, state, action):
        return self.computeQValueFromValues(state, action)


class PrioritizedSweepingValueIterationAgent(ValueIterationAgent):
    """
        * Please read learningAgents.py before reading this.*

        A PrioritizedSweepingValueIterationAgent takes a Markov decision process
        (see mdp.py) on initialization and runs prioritized sweeping value iteration
        for a given number of iterations using the supplied parameters.
    """
    def __init__(self, mdp, discount = 0.9, iterations = 100, theta = 1e-5):
        """
          Your prioritized sweeping value iteration agent should take an mdp on
          construction, run the indicated number of iterations,
          and then act according to the resulting policy.
        """
        self.theta = theta
        ValueIterationAgent.__init__(self, mdp, discount, iterations)

    def runValueIteration(self):
        "*** YOUR CODE HERE ***"
        # Passo 1: Descobre o historico reverso para cada estado quem pode levar a ele
        # Precisamos saber quando um estado muda quem foi afetado por ele
        predecessores = {}
        for state in self.mdp.getStates():
            predecessores[state] = set()
        for state in self.mdp.getStates():
            for action in self.mdp.getPossibleActions(state):
                for nextState, prob in self.mdp.getTransitionStatesAndProbs(state, action):
                    if prob > 0:
                        predecessores[nextState].add(state)

        # Passo 2: Monta uma lista de tarefas prioritaria
        # Coloca no topo os estados que tem maior potencial de mudanca
        # Diferenca entre valor atual e o melhor Q-value possivel
        queue = util.PriorityQueue()
        for state in self.mdp.getStates():
            if not self.mdp.isTerminal(state):
                # Calcula o melhor Q(s,a) que esse estado poderia ter
                qVals = [self.computeQValueFromValues(state, action) for action in self.mdp.getPossibleActions(state)]
                maxQ = max(qVals)
                # Quanto esse estado poderia melhorar erro entre valor atual e ideal
                diff = abs(self.values[state] - maxQ)
                # Prioridade negativa porque fila eh min-heap queremos maior erro primeiro
                queue.update(state, -diff)

        # Passo 3: Processa a fila atualizamos os estados mais urgentes
        for i in range(self.iterations):
            if queue.isEmpty():
                break  # Se nao ha mais estados para atualizar paramos

            # Pega o estado com maior erro estimado
            state = queue.pop()
            if not self.mdp.isTerminal(state):
                # Recalcula o valor desse estado com os novos dados
                qVals = [self.computeQValueFromValues(state, action) for action in self.mdp.getPossibleActions(state)]
                self.values[state] = max(qVals)

            # Passo 4: Propaga a mudanca
            # Se esse estado mudou avaliamos se seus antecessores tambem precisam ser re-analisados
            for p in predecessores[state]:
                if not self.mdp.isTerminal(p):
                    # Refaz os calculos do predecessor
                    qVals = [self.computeQValueFromValues(p, action) for action in self.mdp.getPossibleActions(p)]
                    maxQ = max(qVals)
                    diff = abs(self.values[p] - maxQ)
                    # Se o erro eh significativo maior que theta volta para fila
                    if diff > self.theta:
                        queue.update(p, -diff)
