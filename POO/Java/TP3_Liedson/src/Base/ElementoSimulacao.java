package Base;

public abstract class ElementoSimulacao {
    private final String nome;
    private final boolean status;

    public ElementoSimulacao(String name, boolean status){
        this.nome = name;
        this.status = status;
    }

    public String getNome() {return this.nome;}
    public abstract void atualizarEstado();
    public boolean getStatus(){return status;}
    /*public Color getCorRepresentacao(){};*/
}
