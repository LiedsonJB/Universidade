import styles from "./Style.Input"
import { TextInput, View } from "react-native"

type PropsInput = {
    placeholder: string;
    editavel: boolean;
    valor: string;
    tamanho: number;
    corPlaceholder: string
}


export function Input({ placeholder, editavel, valor, tamanho, corPlaceholder }: PropsInput) {
    return (
        <View style={styles.view}>
            <TextInput
                style={styles.input}
                placeholder={placeholder}
                editable={editavel}
                placeholderTextColor={corPlaceholder}
                value={valor}
                maxLength={tamanho}
            />

        </View>
    )
}