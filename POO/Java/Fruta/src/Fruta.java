public abstract class Fruta {
    private final String nome;
    private final float precoBase;

    public Fruta(String nome, float precoBase){
        this.nome = nome;
        this.precoBase = precoBase;
    }

    public float getPrecoBase(){return this.precoBase;}
    public String getNome(){return this.nome;}

    public abstract float precoTotal();
}
