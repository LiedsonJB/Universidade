public class Lance {
    private Pessoa p;
    private final int valor;

    public Lance(int Valor){
        this.valor = Valor;
    }

    public Lance(int valor, String Nome, String contato){
        this.valor = valor;
        this.p = new Pessoa(Nome, contato);
    }

    public int getValor() {return this.valor;}
    public Pessoa getP1() {return this.p;}
}
