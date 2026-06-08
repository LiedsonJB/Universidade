package Organismos;

import Base.Consumidor;
import Base.OrganismoMarinho;

import java.awt.*;

public class AveMarinho extends OrganismoMarinho implements Consumidor<Cavala>{
    private int consumo;
    //private Color corRepresentacao;

    //construtor para inicializar as minhas variaveis
    public AveMarinho(int populacaoInicial,
                      double taxaReproducao,
                      int consumoPorCiclo,
                      String nome, boolean status){
        super(nome, populacaoInicial, taxaReproducao, status);
        consumo = consumoPorCiclo;
    }

    //atualizar o estado da minha ave
    @Override
    public void atualizarEstado() {
        if(getStatus()) {
            reproduzir();
        }else
            System.out.println("Error 002\n------------------------------\nElemento nao se encontra neste momento");
    }

    //alimentar minha ave com cavala
    @Override
    public int consumir(Cavala presa) {
        if (getStatus()) {
            if(presa.getPopulacao() > 0) {
                int quantidadeConsumida = Math.min(consumo, presa.getPopulacao());
                presa.serPredado(quantidadeConsumida);
                return quantidadeConsumida;
            }else{
                System.out.println("Sem presa no momento");
                return -1;
            }
        }else{
            System.out.println("Error 002\n------------------------------\nElemento nao se encontra neste momento");
            return -1;
        }
    }

/*
    public Color getCorRepresentacao() {return corRepresentacao;}
*/
}
