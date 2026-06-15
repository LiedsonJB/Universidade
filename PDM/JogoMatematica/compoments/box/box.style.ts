// Estilos para o componente Box (mostra a operação)
import { StyleSheet } from "react-native";

const style = StyleSheet.create({

    // Caixa que contém os três elementos da operação
    box: {
        width: '70%',
        height: 90,
        backgroundColor: '#b49c9c',
        borderRadius: 10,
        alignContent: 'center',
        alignSelf: 'center',
        justifyContent: 'center',
        flexDirection: 'row',
        gap: 10
    },

    // Estilo do texto dentro da box
    h4: {
        fontSize: 20,
    },

})

export default style;