public class Pixel {

    private double x;
    private double y;
    private String cor;

    public Pixel(double Xp, double Yp, String colorP){
        this.x = Xp;
        this.y = Yp;
        this.cor = colorP;

    }

    public double getX(){
        return this.x;
    }

    public double getY(){
        return this.y;
    }

    public String getCOR(){
        return this.cor;
    }

    public void setCor(String color){
        this.cor = color;
    }

    public void setX(int posX){
        this.x = posX;
    }

    public void setY(int posY){
        this.y = posY;
    }

    public void cima(float yp){
        this.y = yp;
    }

    public void baixo(float yp){
        this.y = yp;
    }

    public void direita(float xp){
        this.x = xp;
    }

    public void esquerda(float xp){
        this.x = xp;
    }

    public void alt(float xp,float yp){
        this.x = xp;
        this.y = yp;
    }
}
