// Funções utilitárias da aplicação
import { Alert, BackHandler } from "react-native"

// Encerra a aplicação
const fecharApp = () => {
    BackHandler.exitApp()
}

// Mostra mensagem de ajuda
const ajuda = () => {
    Alert.alert("Esta funcionalidade foi jogado no mar kkkkkkkkkkkk")
}

// Gera um número aleatório entre 1 e 10
const aleatorio = () => {
    const max = 10;
    const min = 1;
    return (Math.ceil(Math.random() * (max - min + 1)) + min);
}

// Verifica se a resposta do utilizador está correta
// a1: primeiro número
// a2: segundo número
// resU: resposta do utilizador
// operador: operação matemática (+, -, *)
// Retorna: true se correto, false se errado
const verificarR = (a1: number, a2: number, resU: number, operador: string) => {
    switch(operador) {
        // Caso adição
        case '+':
            return resU === (a1 + a2);

        // Caso subtração
        case '-':
            return resU === (a1 - a2);

        // Caso multiplicação
        case '*':
            return resU === (a1 * a2);
        
        // Se operador inválido, retorna false
        default:
            return false;
    }
}

// Exporta todas as funções para uso em outros ficheiros
export { fecharApp, ajuda, aleatorio, verificarR };
