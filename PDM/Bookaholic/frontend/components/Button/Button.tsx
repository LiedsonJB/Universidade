import { Alert, Platform, Text, ToastAndroid, TouchableOpacity, TouchableOpacityProps } from "react-native"
import styles from "./Style.Button"

type ButtonProps = TouchableOpacityProps & {
    label: string,
}

export function Button({ label, ...rest }: ButtonProps) {

    const submeter = () => {
        console.log("Clicou no botão");

        if (Platform.OS === 'android') {
            ToastAndroid.show("Função em desenvolvimento", ToastAndroid.SHORT);
        } else {
            Alert.alert("Aviso", "Função em desenvolvimento");
        }
    }
    return (

        <TouchableOpacity style={styles.container} activeOpacity={0.8} onPress={submeter} {...rest}>
            <Text style={styles.label}>{label}</Text>
        </TouchableOpacity>

    )
}
