import java.time.LocalDate;
import java.util.ArrayList;

public class capitaoEquipa extends JogadorSenior {
    private final LocalDate dataInc;
    private boolean status;
    private LocalDate dataFim;
    private ArrayList<LocalDate> NJogos;

    public capitaoEquipa(LocalDate dataIn, double Bonus, String Nome, double Salario){
        super(Bonus, Nome, Salario);
        this.status = true;
        this.dataInc = dataIn;
        this.NJogos = new ArrayList<>();
    }

    public LocalDate getDataInc() {return this.dataInc;}
    public LocalDate getDataFim() {return this.dataFim;}
    public Boolean getStatus(){return this.status;}

    public void setDataFim(LocalDate dataFim){this.dataFim = dataFim;}
    public void FimCapitao(LocalDate data){this.status = false; this.dataFim = dataFim;}
    public void addJogo(LocalDate data){NJogos.add(data);}
}
