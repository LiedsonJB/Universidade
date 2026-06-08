public class Pessoa {
    private final String nome;
    private String contato;

    public Pessoa(String Nome){
        this.nome = Nome;
    }

    public Pessoa(String Nome, String Number){
        this.nome = Nome;
        this.contato = Number;
    }

    public String getContato() {return contato;}
    public String getNome() {return nome;}
}
