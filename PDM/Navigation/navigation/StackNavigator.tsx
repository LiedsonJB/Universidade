import React from 'react';
import { createNativeStackNavigator } from '@react-navigation/native-stack';
import { RootStackParamList } from './type';
import MainScreen from '../screens/MainScreen';
import SecondScreen from '../screens/SecondScreen';
import ThirdScreen from '../screens/ThirdScreen';
const Stack = createNativeStackNavigator<RootStackParamList>();
const StackNavigator = () => {
return (
<Stack.Navigator>
<Stack.Screen name="Main" component={MainScreen} />
<Stack.Screen name="Second" component={SecondScreen} />
<Stack.Screen name="Third" component={ThirdScreen} />
</Stack.Navigator>
);
};
export default StackNavigator;