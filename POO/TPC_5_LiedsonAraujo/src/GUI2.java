import javax.swing.*;
import java.awt.*;

public class GUI2 extends JFrame {
    private int rows = 0;
    private int cols = 0;

    public GUI2(){
        super("Ler Linha e coluna");
        setSize(400,200);
        setLayout(new GridLayout(3,1, 10, 10));

        JPanel paraLinhas = new JPanel(new BorderLayout(10, 10));
        JPanel paraColunas = new JPanel(new BorderLayout(10,10));

        JLabel linhas = new JLabel("Numero de Linhas:");
        JTextField campoLinhas = new JTextField();
        campoLinhas.setMinimumSize(new Dimension(200, 10));
        paraLinhas.add(linhas, BorderLayout.WEST);
        paraLinhas.add(campoLinhas, BorderLayout.CENTER);

        JLabel colunas = new JLabel("Numero de Colunas:");
        JTextField campoColunas = new JTextField();
        paraColunas.add(colunas, BorderLayout.WEST);
        paraColunas.add(campoColunas, BorderLayout.CENTER);

        JButton btn = new JButton("Confirmar Valores");
       btn.addActionListener(e -> confirmar(campoLinhas.getText(), campoColunas.getText()));

        add(paraLinhas);
        add(paraColunas);
        add(btn);

        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        setVisible(true);

    }

    private void confirmar(String pLinhas, String pColunas) {
        if(pLinhas != null && pColunas != null) {
            this.rows = Integer.parseInt(pLinhas.trim());
            this.cols = Integer.parseInt(pColunas.trim());

            if(this.cols > 0 && this.rows > 0){
               setVisible(false);
                new GUI(this.rows, this.cols);
            }
        }
    }
}
