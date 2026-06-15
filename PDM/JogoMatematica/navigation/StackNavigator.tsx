// Configuração das rotas de navegação da aplicação
import React from 'react';
import { createNativeStackNavigator } from '@react-navigation/native-stack';
import { RootStackParamList } from './type';
import Main from '../pages/Pagina_inicial'
import Second from '../pages/Second'
import Final from "../pages/final"

// Cria um navegador de pilha com os tipos de rotas definidas
const Stack = createNativeStackNavigator<RootStackParamList>();

// Componente que define todas as telas da aplicação
const StackNavigator = () => {

    return (
        <Stack.Navigator>
            {/* Main: tela inicial com opções de jogo */}
            <Stack.Screen name="Main" component={Main} />
            {/* Second: tela onde o jogo acontece */}
            <Stack.Screen name="Second" component={Second} />
            {/* Final: tela mostra pontuação e permite voltar ao início */}
            <Stack.Screen name="Final" component={Final} />
        </Stack.Navigator>
    );

};
export default StackNavigator;