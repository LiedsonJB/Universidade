package EventoClimatico;

import Base.ElementoSimulacao;

public class EventoClimatico extends ElementoSimulacao {
    private int duracao;
    private final int impactotemperatura;
    private int ciclo;

    //construtor para inicializar as minhas variaveis
    public EventoClimatico(String tipo,
                           int duracao,
                           int impactoTemperatura, Boolean status,
                            int ciclo){
        super(tipo, status);
        this.duracao = duracao;
        this.impactotemperatura = impactoTemperatura;
        this.ciclo = ciclo;
    }

    //atualizar o estado do clima
    @Override
    public void atualizarEstado() {
        if(getStatus()) {
            if (estaAtivo())
                this.ciclo--;
        }else
            System.out.println("Error 002\n------------------------------\nElemento nao se encontra neste momento");
    }

    //verificar se ainda existe algum ciclo presente no ambiente
    public boolean estaAtivo(){
        return (ciclo > 0);
    }

    //retornar nome do evento/elemento
    @Override
    public String getNome() {//mesmo do getTipo()
        return super.getNome();
    }

    // retornar o impacto da temperatura no ambiente em caso que ele esta presente
    public int getImpactoTemperatura(){
        if(estaAtivo())
            return this.impactotemperatura;
        else
            return 0;
    }

    //retornar o numero de ciclos restantes
    public int getCiclosRestantes(){return this.ciclo;}

    //retornar a duracao do ciclo
    public int getDuracao() {return duracao;}
}
