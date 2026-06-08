import java.util.ArrayList;

public class Leilao {
    private int prox;
    private ArrayList<Lote> lots;

    public Leilao(){
        this.lots = new ArrayList<>();
        this.prox = 1;
    }

    public Lance registarLance(int valor ,String contact, String nome){
        return new Lance(valor, nome, contact);
    }

    public void adicionarNovo(String desc){
        this.lots.add(new Lote(prox, desc));
        prox++;
    }

    public void ListarLotes() {
        for(Lote lot : lots){
            System.out.println(lot.toString());
        }
    }
}
