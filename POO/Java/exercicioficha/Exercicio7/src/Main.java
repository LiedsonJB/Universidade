import java.time.LocalDate;

public class Main {
    public static void main(String[] args) {

        capitaoEquipa capitao = new capitaoEquipa(LocalDate.of(2024, 1, 10), 1500.0, "Liedson", 8000.0);

        System.out.println("Nome: " + capitao.getNome());
        System.out.println("Salário total: " + capitao.getSalario());
        System.out.println("Data início como capitão: " + capitao.getDataInc());
        System.out.println("É capitão atualmente? " + capitao.getStatus());

        capitao.addJogo(LocalDate.of(2024, 2, 1));
        capitao.addJogo(LocalDate.of(2024, 3, 14));
        capitao.addJogo(LocalDate.of(2024, 4, 5));

        capitao.FimCapitao(LocalDate.of(2024, 6, 1));
        System.out.println("Capitão ativo? " + capitao.getStatus());
        System.out.println("Data fim da capitania: " + capitao.getDataFim());
    }
}
