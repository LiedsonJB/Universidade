import java.util.ArrayList;

public class NewsFeed {
    private ArrayList<Post> myPost;

    public NewsFeed(){
        this.myPost = new ArrayList<>();
    }

    public void addPost(Post novo){
        this.myPost.add(novo);
    }

    public void show(){
        for(Post aux : myPost){
            System.out.println("Autor: " + aux.getAutor());

            if(aux instanceof PhotoPost){
                System.out.println("Caminho da imagem: " + ((PhotoPost) aux).getCaminho());
            }else{
                System.out.println("Mensagem: " + ((MessagePost) aux).getMessage());
            }

            System.out.println("Likes: " + aux.getLikes());
        }
    }
}
