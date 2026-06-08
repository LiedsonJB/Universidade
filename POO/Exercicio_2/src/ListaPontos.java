import java.util.ArrayList;

public class ListaPontos {
    private ArrayList<Ponto2D> pontos;

    public ListaPontos(){
        pontos = new ArrayList<>();
    }

    public ArrayList<Ponto2D> getPontos(){
        return pontos;
    }

    public void inserir(Ponto2D ponto){
        this.pontos.add(ponto);
    }

    public void remover(int indice){this.pontos.remove(indice);}
    public void remover(Ponto2D p){this.pontos.remove(p);}

    public void listarPontos(){
        for(Ponto2D p : this.pontos){
            System.out.println(p.toStrings());
        }
    }
}
