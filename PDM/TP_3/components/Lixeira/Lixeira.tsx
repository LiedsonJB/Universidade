import { Image, TouchableOpacity } from 'react-native';
import style from './Lixeira.Style'

type PropsLixeira = {
    onpress: () => void
}

const ButtunLixeira = ({ onpress, }: PropsLixeira) => {

    return (

        <TouchableOpacity onPress={onpress} style={style.corpo}>
            <Image source={require('./../../assets/lixeira.png')} style={style.conteudo} />
        </TouchableOpacity>

    );

}

export default ButtunLixeira;