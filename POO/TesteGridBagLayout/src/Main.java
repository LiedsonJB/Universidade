import javax.swing.*;
import java.awt.*;

public class Main {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Tabela 3x3 com GridBagLayout");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(300, 300);

        JPanel panel = new JPanel(new GridBagLayout());
        GridBagConstraints pos = new GridBagConstraints();


        /*for (int y = 0; y < 3; y++) {           // linhas
            for (int x = 0; x < 3; x++) {       // colunas
                gbc.gridx = x;                 // posição horizontal
                gbc.gridy = y;                 // posição vertical
                panel.add(new JButton("(" + x + "," + y + ")"), gbc);
            }*/
        //}
        pos.gridx = 0;
        pos.gridy = 0;
        pos.gridwidth = 2;
        pos.gridheight = 0;

        panel.add(new Label("Teste"), pos);
        panel.add(new Label("Outro"));
        frame.add(panel);
        frame.setVisible(true);
    }
}
