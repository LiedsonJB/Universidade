import javax.swing.*;
import javax.swing.border.LineBorder;
import java.awt.*;

public class GUI extends JFrame {
    private boolean iniciar;
    private int indice;
    private final JPanel centro;

    public GUI(int rows, int cols){
        super("Grelha n*m");
        iniciar = true;
        indice = 0;

        setLayout(new BorderLayout(20,10));
        setSize(500, 400);

        JPanel topo = new JPanel();
        centro = new JPanel(new GridLayout(rows, cols));
        JPanel baixo = new JPanel();

        JLabel l1 = new JLabel("Grelha da Marinha", SwingConstants.CENTER);
        topo.add(l1);

        // ----------- para os btns
        JPanel paraBtn = new JPanel(new GridLayout(3, 1, 10, 10));
        JButton iniciarOUparar = new JButton("Iniciar");
        JButton reset = new JButton("Reset");
        JButton passoApasso = new JButton("Passo a Passo");

        iniciarOUparar.addActionListener(e -> iniciarParar(iniciarOUparar));
        reset.addActionListener(e -> {
            dispose();
            Main.main(new String[0]);
        });
        passoApasso.addActionListener(e -> executar(rows));

        //add ao parabtn
        paraBtn.add(iniciarOUparar);
        paraBtn.add(reset);
        paraBtn.add(passoApasso);

        // -------------- criar celulas
        for(int x = 0; x < rows; x++){
            for(int y = 0; y < cols; y++){
                JPanel celula = new JPanel();
                celula.setSize(10, 10);
                celula.setMaximumSize(new Dimension(10, 10));
                celula.setMinimumSize(new Dimension(10, 10));
                celula.setBackground(new Color(0x0C92BA));

                if((x + y) % 2 == 0){
                    celula.setBackground(new Color(0xFFFFFF));
                }

                celula.setBorder(new LineBorder(new Color(0x000000)));

                centro.add(celula);
            }
        }

        JLabel l2 = new JLabel("Todos os direitos reservados © Liedson Gomes Araujo", SwingConstants.LEFT);
        baixo.add(l2);
        add(topo, BorderLayout.NORTH);
        add(centro, BorderLayout.CENTER);
        add(paraBtn, BorderLayout.EAST);
        add(baixo, BorderLayout.SOUTH);

        setLocationRelativeTo(null);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setVisible(true);
    }

    private void executar(int rows) {
        System.out.println(indice);
        if (!iniciar) {
            if (indice >= centro.getComponentCount()) {
                JOptionPane.showMessageDialog(null, "Fim da execução");
                return;
            }
            Component aux = centro.getComponent(indice);

            if (!aux.getBackground().equals(new Color(0x0C92BA))) {
                aux.setBackground(new Color(0x000000));
            }

            indice++; // AVANÇA UMA VEZ, SEM DUPLICAÇÃO
        } else {
            JOptionPane.showMessageDialog(null, "Por favor inicia o jogo antes");
        }
    }


    private void iniciarParar(JButton btn) {

        if(iniciar){
            iniciar = false;
            btn.setText("Pausar");
        } else{
            iniciar = true;
            btn.setText("iniciar");
        }
    }
}
