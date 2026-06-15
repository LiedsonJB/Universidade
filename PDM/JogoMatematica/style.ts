import { StyleSheet, Dimensions } from "react-native";

const { width } = Dimensions.get("window");

const style = StyleSheet.create({ 
    // Estrutura de Scroll
    scroll: {
        flex: 1,
        backgroundColor: '#fff', 
    },
    scrollContent: {
        flexGrow: 1, // Garante que o conteúdo estique para preencher a tela
    },

    // Tipografia
    h1: {
        fontSize: 32, // Reduzi levemente para não quebrar em telas pequenas
        fontWeight: 'bold',
        textAlign: 'center',
        color: '#000',
        marginVertical: 10,
        paddingHorizontal: 20,
    },
    h2: {
        fontSize: 20,
        textAlign: 'center',
        color: '#444',
        fontWeight: '600',
        marginBottom: 20,
    },

    // Containers de Layout
    main: {
        flex: 1,
        width: '100%',
        alignItems: 'center',
        justifyContent: 'center',
        paddingBottom: 40, // Espaço extra no final
    },
    // Área de cabeçalho usada na tela inicial
    headerArea: {
        marginTop: 60,
        paddingHorizontal: 20,
        width: '100%',
    },
    div: {
        width: '100%',
        alignItems: 'center',
        justifyContent: "center",
        gap: 12, // Espaçamento entre botões do mesmo grupo
        marginVertical: 10,
    },
    sectionSpacer: {
        height: 40,
    },

    // Tela de Jogo
    containerVidas: {
        width: '100%',
        marginTop: 40,
        alignItems: 'center',
        justifyContent: 'center',
    },
    txtVidas: {
        fontSize: 26,
        letterSpacing: 8,
        textShadowColor: 'rgba(0, 0, 0, 0.2)',
        textShadowOffset: { width: 1, height: 1 },
        textShadowRadius: 2,
    },

    // Interação
    input: {
        width: width * 0.85, // 85% da largura da tela
        height: 60,
        backgroundColor: '#ba5656',
        borderRadius: 12,
        fontSize: 24,
        fontWeight: 'bold',
        textAlign: 'center', // Texto centralizado no input fica melhor para números
        color: '#fff',
        marginVertical: 20,
        elevation: 4, // Sombra no Android
        shadowColor: '#000', // Sombra no iOS
        shadowOffset: { width: 0, height: 2 },
        shadowOpacity: 0.3,
        shadowRadius: 4,
    },

    // Tela Final
    containerFinal: {
        flex: 1,
        justifyContent: 'center', 
        alignItems: 'center',     
        padding: 30,
    },
    finalMessage: {
        color: '#000',
        marginVertical: 10,
    },
    finalScore: {
        color: '#000',
    },
    txtEstrelas: {
        fontSize: 70,             
        textAlign: 'center',
        marginVertical: 15,
        // Efeito de brilho nas estrelas
        shadowColor: '#FFD700',
        shadowOffset: { width: 0, height: 0 },
        shadowOpacity: 0.8,
        shadowRadius: 10,
    },
    areaBotoes: {
        width: '100%',
        gap: 15,
        marginTop: 30,
    }
});

export default style;