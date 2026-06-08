package Organismos;

import Base.ElementoSimulacao;

public class Plancton extends ElementoSimulacao {
    private int quantidade;
    private int TaxaCrescimento;

    //construtor para inicializar as minhas variaveis
    public Plancton(int quantidadeInicial, int taxaCrescimento, String tipo, boolean status){
        super(tipo, status);
        this.quantidade = quantidadeInicial;
        this.TaxaCrescimento = taxaCrescimento;
    }

    //atualizar o estado dos planctons colocando-os para crescer
    @Override
    public void atualizarEstado() {
        if(getStatus())
            crescer();
        else
            System.out.println("Error 002\n------------------------------\nElemento nao se encontra neste momento");
    }

    //crescer os planctons com base na sua taxa de crescimento
    public void crescer(){
        quantidade += TaxaCrescimento;
    }

    //retornar a quantidade de plancton desponivel ainda
    public int getQuantidade() {
        return this.quantidade;
    }

    //diminuir plancton quando for consumida
    public int consumir(int quantidadeConsumida){
        if(quantidade >= quantidadeConsumida) {
            quantidade -= quantidadeConsumida;
            return quantidadeConsumida;
        }else {
            int consumido = quantidade;
            quantidade = 0;
            return consumido;
        }
    }
}
