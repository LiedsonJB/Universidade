public class FrutaVolume extends Fruta{
    private final float volume;

    public FrutaVolume(String nome, float precoBase, float volume){
        super(nome, precoBase);
        this.volume = volume;
    }

    public float getVolume(){return this.volume;}

    @Override
    public float precoTotal(){
        return (this.volume * super.getPrecoBase());
    }
}
