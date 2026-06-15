import { Text, TouchableOpacity } from "react-native";
import myButtonStyles from "./ButtonConvert.style";

type MyButtonProps = {
    units?: string;
    onPress: () => void;
}

const ButtonConvert = ({ units, onPress }: MyButtonProps) => {
    return (
        <TouchableOpacity
            style={myButtonStyles.button}
            onPress={onPress}
        >
            <Text style={myButtonStyles.buttonText}>
                Converta para {units}
            </Text>
        </TouchableOpacity>
    );
}

export default ButtonConvert;