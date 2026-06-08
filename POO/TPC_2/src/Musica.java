public class Musica {
    private final String nome;
    private final String caminho;
    private String artista;
    private final float duracao;
    
    public Musica(String nome, String caminho, float duracao){
        this.nome = nome;
        this.caminho = caminho;
        this.duracao = duracao;
    }
    
    public Musica(String nome, String caminho, float duracao, String Artista){
        this.nome = nome;
        this.caminho = caminho;
        this.duracao = duracao;
        this.artista = Artista;
    }
    
    public String getNome(){return this.nome;}
    public String getCaminho(){return this.caminho;}
    public String getArtista(){return this.artista;}
    public float getDuracao(){return this.duracao;}
}