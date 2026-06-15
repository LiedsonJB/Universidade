// Componente que exibe uma operação matemática (ex: 5 + 3)
import {Text, View } from "react-native";
import style  from "./box.style";

type PropsBox = {
    // Primeiro valor da operação
    valor1: string,
    // Operador ("+", "-", "*")
    valor2: string,
    // Segundo valor da operação
    valor3: string,
}

function Box({valor1, valor2, valor3}: PropsBox){
    // Renderiza os três elementos em linha para formar a operação
    return (
        <View style={style.box}>
            <Text style={style.h4}>{valor1}</Text>
            <Text style={style.h4}>{valor2}</Text>
            <Text style={style.h4}>{valor3}</Text>
        </View>
    )

}

export default Box;