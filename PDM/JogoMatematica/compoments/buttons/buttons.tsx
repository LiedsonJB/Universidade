// Componente de botão reutilizável
// Recebe um texto (`valor`) e uma função (`onpress`) para executar quando clicado
import { TouchableOpacity, Text } from "react-native";
import { style } from "./buttons.style";

type PropsButtons = {
    // Texto exibido no botão
    valor: string,
    // Função chamada ao pressionar o botão
    onpress: () => void
}

function Button({valor, onpress}: PropsButtons){
    // Usa TouchableOpacity para efeito visual ao pressionar
    return (
        <TouchableOpacity style={style.container} activeOpacity={0.7}
            onPress={onpress}
        >
            {/* Texto centralizado do botão */}
            <Text style={style.conteudo}>{valor}</Text>
        </TouchableOpacity>
    )

}

export default Button;