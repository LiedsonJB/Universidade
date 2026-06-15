import React from "react";
import { View, Text, ScrollView } from "react-native";
import Background from "../compoments/Background/background";
import Button from "../compoments/buttons/buttons";
import style from "../style";
import { fecharApp, ajuda } from "../utils/funcoes";

// Importações de navegação
import { useNavigation } from '@react-navigation/native';
import { NativeStackNavigationProp } from '@react-navigation/native-stack';
import { RootStackParamList } from '../navigation/type';

type Nav = NativeStackNavigationProp<RootStackParamList, 'Main'>;

export default function Inicio() {
    const navigation = useNavigation<Nav>();
    
    return (
        <ScrollView style={style.scroll} contentContainerStyle={style.scrollContent}>
            <Background url={require("../assets/primeiro.jpeg")}>
                
                {/* Cabeçalho de Boas-vindas */}
                <View style={style.headerArea}>
                    <Text style={style.h1}>Bem-vindo ao Jogo de Matemática</Text>
                    <Text style={style.h2}>Aprende aqui a fazer contas se divertindo!</Text>
                </View>

                {/* Container Principal que centraliza os grupos de botões */}
                <View style={style.main}> 
                    
                    {/* Grupo de Operações Matemáticas */}
                    <View style={style.div}>
                        <Button 
                            valor={"Adição"} 
                            onpress={() => navigation.navigate('Second', { dados: 'adicao' })}
                        />
                        <Button 
                            valor={"Subtração"} 
                            onpress={() => navigation.navigate('Second', { dados: 'subtracao' })}
                        />
                        <Button 
                            valor={"Multiplicação"} 
                            onpress={() => navigation.navigate('Second', { dados: 'multiplicacao' })}
                        />
                    </View>

                    {/* Espaçador visual entre os blocos */}
                    <View style={style.sectionSpacer} />

                    {/* Grupo de Utilidades */}
                    <View style={style.div}>
                        <Button valor={"Ajuda"} onpress={() => ajuda()} />
                        <Button valor={"Sair"} onpress={() => fecharApp()} />
                    </View>

                </View>

            </Background>
        </ScrollView>
    );
}