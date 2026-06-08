public class Main {
    public static void main(String[] args) {
        NewsFeed n1 = new NewsFeed();
        MessagePost Message1 = new MessagePost("Ola", "Joao", "Teste");
        PhotoPost PhotoPost1 = new PhotoPost("Novo Teste", "Maria", "Teste2", "C://");

        n1.addPost(Message1);
        n1.addPost(PhotoPost1);

        n1.show();
    }
}