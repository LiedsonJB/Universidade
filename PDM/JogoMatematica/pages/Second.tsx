// TELA DO JOGO - Onde o utilizador resolve operações matemáticas
import React, { useMemo, useState } from "react";
import { Alert, Text, View, TextInput, ScrollView } from "react-native";
import { useNavigation, useRoute, RouteProp } from '@react-navigation/native';
import { NativeStackNavigationProp } from '@react-navigation/native-stack';
import { RootStackParamList } from '../navigation/type';
import Background from "../compoments/Background/background";
import style from "../style";
import Box from "../compoments/box/box";
import { aleatorio, verificarR } from "../utils/funcoes";
import Button from "../compoments/buttons/buttons";

// Tipos para navegação
type Nav = NativeStackNavigationProp<RootStackParamList, 'Second'>;
// Tipo para receber o tipo de operação da tela anterior
type Route = RouteProp<RootStackParamList, 'Second'>;

// Componente principal do jogo
export default function Inicio() {
    // Permite navegar para outras telas
    const navigation = useNavigation<Nav>();
    // Recebe os dados da tela anterior
    const route = useRoute<Route>();
    // Extrai o tipo de operação (adicao, subtracao, multiplicacao)
    const operacao = route.params?.dados ?? 'erro';

    // ===== ESTADOS DO JOGO =====
    // Primeiro número aleatório
    const [a1, setA1] = useState(aleatorio());
    // Segundo número aleatório
    const [a2, setA2] = useState(aleatorio());
    // Número de vidas (máximo 5)
    const [vidas, setVidas] = useState(5);
    // Resposta digitada pelo utilizador
    const [respostaUser, setRespostaUser] = useState("");
    // Pontuação total do utilizador
    const [pontuacao, setPontuacao] = useState(0);
    // Número de operações restantes (rounds)
    const [numIteracoes, setNumIteracoes] = useState(3); 

    // Determina o símbolo da operação matemática
    const operador = useMemo(() => {
        const ops: Record<string, string> = {
            adicao: "+",
            subtracao: "-",
            multiplicacao: "*"
        };
        return ops[operacao] || "?";
    }, [operacao]);

    // Função para resetar os números e preparar próximo round
    const proximoRound = () => {
        setA1(aleatorio());
        setA2(aleatorio());
        setRespostaUser("");
    };

    // Função executada quando o utilizador clica em Verificar
    const aoVerificar = () => {
        // Converte a resposta em número inteiro
        const numResposta = parseInt(respostaUser, 10);

        // Valida se o utilizador digitou um número válido
        if (isNaN(numResposta)) {
            Alert.alert("Atenção", "Digite um número valido!");
            return;
        }

        // Variáveis para controlar o estado durante a verificação
        let vidasAtuais = vidas;
        let pontuacaoAtual = pontuacao;

        // Verifica se a resposta está correta
        if (verificarR(a1, a2, numResposta, operador)) {
            // Se correto, adiciona 3 pontos
            Alert.alert('Acertou!', 'Parabéns, ganhaste 3 pontos.');
            pontuacaoAtual += 3;
            setPontuacao(pontuacaoAtual);
            proximoRound(); // Prepara próxima questão
        } else {
            // Se errado, perde uma vida
            vidasAtuais -= 1;
            setVidas(vidasAtuais);
            Alert.alert("Errado", "Perdeste uma vida!");
            setRespostaUser("");
        }

        // Decrementa o número de iterações
        const proxIteracao = numIteracoes - 1;
        setNumIteracoes(proxIteracao);

        // Verifica se o jogo acabou (sem vidas ou sem iterações)
        if (vidasAtuais <= 0 || proxIteracao <= 0) {
            Alert.alert('Fim de Jogo', `Sua pontuação final: ${pontuacaoAtual}`, [
                { 
                    text: 'OK', 
                    // Navega para a tela final passando a pontuação
                    onPress: () => navigation.navigate('Final', { pontuacaoFinal: pontuacaoAtual }) 
                }
            ]);
        }
    };

    return (
        <ScrollView style={style.scroll} contentContainerStyle={style.scrollContent}>
            <Background url={require("../assets/segundo.jpeg")}>
                {/* Container com as vidas e pontuação */}
                <View style={style.containerVidas}>
                    {/* Mostra vidas com emojis (❤️ para vida, 🖤 para vidas perdidas) */}
                    <Text style={style.txtVidas}>
                        {"❤️".repeat(vidas)}{"🖤".repeat(5 - vidas)}
                    </Text>
                    {/* Mostra pontos e rounds restantes */}
                    <Text>Pontos: {pontuacao} | Restam: {numIteracoes}</Text>
                </View>

                {/* Título da tela */}
                <Text style={style.h1}>Resolva a operação</Text>

                {/* Componente que mostra a operação (exemplo: 5 + 3) */}
                <Box valor1={a1.toString()} valor2={operador} valor3={a2.toString()} />

                {/* Campo de entrada para o utilizador digitar a resposta */}
                <TextInput
                    placeholder={'Sua resposta aqui'}
                    style={style.input}
                    keyboardType="numeric"
                    onChangeText={setRespostaUser}
                    value={respostaUser}
                />

                {/* Botão para verificar a resposta */}
                <Button valor={'Verificar'} onpress={aoVerificar} />
            </Background>
        </ScrollView>
    );
}