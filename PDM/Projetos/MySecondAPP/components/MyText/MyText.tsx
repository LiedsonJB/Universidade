import { Text, TextInput, View } from "react-native";
import myTextStyles from "./MyText.style";

type MyTextProps = {
    temperature?: number;
    onChange?: (text: number) => void;
    units?: string;

}

const MyText = ({temperature, units}: MyTextProps) => {
    return(
        <Text style = {myTextStyles.text}>
            {temperature?.toFixed(2)} {units}
        </Text>

    );
}
export default MyText;