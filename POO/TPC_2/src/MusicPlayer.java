
public class MusicPlayer {
    private final Musica musica = null;
    
    public MusicPlayer(Musica myMusic){
        this.musica = myMusic;
    }
    
    public boolean play(){
        if (musica != null) {
            System.out.println("Musica sendo reproduzida");
            return true;//se reproduzir
        } else {
            System.out.println("Nao foi possivel criar a musica");
            return false;//caso na conseguir reproduzir            
        }
    }
}