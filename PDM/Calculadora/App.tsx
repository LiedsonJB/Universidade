import { SafeAreaView } from "react-native-safe-area-context";
import styles from "./styles";
import { View, } from "react-native";
import { Button } from "./components/Button";
import { AC, del, getValores, getResultado, calcularResultado } from "./utils/funcoes";
import { useEffect, useState } from "react";
import { Input } from "./components/Input";

function App() {

  const [valor, setValor] = useState("");
  const [resultado, setResultado] = useState('')

  useEffect(() => {
    calcularResultado(valor, setResultado);
  }, [valor]);

  return (

    <SafeAreaView style={styles.root}>
      <View style={styles.container}>

        <Input placeholder={"0"} editavel={false} tamanho={10} valor={valor} corPlaceholder={"#fff"} />

        <View style={styles.rows}>
          <Button valor={"AC"} onPress={() => { AC(setValor) }} />
          <Button valor={"del"} onPress={() => { del(valor, setValor) }} />
          <Button valor={"%"} onPress={() => { getValores("%", valor, setValor); }} />
          <Button valor={"/"} onPress={() => { getValores("/", valor, setValor); }} />
        </View>

        <View style={styles.rows}>
          <Button valor={"7"} onPress={() => { getValores("7", valor, setValor); }} />
          <Button valor={"8"} onPress={() => { getValores("8", valor, setValor,); }} />
          <Button valor={"9"} onPress={() => { getValores("9", valor, setValor,); }} />
          <Button valor={"x"} onPress={() => { getValores("*", valor, setValor,); }} />
        </View>

        <View style={styles.rows}>
          <Button valor={"4"} onPress={() => { getValores("4", valor, setValor,); }} />
          <Button valor={"5"} onPress={() => { getValores("5", valor, setValor,); }} />
          <Button valor={"6"} onPress={() => { getValores("6", valor, setValor,) }} />
          <Button valor={"-"} onPress={() => { getValores("-", valor, setValor,) }} />
        </View>

        <View style={styles.rows}>
          <Button valor={"1"} onPress={() => { getValores("1", valor, setValor,) }} />
          <Button valor={"2"} onPress={() => { getValores("2", valor, setValor,) }} />
          <Button valor={"3"} onPress={() => { getValores("3", valor, setValor,) }} />
          <Button valor={"+"} onPress={() => { getValores("+", valor, setValor,) }} />
        </View>

        <View style={styles.rows}>
          <Button valor={"0"} onPress={() => { getValores("0", valor, setValor,) }} />
          <Button valor={"00"} onPress={() => { getValores("00", valor, setValor,) }} />
          <Button valor={","} onPress={() => { getValores(".", valor, setValor,) }} />
          <Button valor={"="} onPress={() => { getResultado(valor, setValor, resultado) }} />
        </View>

      </View>
    </SafeAreaView>

  );

}


export default App;
