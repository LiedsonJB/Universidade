public class Ponto3D extends Ponto2D {
    private float z;

    public Ponto3D(float x, float y, float z){
        super(x,y);
        this.z = z;
    }

    public float getZ(){return this.z;}
    public void setZ(float z){this.z = z;}

    public void increment(float x, float y, float z){
        super.increment(x, y);
        this.z += z;
    }
}
