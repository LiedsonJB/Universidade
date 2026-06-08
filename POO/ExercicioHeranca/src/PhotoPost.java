public class PhotoPost extends Post {
    protected String legenda;
    protected String caminho;

    public PhotoPost(String legenda, String autor, String comentario, String caminho){
        super(comentario, autor);
        this.legenda = legenda;
        this.caminho = caminho;
    }

    public String getLegenda(){return this.legenda;}
    public String getCaminho(){return this.caminho;}

    public void IncLike(){super.IncLike();}
}
