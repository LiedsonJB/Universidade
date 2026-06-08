import javax.swing.*;

public class Outher {
    int numeros[];

    public Outher(int n[]){
        this.numeros = n;
    }

    public void determinarValores(){
        Inner inObj = new Inner();

        System.out.println("Valor minino: " + inObj.minValor());
        System.out.println("Valor max: " + inObj.maxValor());
        System.out.println("media: " +inObj.media());
    }

    class Inner{
        int minValor(){
            int min = numeros[0];
            for (int i=1; i < numeros.length; i++)
                if(min > numeros[i])
                   min = numeros[i];

            return min;
        }

        int maxValor(){
            int max = numeros[0];
            for (int i=1; i < numeros.length; i++)
                if(max < numeros[i])
                    max = numeros[i];

            return max;
        }
        double media(){
            int soma = 0;

            for(int i : numeros){
                soma += i;
            }

            return (double) (soma/numeros.length);
        }
    }
}
