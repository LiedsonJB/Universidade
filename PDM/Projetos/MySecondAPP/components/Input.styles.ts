import { StyleSheet } from "react-native";

const inputStyles = StyleSheet.create({
    input: {
        backgroundColor: "white",
        height: 50,
        borderRadius: 20,
        paddingLeft: 25,
        fontSize: 20,
    },
    root: {
        alignSelf: "stretch",
        justifyContent: "center",
    },
    unit: {
        position: "absolute",
        alignSelf: "flex-end",
        paddingRight: 25,
        fontSize: 30,
    },
});


export default inputStyles;