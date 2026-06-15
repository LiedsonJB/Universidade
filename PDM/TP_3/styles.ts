import { StyleSheet } from 'react-native';

const styles = StyleSheet.create({
    app: {
        flex: 1,
        backgroundColor: '#f9f9f9',
    },

    header: {
        flex: 1,
        
    },

    body: {
        flex: 5,
    },

    footer: {
        backgroundColor: 'white',
        height: 70,
    },

    cardItem: {
        marginBottom: 15,
    },

    modalContainer: {
        flex: 1,
        justifyContent: 'center',
        alignItems: 'center',
        backgroundColor: 'rgba(0,0,0,0.5)',  // fundo escurecido
    },

    modalContent: {
        backgroundColor: '#fff',
        padding: 20,
        borderRadius: 10,
        width: '80%',
    },

    buttonsModal: {
         flexDirection: 'row', 
         justifyContent: 'space-between', 
         marginTop: 20,
    },

    teste: {
        flex: 1,
    },

    pesquisar: {
        backgroundColor: '#f9f9f9',
        marginTop: 10,
        paddingLeft: 10,
        borderRadius: 5,
    }

});



export default styles;