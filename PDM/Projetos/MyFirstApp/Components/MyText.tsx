import { Text } from "react-native";
import styles from '../styles';

type MyTextProps = {
    title?: string;
}

const  MyText = ( {title = "Hello World"}: MyTextProps) => {
    return (
        <Text style={styles.texto}>{title}</Text>
    );
}

export default MyText;
