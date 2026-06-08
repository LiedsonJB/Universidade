import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {

    private static  void lerFicheiro(String nome) throws FileNotFoundException{
        File ficheiro = new File(nome);
        Scanner inputFile = new Scanner(ficheiro);

    }

    public static void main(String[] args) {
        Scanner src = new Scanner(System.in);

        System.out.print("Nome do ficheiro: ");
        String nome = src.nextLine();

        try {
            lerFicheiro(nome);
        }catch (FileNotFoundException e){
            System.out.println("Nao foi possivel abri o ficheiro");
        }


    }
}