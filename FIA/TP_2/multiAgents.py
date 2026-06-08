# multiAgents.py
# --------------
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


from util import manhattanDistance
from game import Directions
import random, util

from game import Agent
from pacman import GameState

class ReflexAgent(Agent):
    """
    A reflex agent chooses an action at each choice point by examining
    its alternatives via a state evaluation function.

    The code below is provided as a guide.  You are welcome to change
    it in any way you see fit, so long as you don't touch our method
    headers.
    """


    def getAction(self, gameState: GameState):
        """
        You do not need to change this method, but you're welcome to.

        getAction chooses among the best options according to the evaluation function.

        Just like in the previous project, getAction takes a GameState and returns
        some Directions.X for some X in the set {NORTH, SOUTH, WEST, EAST, STOP}
        """
        # Collect legal moves and successor states
        legalMoves = gameState.getLegalActions()

        # Choose one of the best actions
        scores = [self.evaluationFunction(gameState, action) for action in legalMoves]
        bestScore = max(scores)
        bestIndices = [index for index in range(len(scores)) if scores[index] == bestScore]
        chosenIndex = random.choice(bestIndices) # Pick randomly among the best

        "Add more of your code here if you want to"

        return legalMoves[chosenIndex]

    def evaluationFunction(self, currentGameState: GameState, action):
        """
        Design a better evaluation function here.

        The evaluation function takes in the current and proposed successor
        GameStates (pacman.py) and returns a number, where higher numbers are better.

        The code below extracts some useful information from the state, like the
        remaining food (newFood) and Pacman position after moving (newPos).
        newScaredTimes holds the number of moves that each ghost will remain
        scared because of Pacman having eaten a power pellet.

        Print out these variables to see what you're getting, then combine them
        to create a masterful evaluation function.
        """
        # Useful information you can extract from a GameState (pacman.py)
        successorGameState = currentGameState.generatePacmanSuccessor(action)
        newPos = successorGameState.getPacmanPosition()
        newFood = successorGameState.getFood()
        newGhostStates = successorGameState.getGhostStates()
        newScaredTimes = [ghostState.scaredTimer for ghostState in newGhostStates]

        "*** YOUR CODE HERE ***"
        #garantir que o pacman nao pare
        if action == Directions.STOP:
           return -float('inf')

        #verificar fantasmas perto
        for i, fantasma in enumerate(newGhostStates):
            distancia = manhattanDistance(newPos, fantasma.getPosition())
            #proxima direcao e um fantasma normal perto
            if newScaredTimes[i] == 0 and distancia <= 1:
                return -float('inf')

        lista_Comidas = newFood.asList()
        valorComida = 0
        
        #calcular a distancia da comida mais proxima
        if lista_Comidas:
            distanciaComida = [manhattanDistance(newPos, comida) for comida in lista_Comidas]
            valorComida = 10 / min(distanciaComida)

        #somar tempo dos fantasmas assustados
        fantasma_Assustado = sum(newScaredTimes)

        return successorGameState.getScore() + valorComida + fantasma_Assustado

def scoreEvaluationFunction(currentGameState: GameState):
    """
    This default evaluation function just returns the score of the state.
    The score is the same one displayed in the Pacman GUI.

    This evaluation function is meant for use with adversarial search agents
    (not reflex agents).
    """
    return currentGameState.getScore()

class MultiAgentSearchAgent(Agent):
    """
    This class provides some common elements to all of your
    multi-agent searchers.  Any methods defined here will be available
    to the MinimaxPacmanAgent, AlphaBetaPacmanAgent & ExpectimaxPacmanAgent.

    You *do not* need to make any changes here, but you can if you want to
    add functionality to all your adversarial search agents.  Please do not
    remove anything, however.

    Note: this is an abstract class: one that should not be instantiated.  It's
    only partially specified, and designed to be extended.  Agent (game.py)
    is another abstract class.
    """

    def __init__(self, evalFn = 'scoreEvaluationFunction', depth = '2'):
        self.index = 0 # Pacman is always agent index 0
        self.evaluationFunction = util.lookup(evalFn, globals())
        self.depth = int(depth)

class MinimaxAgent(MultiAgentSearchAgent):
    """
    Your minimax agent (question 2)
    """

    def getAction(self, gameState: GameState):
        """
        Returns the minimax action from the current gameState using self.depth
        and self.evaluationFunction.

        Here are some method calls that might be useful when implementing minimax.

        gameState.getLegalActions(agentIndex):
        Returns a list of legal actions for an agent
        agentIndex=0 means Pacman, ghosts are >= 1

        gameState.generateSuccessor(agentIndex, action):
        Returns the successor game state after an agent takes an action

        gameState.getNumAgents():
        Returns the total number of agents in the game

        gameState.isWin():
        Returns whether or not the game state is a winning state

        gameState.isLose():
        Returns whether or not the game state is a losing state
        """
        "*** YOUR CODE HERE ***"
        #lista de direcoes legais do pacman
        direcoes_legais = gameState.getLegalActions(0)

        #lista do custo de cada direcao
        custo_direcao = [self.getValor(gameState.generateSuccessor(0, action), self.depth, 1) for action in direcoes_legais]

        return direcoes_legais[custo_direcao.index(max(custo_direcao))]

    def getValor(self, gameState: GameState, profundidade: int, indiceAgente: int):

        #caso base para terminar a recursao
        if profundidade == 0 or gameState.isWin() or gameState.isLose():  
            return self.evaluationFunction(gameState) 
           
        #garantir que todos jogaram antes de diminuir a profundidade
        if (gameState.getNumAgents() == indiceAgente + 1) and (profundidade > 0):  
            profundidade -= 1
        
        #minimizar fantasmas
        if indiceAgente >= 1:  
            return self.minValor(gameState, profundidade, indiceAgente)
        
        #maximizar pacman
        if indiceAgente == 0:  
            return self.maxValor(gameState, profundidade, indiceAgente)
        

    def minValor(self, gameState: GameState, profundidade: int, indeceAgente: int):

        #direcoes legais dos agentes(fantasmas)
        direcoes = gameState.getLegalActions(indeceAgente)
        minVal = float('inf')

        #calcular o menor valor entre as direcoes
        for direcao in direcoes:
            next = gameState.generateSuccessor(indeceAgente, direcao)
            minVal = min(minVal, self.getValor(next, profundidade, (indeceAgente + 1) % gameState.getNumAgents()))

        return minVal

    def maxValor(self, gameState: GameState, profundidade: int, indeceAgente: int):
        #direcoes legais dos agentes(pacman)
        direcoes = gameState.getLegalActions(indeceAgente)
        maxVal = -float('inf')

        #calcular o maior valor entre as direcoes
        for direcao in direcoes:
            successor = gameState.generateSuccessor(indeceAgente, direcao)
            maxVal = max(maxVal, self.getValor(successor, profundidade, (indeceAgente + 1) % gameState.getNumAgents()))

        return maxVal
        util.raiseNotDefined()

class AlphaBetaAgent(MultiAgentSearchAgent):
    """
    Your minimax agent with alpha-beta pruning (question 3)
    """

    def getAction(self, gameState: GameState):
        """
        Returns the minimax action using self.depth and self.evaluationFunction
        """
        "*** YOUR CODE HERE ***"
        melhorValor = -float('inf') #melhor valor ate agora
        alfa = -float('inf') #limite inferior
        beta = float('inf') #limite superior
        melhor_dir = None #melhor direcao ate agora
        
        #direcao possiveis para o pacman
        for direcao in gameState.getLegalActions(0):
            next = gameState.generateSuccessor(0, direcao)
            valor = self.getValor(next, self.depth, 1, alfa, beta)
            
            #atualizar a melhor
            if valor > melhorValor:
                melhorValor = valor
                melhor_dir = direcao
                
            #atualizar alfa
            alfa = max(alfa, melhorValor)

        return melhor_dir

    def getValor(self, gameState: GameState, profundidade: int, indiceAgente: int, alfa: float, beta: float):
        
        #caso base , fim da arvore | vitoria | derrota
        if profundidade == 0 or gameState.isWin() or gameState.isLose():
            return self.evaluationFunction(gameState)

        #garantir que todos jogaram antes de diminuir a profundidade
        if indiceAgente == gameState.getNumAgents():
            return self.getValor(gameState, profundidade - 1, 0, alfa, beta)

        #maximizar pacman    
        if indiceAgente == 0:
            return self.maxValor(gameState, profundidade, indiceAgente, alfa, beta)
        #minimizar fantasmas
        else:
            return self.minValor(gameState, profundidade, indiceAgente, alfa, beta)


    def maxValor(self, gameState: GameState, profundidade: int, indiceAgente: int, alfa: float, beta: float):
        valorMax = -float('inf')
        
        #direcoes possiveis(pacman)
        for direcao in gameState.getLegalActions(indiceAgente):
            next = gameState.generateSuccessor(indiceAgente, direcao)
            valor = self.getValor(next, profundidade, indiceAgente + 1, alfa, beta)
            
            valorMax = max(valorMax, valor) #atualizar o maior valor
            
            #corte beta (ignorar os restantes insificientes)
            if valorMax > beta: 
                return valorMax
            
            alfa = max(alfa, valorMax)#atualizar alfa
            
        return valorMax

    def minValor(self, gameState: GameState, profundidade: int, indiceAgente: int, alfa: float, beta: float):
        valorMin = float('inf')
        
        #direcoes possiveis(fantasmas)
        for direcao in gameState.getLegalActions(indiceAgente):
            next = gameState.generateSuccessor(indiceAgente, direcao)
            valor = self.getValor(next, profundidade, indiceAgente + 1, alfa, beta)
            
            valorMin = min(valorMin, valor) #atualizar o valor minimo
            
            #corte alfa(ignorar os restantes insificientes)
            if valorMin < alfa:
                return valorMin
            
            beta = min(beta, valorMin) #atualizar beta
            
        return valorMin
        util.raiseNotDefined()

class ExpectimaxAgent(MultiAgentSearchAgent):
    """
      Your expectimax agent (question 4)
    """

    def getAction(self, gameState: GameState):
        """
        Returns the expectimax action using self.depth and self.evaluationFunction

        All ghosts should be modeled as choosing uniformly at random from their
        legal moves.
        """
        "*** YOUR CODE HERE ***"
        # lista de direcoes possiveis para o Pacman
        direcoes_legais = gameState.getLegalActions(0)

        # lista custo de cada direcao
        custo_direcao = [self.getValor(gameState.generateSuccessor(0, direcao), self.depth, 1) for direcao in direcoes_legais]

        return direcoes_legais[custo_direcao.index(max(custo_direcao))]

    def getValor(self, gameState: GameState, profundidade: int, indiceAgente: int):
        # caso base: fim da profundidade | vitoria | derrota
        if profundidade == 0 or gameState.isWin() or gameState.isLose():
            return self.evaluationFunction(gameState)

        # garantir que todos jogaram antes de diminuir a profundidade
        if indiceAgente == gameState.getNumAgents():
            return self.getValor(gameState, profundidade - 1, 0)

        #maximizar Pacman
        if indiceAgente == 0:
            return self.maxValor(gameState, profundidade, indiceAgente)

        #reduzir a probabilidade dos fantasmas
        return self.expValor(gameState, profundidade, indiceAgente)
    

    def maxValor(self, gameState: GameState, profundidade: int, indiceAgente: int):
        valorMax = -float('inf')
        
        #direcoes possiveis (Pacman)
        for direcao in gameState.getLegalActions(indiceAgente):
            next = gameState.generateSuccessor(indiceAgente, direcao) #gerar next direcaO
            valor = self.getValor(next, profundidade, indiceAgente + 1) #obter valor do next 
            
            valorMax = max(valorMax, valor) #atualizar o maior valor
            
        return valorMax

    def expValor(self, gameState: GameState, profundidade: int, indiceAgente: int):
        #direcoes possiveis (fantasmas)
        direcoes = gameState.getLegalActions(indiceAgente)
        if not direcoes:
            return self.evaluationFunction(gameState)

        soma = 0
        prob = 1.0 / len(direcoes)  # calcular probabilidade uniforme (1/n)
        
        #calcular a soma do valor esperado dos fantasmas
        for direcao in direcoes:
            next = gameState.generateSuccessor(indiceAgente, direcao)
            soma += (prob * self.getValor(next, profundidade, indiceAgente + 1))
            
        return soma
        util.raiseNotDefined()

def betterEvaluationFunction(currentGameState: GameState):
    """
    Your extreme ghost-hunting, pellet-nabbing, food-gobbling, unstoppable
    evaluation function (question 5).

    DESCRIPTION: <write something here so we know what you did>
    """
    "*** YOUR CODE HERE ***"
    pacmanPos = currentGameState.getPacmanPosition() #posição do pacman
    lista_cmida = currentGameState.getFood().asList() #lista de comida
    fantasmas = currentGameState.getGhostStates() #fantasmas
    scaredTimes = [ghostState.scaredTimer for ghostState in fantasmas]   #tempo de susto dos fantasmas         
    score = currentGameState.getScore()

    # Distância para a comida mais próxima
    if lista_cmida:                
        dist_cmida = [manhattanDistance(pacmanPos, food) for food in lista_cmida] #calcular distancias da comida
        score += 10.0 / min(dist_cmida)  # Recompensa por estar perto da comida
        
    # Distância para os fantasmas
    for i, ghostState in enumerate(fantasmas):
        pos_fantasma = ghostState.getPosition() #posição fantasma
        dist_pac_fan = manhattanDistance(pacmanPos, pos_fantasma) #distancia pacman-fantasma
        
        if scaredTimes[i] > 0:
            score += scaredTimes[i]  # Recompensa por fantasmas assustados
        else:
            if dist_pac_fan > 0:
                score -= 10.0 / dist_pac_fan  # Penalidade por estar perto de fantasmas normais
                
    return score
    
# Abbreviation
better = betterEvaluationFunction