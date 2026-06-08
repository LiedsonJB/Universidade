public class ParDeDados{

    private Dado d1;
    private Dado d2;

    public ParDeDados() {
        d1 = new Dado();
        d2 = new Dado();
    }

}

/*
public class ParDeDados {

    private Dado dado1;
    private Dado dado2;

    public ParDeDados() {
        dado1 = new Dado();
        dado2 = new Dado();
    }

    public boolean lancarEcompare() {
        int valor1 = dado1.lancarDados();
        int valor2 = dado2.lancarDados();

        return (valor1 == 6 && valor2 == 6);
    }
}
*/