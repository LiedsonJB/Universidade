public class FrutaUnidade extends Fruta{
    private final float unidade;

    public FrutaUnidade(String nome, float precoBase, float unidade){
        super(nome, precoBase);
        this.unidade = unidade;
    }

    public float getUnidade(){return this.unidade;}

    @Override
    public float precoTotal(){
        return (this.unidade * super.getPrecoBase());
    }
}
