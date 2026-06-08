public class FrutaPeso extends Fruta{
    private final float peso;

    public FrutaPeso(String nome, float precoBase, float peso){
        super(nome, precoBase);
        this.peso = peso;
    }

    public float getUnidade(){return this.peso;}

    @Override
    public float precoTotal(){
        return (this.peso * super.getPrecoBase());
    }
}
