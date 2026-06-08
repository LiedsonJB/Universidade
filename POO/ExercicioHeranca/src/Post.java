public class Post {
    protected int likes;
    protected String comentarios;
    protected String autor;
    protected long tempo;

    public  Post(String comentario, String autor){
        this.likes = 0;
        this.comentarios = comentario;
        this.autor = autor;
    }

    public int getLikes(){return this.likes;}
    public String getComantarios(){return this.comentarios;}
    public String getAutor(){return this.autor;}
    public long getTempo(){return this.tempo;}

    public void IncLike(){this.likes++;}
}
