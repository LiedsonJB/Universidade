import { TouchableOpacity, Text } from "react-native";
import styles from "./Style.Button";

type ButtonProps = {
    valor: string
    onPress: () => void
}

export function Button({ valor, onPress }: ButtonProps) {

    return (

        <TouchableOpacity style={styles.button} activeOpacity={0.8} onPress={onPress}>
            <Text style={styles.label}>{valor}</Text>
        </TouchableOpacity>
    )

}