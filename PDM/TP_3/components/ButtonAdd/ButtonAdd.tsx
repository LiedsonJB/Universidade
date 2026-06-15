import Style from './ButtonAdd.style'
import { TouchableOpacity, Text } from 'react-native'

type Button = {
    onPress: () => void
}

function ButtonAdd({onPress}: Button){

    return (

        <TouchableOpacity style = {Style.button} onPress={onPress}>
            <Text style = {Style.buttonAdd}>+</Text>
        </TouchableOpacity>

    )


}


export default ButtonAdd;