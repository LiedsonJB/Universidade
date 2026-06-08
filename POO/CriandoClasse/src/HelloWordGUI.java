import javax.swing.*;

public class HelloWordGUI {

        public static void main(String[] args){
            int numero = 13;
            double media = 871.0 / 13.2;

            JOptionPane.showMessageDialog(null,"Hello World!" + String.format("%.2f", media));
        }

}
