import { StyleSheet } from "react-native"

const styles = StyleSheet.create({
    container: {
        flex: 1,
        backgroundColor: "#fdfdfd",
        padding: 31,
        //gap: 10,
    },

    ilustracao: {
        width: "100%",
        height: 400,
        resizeMode: "contain",
        marginTop: 62,
        borderRadius: 30,
    },

    title: {
        fontSize: 32,
        fontWeight: 900,
    },

    subtitle: {
        fontSize: 16,
    },

    from: {
        marginTop: 24,
        gap: 12,
    },

    footerText: {
        textAlign: "center",
        color: "#585860",
    },

    footerLink: {
        color: "#032ad7",
        fontWeight: 700,
    },

})

export default styles;
