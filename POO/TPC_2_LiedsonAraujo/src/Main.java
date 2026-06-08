import javax.swing.*;
import java.awt.*;
import javax.swing.border.EmptyBorder;

public class Main {

    public static void main(String[] args) {

        JFrame jF1 = new JFrame("TPC_LiedsonAraujo"); // atribuir nome a minha janela
        jF1.setSize(800, 500); // tamanho da minha janela
        jF1.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); // permite fechar corretamente a janela
        BorderLayout Mylayout = new BorderLayout(); // meu layout para ser utilizado na minha janela
        jF1.setLayout(Mylayout); // atribuir o meu layout a minha janela

        JPanel topo = new JPanel(); // cria painel para topo
        topo.setBackground(new Color(255, 0, 0)); // cor para a parte do topo da minha janela
        topo.setPreferredSize(new Dimension(800, 25)); // tamanho do topo da minha janela
        topo.add(new JLabel("Topo da janela")); // o titulo que ele tem
        jF1.add(topo, BorderLayout.NORTH); // a sua posicao na minha janela

        JPanel botoesPanel = new JPanel(); // parte para os meus botoes
        botoesPanel.setLayout(new BoxLayout(botoesPanel, BoxLayout.Y_AXIS)); // layout para organizar os botoes um abaixo do outro
        Dimension cmpB = new Dimension(120, 40); // tamanho fixo para todos os botoes

        // botao Enviar
        JButton btnEnviar = new JButton("Enviar"); // criar botao com o titulo Enviar
        btnEnviar.setMaximumSize(cmpB); // garantir o mesmo tamanho para todos os botoes
        btnEnviar.setAlignmentX(Component.CENTER_ALIGNMENT); // alinhar o botao ao centro
        botoesPanel.add(btnEnviar); // adicionar ao meu painel o botao
        botoesPanel.add(Box.createRigidArea(new Dimension(0, 10))); // adicionar 10px abaixo do botao

        // botao Guardar
        JButton btnGuardar = new JButton("Guardar"); // criar botao com o titulo Guardar
        btnGuardar.setMaximumSize(cmpB);
        btnGuardar.setAlignmentX(Component.CENTER_ALIGNMENT);
        botoesPanel.add(btnGuardar);
        botoesPanel.add(Box.createRigidArea(new Dimension(0, 10)));

        // botao Reset
        JButton btnReset = new JButton("Reset"); // criar botao com o titulo Reset
        btnReset.setMaximumSize(cmpB);
        btnReset.setAlignmentX(Component.CENTER_ALIGNMENT);
        botoesPanel.add(btnReset);
        botoesPanel.add(Box.createRigidArea(new Dimension(0, 10)));

        // botao Cancelar
        JButton btnCancelar = new JButton("Cancelar"); // criar botao com o titulo Cancelar
        btnCancelar.setMaximumSize(cmpB);
        btnCancelar.setAlignmentX(Component.CENTER_ALIGNMENT);
        botoesPanel.add(btnCancelar);

        JPanel parteDireita = new JPanel(new GridBagLayout()); // painel a direita com layout centralizado
        parteDireita.setBorder(new EmptyBorder(0, 0, 0, 20)); // margem a direita
        parteDireita.add(botoesPanel); // adicionar painel de botoes a direita
        jF1.add(parteDireita, BorderLayout.EAST); // adicionar a posicao direita da janela

        JLabel rodape = new JLabel("Data : 30 de Maio"); // criar o rodape
        rodape.setHorizontalAlignment(SwingConstants.LEFT); // alinhar a esquerda
        rodape.setBorder(new EmptyBorder(10, 10, 10, 10)); // margem ao redor do rodape
        jF1.add(rodape, BorderLayout.SOUTH); // adicionar o rodape na parte inferior

        jF1.setVisible(true); // tornar a janela visivel
    }
}
