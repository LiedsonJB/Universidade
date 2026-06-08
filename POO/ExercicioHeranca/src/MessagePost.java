public class MessagePost extends Post {
    protected String Message;

    public MessagePost(String message, String autor, String comentario){
        super(comentario, autor);
        this.Message = message;
    }

    public String getMessage(){return this.Message;}
    public void IncLike(){super.IncLike();}
}
