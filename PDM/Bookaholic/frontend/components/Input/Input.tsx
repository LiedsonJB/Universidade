import { TextInput, TextInputProps} from "react-native";
import styles from "./Style.Input";


export function Input({...rest}: TextInputProps){

    return (
        <TextInput style={styles.input} {...rest}/> //uso de ...rest
    )

}