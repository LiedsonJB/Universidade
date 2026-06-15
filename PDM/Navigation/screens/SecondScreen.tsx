import React from 'react';
import { View, Text } from 'react-native';
import { useRoute } from '@react-navigation/native';
import { RouteProp } from '@react-navigation/native';
import { RootStackParamList } from '../navigation/type';

type Route = RouteProp<RootStackParamList, 'Second'>;

const SecondScreen = () => {
    const route = useRoute<Route>();
    const mensagem = route.params?.mensagem ?? 'Sem mensagem';
    return (
        <View style={{ flex: 1, justifyContent: 'center', gap: 10, padding: 20 }}>
            <Text style={{ fontSize: 20 }}>Mensagem recebida:</Text>
            <Text style={{ fontSize: 20 }}>{mensagem}</Text>
        </View>
    );
};
export default SecondScreen;