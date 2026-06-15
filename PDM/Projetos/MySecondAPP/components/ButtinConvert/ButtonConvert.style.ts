import { StyleSheet } from "react-native";

const myButtonStyles = StyleSheet.create({
    button: {
        backgroundColor: "black",
        paddingHorizontal: 40,
        paddingVertical: 20,
        borderRadius: 30,
        width: 250,
    },
    buttonText: {
        alignSelf: "center",
        fontWeight: "bold",
        color: "white",
    }
});

export default myButtonStyles;