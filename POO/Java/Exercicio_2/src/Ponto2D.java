public class Ponto2D {
    private float x;
    private float y;

    public Ponto2D(Ponto2D b){
        this.x = getX();
        this.y = getY();
    }

    public Ponto2D(){this.x = 0; this.y = 0;}

    public Ponto2D(float Xp, float Yp){
        this.x = Xp;
        this.y = Yp;
    }

    public Ponto2D(float Xp){
        this.x = Xp;
    }
    public Ponto2D(float YP, char lixo){
        this.y = YP;
    }

    public float getX(){return this.x;}
    public float getY(){return this.y;}

    public void setX(float X){this.x = X;}
    public void setY(float Y){this.y = Y;}

    public Ponto2D clone(Ponto2D b){
        return  new Ponto2D(this);
    }

    public String toStrings(){
        StringBuilder string = new StringBuilder();

        string.append("Posicao x: " + this.x);
        string.append("Posicao y: " + this.y + "\n");

        return string.toString();
    }

    public void increment(float xp, float yp){
        this.x += xp; this.y += yp;
    }
}
