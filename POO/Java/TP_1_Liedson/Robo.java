package TP_1_Liedson;
import robocode.*;
import java.awt.Color;

/*
    Esse robo foi baseado no robo fire encontrado com exemplo nos APIs do robocode
    onde ele fica escaneado o terreno para obter a posicao dos inimigos, agora de forma mais inteligente onde 
    nao atira atoua de modo nao perder vida sem necessidade em que atira so apartir do inimigo encontrar dentro de uma distancia 
    difinida no codigo
    ele tambem implementa uma logica bem util de modo em que verifica as parades de modo nao bater nelas
    tambem caso ele seja atingido ele movimenta de modo evitar as paredes tambem
    A potencia do tiro e baseado de acordo com a vida/ energia do robo de modo que quando ele nao tiver
    muita vida ele nao desparar que a potencia maxima e perder energia

    API utilizada com base: https://wiki.sj.ifsc.edu.br/images/7/73/ITL60801-Robocode-Manual2.pdf
*/

public class Robo extends AdvancedRobot {

    public void run() {
        // Ajustar as cores do robo
        setBodyColor(Color.orange); //cor do corpo
        setGunColor(Color.orange); //cor do canhao
        setRadarColor(Color.black); //cor do radar
        setScanColor(Color.red); //cor do feixe de escaneamento
        setBulletColor(Color.white); //cor das balas

    
        while (true) {
            verificarBordas(); // Ajustar para evitar colisao com parede
            setAhead(100); // Mover para frente
            setTurnGunRight(360); // Ajustar rotacao do canhao
            setBack(60); // Mover para tras
            execute(); // Executar todas as acoes pendentes
        }
    }

    public void onScannedRobot(ScannedRobotEvent e) {
        // Obter informacoes do inimigo e ajustar mira
        double anguloInimigo = getHeading() + e.getBearing(); // Obter angulo do inimigo
        double ajusteCanhao = anguloInimigo - getGunHeading(); // Ajustar canhao
        double vida = getEnergy(); // Obter nivel de energia do robo
        double distancia = e.getDistance(); // Obter distancia do inimigo

        double limiteDistancia = 250; // Ajustar limite de distancia para disparo
        setTurnGunRight(normalizarAngulo(ajusteCanhao)); // Ajustar direcao do canhao

        // Ajustar potencia do disparo com base na distancia e energia
        if (distancia < limiteDistancia) {
            if (vida < 20) {
                setFire(1); // Ajustar disparo fraco para economizar energia
            } else if (distancia < 20) {
                setFire(2); // Ajustar disparo medio para proximidade
            } else {
                setFire(3); // Ajustar disparo forte para maior distancia
            }
        }

        setTurnGunRight(360); // Ajustar para manter mira ativa
        scan(); // Obter novos inimigos
        setAhead(100); // Mover para frente
        execute(); // Executar todas as acoes pendentes
    }

    public void onHitByBullet(HitByBulletEvent e) {
        // Ajustar estrategia para evitar tiros inimigos
        double margemSegura = 40; // Ajustar distancia minima segura
        double larguraArena = getBattleFieldWidth(); // Obter largura da arena
        double alturaArena = getBattleFieldHeight(); // Obter altura da arena

        double x = getX(); // Obter posicao X do robo
        double y = getY(); // Obter posicao Y do robo

        double distanciaEsquerda = x; // Obter distancia ate borda esquerda
        double distanciaDireita = larguraArena - x; // Obter distancia ate borda direita
        double distanciaSuperior = alturaArena - y; // Obter distancia ate borda superior
        double distanciaInferior = y; // Obter distancia ate borda inferior

        // Ajustar angulo para esquiva
        double anguloEvasivo = Math.random() * 90 - 45;
        setTurnRight(anguloEvasivo); // Ajustar rotacao para evitar tiro

        // Ajustar movimento com base na distancia das bordas
        if (distanciaEsquerda > margemSegura && distanciaDireita > margemSegura &&
            distanciaSuperior > margemSegura && distanciaInferior > margemSegura) {
            setAhead(100 + Math.random() * 50); // Mover para frente com seguranca
        } else {
            setBack(80 + Math.random() * 40); // Mover para tras se estiver perto da borda
            setTurnRight(90); // Ajustar rotacao para sair da area de perigo
        }

        execute(); // Executar acao de esquiva
    }

    public void onHitWall(HitWallEvent e) {
        verificarBordas(); // Ajustar direcao ao bater na parede
    }

    public void verificarBordas() {
        // Ajustar estrategia para evitar colisao com bordas
        double margemSegura = 40; // Ajustar distancia segura minima
        double larguraArena = getBattleFieldWidth(); // Obter largura da arena
        double alturaArena = getBattleFieldHeight(); // Obter altura da arena

        double x = getX(); // Obter posicao X
        double y = getY(); // Obter posicao Y

        double distanciaEsquerda = x; // Obter distancia ate borda esquerda
        double distanciaDireita = larguraArena - x; // Obter distancia ate borda direita
        double distanciaSuperior = alturaArena - y; // Obter distancia ate borda superior
        double distanciaInferior = y; // Obter distancia ate borda inferior

        // Ajustar direcao se estiver perto da borda
        if (distanciaEsquerda < margemSegura || distanciaDireita < margemSegura ||  
            distanciaSuperior < margemSegura || distanciaInferior < margemSegura) {
            
            double novoAngulo = Math.random() * 180 - 90;
            setTurnRight(novoAngulo); // Ajustar rotacao para se afastar da borda

            setAhead(150); // Mover para se reposicionar
            setTurnRight(45); // Ajustar trajetoria
            execute(); // Executar acao
        }
    }

    public double normalizarAngulo(double angulo) {
        // Ajustar angulos para ficarem entre -180 e 180 graus
        while (angulo > 180) angulo -= 360;
        while (angulo < -180) angulo += 360;
        return angulo;
    }
}