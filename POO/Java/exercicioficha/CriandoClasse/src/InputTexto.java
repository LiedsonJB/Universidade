import java.util.Scanner;

public class InputTexto {
    public static void main(String[] args) {

        Scanner entradaDados = new Scanner(System.in);

        System.out.print("Digite sua idade: ");
        int idade = entradaDados.nextInt();
        String buffer = entradaDados.nextLine();

        System.out.print("Sua ALTURA: ");
        float altura = entradaDados.nextFloat();
        buffer = entradaDados.nextLine();

        System.out.print("Seu nome completo: ");
        String nome = entradaDados.nextLine();

        System.out.printf("\n-----------------------------------------------\n");
        System.out.printf("Seu nome: %s\nSua altura: %.2f\nSua idade: %d", nome, altura, idade);
    }
}
