import java.util.Scanner;

public class Exerc10 {
    public static void main(String[] args) {
        Scanner scr = new Scanner(System.in);
        int n = 3;
        String carater;

        do {
            System.out.print("Digite um numero impar (n>2): ");
            n = scr.nextInt();

            String buffer = scr.nextLine();

            System.out.print("Qual carater deseja que seja imprimido: ");
            carater = scr.nextLine();

            if (n <= 2 || n % 2 == 0)
                System.out.println("\n[ERRO] Numero invalido! Tente novamente.\n");

       } while (n <= 2 || n % 2 == 0);

        System.out.println("\nNumero aceito! Obrigado.");
        System.out.println("Aqui esta a sua recompensa:\n");

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++)
                System.out.print(" ");

            for (int j = 0; j < (n - i) * 2 - 1; j++)
                System.out.print(carater);

            System.out.println();
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n - i - 1; j++)
                System.out.print(" ");

            for (int j = 0; j < i * 2 + 1; j++)
                System.out.print(carater);

            System.out.println();
        }

    }
}
