import { StyleSheet } from 'react-native';

const styles = StyleSheet.create({

    card: {
        backgroundColor: 'white',
        height: 115,

        //Adicionado sombra ao nosso CardTodo:
        shadowColor: '#000',
        shadowOffset: {
            width: 0,
            height: 5,
        },

        shadowOpacity: 0.36,
        shadowRadius: 6.68,
        elevation: 11,

        borderRadius: 13,
        alignItems: 'center',
        flexDirection: 'row',
        justifyContent: 'space-between',
        paddingHorizontal: 20,
    },

    title: {
        fontSize: 20,
        flex: 1,
    },
    img: {
        height: 25,
        width: 25,
    },

});


export default styles;