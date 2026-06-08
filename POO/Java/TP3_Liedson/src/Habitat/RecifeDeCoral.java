package Habitat;

import Base.ElementoSimulacao;

public class RecifeDeCoral extends ElementoSimulacao {
    private int saude;
    private int taxaRegeneracao;
    private int taxaDegradacao;

    //construtor para inicializar as minhas variaveis
    public RecifeDeCoral(int saudeInicial,
                         int taxaRegeneracao,
                         int taxaDegradacao,
                         String nome, boolean status){
        super(nome, status);
        this.saude = saudeInicial;
        this.taxaDegradacao = taxaDegradacao;
        this.taxaRegeneracao = taxaRegeneracao;
    }

    // retornar a saude do recife
    public int getSaude() {return this.saude;}

    // atualizar o estado do recife regenerando-a
    @Override
    public void atualizarEstado() {
        if(getStatus()) {
            if (this.saude < 100 && estaDegradado())
                saude += this.taxaRegeneracao;
        }else
            System.out.println("Error 002\n------------------------------\nElemento nao se encontra neste momento");
    }

    //verificar se o recife esta degradado
    public boolean estaDegradado(){
        return this.saude < 30;
    }

    //degradar o recife
    public void degradar(){
        if(getStatus() && (getSaude() > 0))
            this.saude -= this.taxaDegradacao;
        else
            System.out.println("Error 002\n------------------------------\nElemento nao se encontra neste momento");
    }

    /*public Color getCorRepresentacao(){};*/
}
