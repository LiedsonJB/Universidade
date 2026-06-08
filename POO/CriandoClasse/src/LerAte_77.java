import javax.swing.*;

public class LerAte_77 {
    public static void main(String[] args) {
        
        final int MAX = 100;//tamanho maximo 
        int aux; 

        int[] valores = new int[MAX];//meu vetor
        int x = 0;
        int i = 0;

        String buffer;

       while(i < MAX){
            buffer = JOptionPane.showInputDialog(null, "Ler valores(termina com -77): ");

            if(buffer == null){
                JOptionPane.showMessageDialog(null, "Nao voi intruduzido nenhum numero");
                continue;
            }
            aux = Integer.parseInt(buffer);
            if (aux != -77) {
                valores[i] = aux;
            } else {
                break;
            }
            i++;
            x++;
        }


        for (int j = 0; j < x; j++) {
            JOptionPane.showMessageDialog(null, "Seus valores\n" + valores[j]);
        }

    }
}
