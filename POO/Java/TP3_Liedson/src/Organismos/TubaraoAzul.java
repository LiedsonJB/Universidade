package Organismos;

import Base.Consumidor;
import Base.OrganismoMarinho;

public class TubaraoAzul extends OrganismoMarinho implements Consumidor<Cavala> {
    private int taxaPredacao;
     public TubaraoAzul(int populacaoInicial,
                        double taxaReproducao,
                        int taxaPredacao,
                        String nome, boolean status){
         super(nome, populacaoInicial, taxaReproducao, status);
         this.taxaPredacao = taxaPredacao;
     }

     // metado para alimentar os tubaroes
    @Override
    public int consumir(Cavala presa) {
         if(getStatus()) {
             int quantidadeConsumo = populacao * taxaPredacao;
             if(presa.getPopulacao() > 0) {
                 presa.serPredado(quantidadeConsumo);
                 return quantidadeConsumo;
             }else{
                 System.out.println("Sem presa no momento");
                 return -1;
             }
         }else{
             System.out.println("Error 111\n------------------------------\nErro desconhecido por agora");
             return -1;
         }
    }

    //atualizar o estado colocando-os a reproduzir
    @Override
    public void atualizarEstado() {
         if(getStatus())
            reproduzir();
         else
             System.out.println("Error 002\n------------------------------\nElemento nao se encontra neste momento");
    }
}
