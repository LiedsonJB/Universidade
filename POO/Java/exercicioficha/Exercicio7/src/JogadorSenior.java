public class JogadorSenior extends Jogador{
    private double bonus;

    public JogadorSenior(double bonus, String Nome, double Salario){
        super.setNome(Nome);
        super.setSalarioBase(Salario);
        this.bonus = bonus;
    }

    public double getBonus(){return this.bonus;}

    public double getSalario() {
        return super.getSalario() + bonus;
    }
}
