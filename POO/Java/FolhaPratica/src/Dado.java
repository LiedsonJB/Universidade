import java.util.Random;

public class Dado{
    private int face;
    Random alt;

    public Dado(int valor){
        this.face = valor;
    }

    public Dado(){
        this.alt = new Random();
        this.face = alt.nextInt(6) + 1;

    }

    public void lancarDados() {
        this.face = this.alt.nextInt(6) + 1;
    }

}


/*
public class Dado {
    private Random alt;

    public Dado() {
        alt = new Random();
    }

    public int lancarDados() {
        return alt.nextInt(6) + 1;
    }
}
*/