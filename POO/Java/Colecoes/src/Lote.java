public class Lote {
    private final int numero;
    private String descrisao;
    private Lance maiorLance;

    public Lote(int n, String desc){
        this.numero = n;
        this.descrisao = desc;
        this.maiorLance = null;
    }

    public boolean fazerProposta(Lance bid){
        if(maiorLance == null){
            maiorLance = bid;
            return true;
        } else if (bid.getValor() > maiorLance.getValor()) {
            maiorLance = bid;
            return true;
        }else
            return false;
    }

    public String toString(){
        String aux = numero + ":" + descrisao;
        if(maiorLance != null){
            aux += " Lance: " + maiorLance.getValor();
        }else{
            aux += " (Sem lances registados)";
        }
        return aux;
    }

    public int getNumero() {return numero;}
    public Lance getL() {return maiorLance;}
    public String getDescrisao() {return descrisao;}
}
