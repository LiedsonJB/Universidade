public class Comprimento {
    public void saudar(Saudacao b){
        b.executarSaudacao();
    }

    public static void main(String[] args) {
        Comprimento comprimento = new Comprimento();

        SaudacaoBomDia sbd = new SaudacaoBomDia();
        SaudacaoBreve sb = new SaudacaoBreve();

        comprimento.saudar(sbd);
        comprimento.saudar(sb);
    }
}
