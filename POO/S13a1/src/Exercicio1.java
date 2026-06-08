import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class Exercicio1 {
    public static List<Pessoa> pessoas;

    public static void main(String[] args) {
        pessoas = Arrays.asList(
            new Pessoa("Liedson", "Araujo", 19),
            new Pessoa("Carlos", "Conceicao", 20),
            new Pessoa("Bruna", "Correia", 19),
            new Pessoa("Liedson", "Delgado", 19)
        );

        show1();
        System.out.printf("\n\n-------------------------------\nSegundo print\n-------------------------------\n");
        show2();

        System.out.printf("\n\n-------------------------------\nCom expressao lambda\n-------------------------------\n");
        System.out.println("Com apelidos que comecem com c");
        printCondiconal((Pessoa p) -> p.getApelido().startsWith("C"));
        System.out.println("Com idade > 30");
        printCondiconal((Pessoa p) -> p.getIdade() > 30);
        System.out.println("Toda a lista");
        printCondiconal((Pessoa p) -> true);
    }

    public void ordernar(){
        Collections.sort(pessoas, (Pessoa p1, Pessoa p2) -> p1.getApelido().compareTo(p2.getApelido()));
    }

    public static void show1(){
        for (Pessoa b : pessoas){
            System.out.println("Nome: " + b.getNome() + " aplido: " + b.getApelido() + " idade: " + b.getIdade());
        }
    }

    public static void show2(){
        for (Pessoa b : pessoas){
            if(b.getApelido().indexOf("C") != -1)
                System.out.println("Nome: " + b.getNome() + " aplido: " + b.getApelido() + " idade: " + b.getIdade());
        }
    }

    public static void printCondiconal(Condicao filtro){
        for(Pessoa b : pessoas){
            if(filtro.testar(b) == true)
                System.out.println("Nome: " + b.getNome() + " aplido: " + b.getApelido() + " idade: " + b.getIdade());
        }
    }
}
