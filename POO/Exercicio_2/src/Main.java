import java.util.*;

public class Main {
    public static void main(String[] args) {
        ListaPontos v = new ListaPontos();

        v.inserir(new Ponto2D(0, 5));
        v.inserir(new Ponto2D(0, 6));
        v.inserir(new Ponto2D(0, 7));
        v.inserir(new Ponto2D(0, 8));
        v.inserir(new Ponto2D(0, 9));
        v.inserir(new Ponto2D(0, 10));
        v.inserir(new Ponto2D(0, 11));
        v.inserir(new Ponto2D(0, 12));
        v.inserir(new Ponto2D(0, 13));
        v.inserir(new Ponto2D(0, 14));


        v.listarPontos();
        v.remover(10);
        v.listarPontos();
    }
}