package Ambiente;

import Base.ElementoSimulacao;
import EventoClimatico.EventoClimatico;
import Habitat.RecifeDeCoral;
import Organismos.*;
import java.util.ArrayList;
import java.util.List;

public class AmbienteMarinho{
    private List<ElementoSimulacao> elemetos;
    private int temperaturaAtual;
    private final int temperaturaBase;

    // construtor que inicializa as minhas variaveis
    public AmbienteMarinho(int temperaturaBase){
        elemetos = new ArrayList<>();
        this.temperaturaBase = temperaturaBase;
        this.temperaturaAtual = temperaturaBase;
    }

    //mostrar como o meu ambiente se encontra
    public void exibirEstado(){
        if(elemetos != null) {
            System.out.println(construir());
        }else{
            System.out.println("ERROR: 555 \n Sem elementos por agora no ambiente!!!");
        }
    }

    //adicionar elementos a minha lista
    public void addElemento(ElementoSimulacao e){
        this.elemetos.add(e);
    }

    //construir uma String com informacoes do meu ambiente
    private String construir(){
        StringBuilder aux =new StringBuilder();

        aux.append("Estado do Ambiente: \n----------------------------\n");
        aux.append("A temperatura atual e de: ").append(this.temperaturaAtual).append("\n");
        aux.append("elememtos encontrados no meu ambiente:\n------------------------------\n");

        //apanhar o nome e tipo de cada especie
        for(ElementoSimulacao e : elemetos){
            aux.append("Nome: ").append(e.getNome()).append("\n\tTipo de especie: ").append(e.getClass().getSimpleName()).append("\n");
        }
        return aux.toString();
    }

    // simular um ambiente
    public void simularCiclo(){
        if(elemetos != null) {
            for (ElementoSimulacao e : elemetos) {
                e.atualizarEstado();
                if (e instanceof TubaraoAzul aux) {
                    Cavala presa;
                    for (ElementoSimulacao i : elemetos) {
                        if (i instanceof Cavala) {
                            presa = (Cavala) i;
                            int quantidadeConsumida = aux.consumir(presa);
                            System.out.println("Foram consumidas: " + quantidadeConsumida + " cavala por tubaroes");
                            break;
                        }
                    }
                }
                if (e instanceof AveMarinho aux) {
                    Cavala presa;
                    for (ElementoSimulacao i : elemetos) {
                        if (i instanceof Cavala) {
                            presa = (Cavala) i;
                            int quantidadeConsumida = aux.consumir(presa);
                            System.out.println("Foram consumidas: " + quantidadeConsumida + " cavala por aves");
                            break;
                        }
                    }
                }
                if (e instanceof Cavala aux) {
                    Plancton presa;
                    for (ElementoSimulacao i : elemetos) {
                        if (i instanceof Plancton) {
                            presa = (Plancton) i;
                            int quantidadeConsumida = aux.consumir(presa);
                            System.out.println("Foram consumidas: " + quantidadeConsumida + " planton");
                            break;
                        }
                    }
                }
                if (e instanceof Plancton aux) {
                    aux.atualizarEstado();
                }
                if (e instanceof RecifeDeCoral aux) {
                    aux.atualizarEstado();
                    aux.degradar();
                    System.out.println("Saude do recife de coral: " + aux.getSaude());
                }
                if(e instanceof EventoClimatico aux){
                    aux.atualizarEstado();
                    temperaturaAtual += aux.getImpactoTemperatura();
                    System.out.println("Impacto da temperatura no ambiente: "+ temperaturaAtual);
                    System.out.println("Ciclos restantes: " + aux.getCiclosRestantes());
                    System.out.println("Duracao deste evento: " + aux.getDuracao());
                }
            }
        }else
            System.out.println("Error: 300\nSem elementos no ambiente");
    }
}
