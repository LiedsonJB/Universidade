import MyText from './Components/MyText';
import styles from './styles';
import {View, TextInput, Button } from 'react-native';


function App() {

  return (
    <View style={styles.container}>
        <MyText title = 'Calculadora de IMC' />
        <TextInput />
        <Button title = "Calcular"/>
         <MyText title = 'Resultado' />
      </View>
    );
}

export default App;
