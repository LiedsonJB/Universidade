import javax.swing.*;
import javax.swing.border.LineBorder;
import java.awt.*;

public class GUI extends JFrame {
    public GUI(int rows, int cols){
        setSize(500, 500);
        setLayout(new GridLayout(rows, cols));
        setBackground(new Color(0x0F3978));

        for(int i=0; i < rows; i++){
            for(int j=0; j< cols; j++){
                JPanel celula = new JPanel();
                celula.setBorder(new LineBorder(new Color(0x00000000)));
                /*if ((i + j) % 2 == 0) {
                    celula.setBackground(Color.WHITE);
                } else {
                    celula.setBackground(Color.BLACK); // ou Color.RED para damas
                }
*/

                add(celula);
            }

        }
        setVisible(true);
    }
}
