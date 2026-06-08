package Base;

public abstract class OrganismoMarinho extends ElementoSimulacao{
    protected int populacao;
    protected double taxaReproducao;

    public OrganismoMarinho(String nome,
                            int populacaoInicial,
                            double taxaReproducao,
                            boolean status){
        super(nome, status);
        this.populacao = populacaoInicial;
        this.taxaReproducao = taxaReproducao;
    }

    public int getPopulacao() {
            return populacao;
    }

    public void setPopulacao(int populacao) {
        if(populacao > 0)
            this.populacao = populacao;
        else{
            System.out.println("Error: 001\n-----------------------------------\nNumero de populacao nao pode ser negativa!!!");
        }

    }

    // metado que permite a reproducao de uma especie aplicado a logica
    public void reproduzir(){
            populacao = populacao  + (populacao * Math.round((float) taxaReproducao));
    }
}
