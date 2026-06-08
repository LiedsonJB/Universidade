import java.util.*;

public class MusicOrganizer {
    private ArrayList<Musica> myArray = null;
    
    public MusicOrganizer(){
        myArray = new ArrayList<>();
    }
    
    public void addMusic(Musica novo){
        this.myArray.add(novo);
    }
    
    public void orderByAsc() {
        Arrays.sort(this.myArray);
    }

    
    public void orderByDesc(){
    this.myArray.sort(Collections.reverseOrder());

    }
}