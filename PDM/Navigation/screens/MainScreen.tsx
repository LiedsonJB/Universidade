import React, { useState } from 'react';
import { View, TextInput, Button } from 'react-native';
import { useNavigation } from '@react-navigation/native';
import { NativeStackNavigationProp } from '@react-navigation/native-stack';
import { RootStackParamList } from '../navigation/type';

type Nav = NativeStackNavigationProp<RootStackParamList, 'Main'>;

const MainScreen = () => {
    const [text, setText] = useState('');
    const navigation = useNavigation<Nav>();
    return (
        <View style={{ flex: 1, justifyContent: 'center', gap: 10, padding: 20 }}>
            <TextInput
                placeholder="Digite uma mensagem"
                value={text}
                onChangeText={setText}
                style={{ borderWidth: 1, margin: 10 }}
            />
            <Button
                title="Enviar para Second"
                onPress={() => navigation.navigate('Second', { mensagem: text })}
            />
            <Button
                title="Ir para Third"
                onPress={() => navigation.navigate('Third')}
            />
        </View>
    );


}

export default MainScreen;