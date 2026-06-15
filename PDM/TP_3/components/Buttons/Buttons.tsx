import { Text, TouchableOpacity } from "react-native";
import style from './Style.Buttons';

type PropsButton = {

    Valor: string;
    onPress: () => void;

}

const Buttons = ({Valor, onPress}: PropsButton) => {

    return (

        <TouchableOpacity style = {style.button} onPress={onPress}>
            <Text style = {style.valor}>{Valor}</Text>
        </TouchableOpacity>

    )
    
}

export default Buttons;