import React, { useMemo } from "react";
import { Text, View } from "react-native";
import { useNavigation, useRoute, RouteProp } from '@react-navigation/native';
import { NativeStackNavigationProp } from '@react-navigation/native-stack';
import { RootStackParamList } from '../navigation/type';
import Background from "../compoments/Background/background";
import Button from "../compoments/buttons/buttons";
import style from "../style"; // Importando seu style.ts atualizado
import { fecharApp } from "../utils/funcoes";

type Nav = NativeStackNavigationProp<RootStackParamList, 'Main'>;
type Route = RouteProp<RootStackParamList, 'Final'>;

export default function Final() {
    const navigation = useNavigation<Nav>();
    const route = useRoute<Route>();
    const resultado = route.params?.pontuacaoFinal ?? 0;
    
    const ranking = useMemo(() => {
        if (resultado >= 18) return { estrelas: "⭐⭐⭐", mensagem: "Incrível! Você é um mestre!" };
        if (resultado >= 12) return { estrelas: "⭐⭐", mensagem: "Muito bom! Quase perfeito!" };
        if (resultado >= 6)  return { estrelas: "⭐", mensagem: "Bom trabalho! Continue praticando." };
        return { estrelas: "✨", mensagem: "Quase lá! Tente mais uma vez!" };
    }, [resultado]);

    return (
        <View style={style.containerFinal}> {/* Container mestre para garantir que nada suma */}
            <Background url={require("../assets/Final.png")}>
                <View>
                    
                    <Text style={style.h1}>Fim de Jogo!</Text>

                    <Text style={style.txtEstrelas}>
                        {ranking.estrelas}
                    </Text>

                    <Text style={[style.h2, style.finalMessage]}> 
                        {ranking.mensagem}
                    </Text>

                    <Text style={[style.h2, style.finalScore]}> 
                        Sua Pontuação: {resultado}
                    </Text>
                    
                    <View style={style.areaBotoes}>
                        <Button 
                            valor={"Jogar Novamente"} 
                            onpress={() => navigation.navigate('Main')} // Teste com navigate se o pop falhar
                        />
                        <Button 
                            valor={'Sair'} 
                            onpress={() => fecharApp()} 
                        />
                    </View>
                </View>
            </Background>
        </View>
    );
}