// Define os tipos de todas as rotas da aplicação
// Serve para ter segurança de tipos ao navegar entre telas

export type RootStackParamList = {
    // Main: tela inicial, não precisa de parâmetros
    Main: undefined;
    
    // Second: tela do jogo, recebe o tipo de operação (adicao, subtracao, multiplicacao)
    Second: { dados: string };
    
    // Final: tela de resultados, recebe a pontuação final
    Final: { pontuacaoFinal: number };
};