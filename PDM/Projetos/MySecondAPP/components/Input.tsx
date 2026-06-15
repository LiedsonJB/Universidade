import { Text, TextInput, View, KeyboardTypeOptions, Alert, } from "react-native";
import inputStyles from "./Input.styles";

type MyInputProps = {
    defaultValue?: number;
    onChange?: (text: number) => void;
    units?: string;
    keyboardType: KeyboardTypeOptions;
    valor: string;
    //editavel: boolean
}

const Input = ({ defaultValue, onChange, keyboardType, units, valor, /*editavel*/}: MyInputProps) => {

    return (
        <View style={inputStyles.root}>

            <TextInput placeholder="Introduza uma temperatura: " style={inputStyles.input} maxLength={4}
                defaultValue={defaultValue?.toString()}
                onChangeText={(text) => {

                    if(isNaN(Number(text))){
                        Alert.alert("Valor invalido digite um numero nao uma letra");
                        text.slice(0, -1);
                        
                        return;

                    }
                        onChange?.(Number(text));
                        
                }}

                value={valor}
                keyboardType={keyboardType}
                //editable = {editavel}

            />

            <Text style={inputStyles.unit}>{units}</Text>
        </View>
    );

}

export default Input;