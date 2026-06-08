import javax.swing.*;

public class SQRT {

    public static void main(String[] args) {

        double resultado = Math.sqrt(Double.parseDouble(JOptionPane.showInputDialog(null, "Numero para raiz quadrada: ")));
        JOptionPane.showMessageDialog(null, "Resultado: " + String.format("%.2f", resultado));
    }
}
