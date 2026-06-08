import Ambiente.AmbienteMarinho;
import EventoClimatico.EventoClimatico;
import Organismos.AveMarinho;
import Organismos.Cavala;
import Organismos.Plancton;
import Organismos.TubaraoAzul;

public class Main {
    public static void main(String[] args) {
        AmbienteMarinho ambienteMarinho = new AmbienteMarinho(50);

        //criacao dos meus elementos
        ambienteMarinho.addElemento(new TubaraoAzul(2, 0.5, 4, "Orca", true));
        ambienteMarinho.addElemento(new Cavala(50, 1.2, 5, "Atum", true));
        ambienteMarinho.addElemento(new Plancton(10, 10, "Algas", true));
        ambienteMarinho.addElemento(new AveMarinho(5,1.2, 2, "Cagarra", true));
        ambienteMarinho.addElemento(new EventoClimatico("Furacao", 2, 10, true, 20));

        //simular os elementos no meu ambientels
        ambienteMarinho.exibirEstado();
        ambienteMarinho.simularCiclo();
        ambienteMarinho.simularCiclo();
        ambienteMarinho.simularCiclo();

    }
}