// Estilos para o componente Background
import { StyleSheet } from "react-native";

const style = StyleSheet.create({

    // Container que faz a imagem de fundo ocupar a tela toda
    container: {
        flex: 1,
        width: '100%',
        height: '100%',
        justifyContent: 'center',
        alignContent: 'center',
    },

    // Overlay usado para aplicar padding e posicionar o conteúdo
    overlay: {
        //flex: 1,
        padding: 20,
    },

});


export default style;