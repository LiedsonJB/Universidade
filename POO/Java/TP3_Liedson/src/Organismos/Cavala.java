package Organismos;

import Base.Consumidor;
import Base.OrganismoMarinho;
import Base.Predavel;

public class Cavala extends OrganismoMarinho implements Consumidor<Plancton>, Predavel {
    public Cavala(int populacaoInicial,
                  double taxaReproducao,
                  int consumoPorCiclo,
                  String nome, boolean status){
        super(nome, populacaoInicial, taxaReproducao, status);
    }

    //alimentar meua peixes com Plancton
    @Override
    public int consumir(Plancton presa) {
        if(getStatus()) {
            if (presa.getQuantidade() == 0) {
                System.out.println("Sem cavala");
                return -1;
            }else
                return presa.consumir(populacao);
        }else{
            System.out.println("Error 111\n------------------------------\nErro desconhecido por agora");
            return -1;
        }
    }

    // atualizar o estado dos peixes para coloca-los a reproduzir
    @Override
    public void atualizarEstado() {
        if(getStatus())
            reproduzir();
        else
            System.out.println("Error 002\n------------------------------\nElemento nao se encontra neste momento");
    }

    //metado que diminiui a quantidade de cavalas ao serem predados pelo seu predador
    @Override
    public void serPredado(int quantidade) {
        if(getStatus()) {
            if (quantidade < 0)
                throw new IllegalArgumentException("Quantidade predada não pode ser negativa");

            populacao -= quantidade;
            if (populacao < 0)
                populacao = 0;
        }else
            System.out.println("Error 002\n------------------------------\nElemento nao se encontra neste momento");
    }
}
