public class Endereco {

        private int number;
        private String rua;
        private int N_apart;
        private String cidade;
        private int cd_Postal;

        public Endereco(Endereco novo){
            this.number = novo.getNumber();
            this.rua = novo.getRua();
            this.N_apart = novo.getN_Apart();
            this.cidade = novo.getCidade();
            this.cd_Postal = novo.getCD_Postal();
        }

        public Endereco(int n, String Rua, String Cidade, int CDPostal, int NAPART){
            this.number = n;
            this.rua = Rua;
            this.N_apart = NAPART;
            this.cidade = Cidade;
            this.cd_Postal= CDPostal;
        }

        public Endereco(int Nart){
            this.N_apart = Nart;
            this.number = 0;
            this.rua = null;
            this.cidade = null;
            this.cd_Postal= 0;
        }

        public Endereco(){
            this.N_apart = 0;
            this.number = 0;
            this.rua = null;
            this.cidade = null;
            this.cd_Postal= 0;
        }

        public int getNumber(){return this.number;}
        public String getRua(){return this.rua;}
        public int getN_Apart(){return this.N_apart;}
        public String getCidade(){return this.cidade;}
        public int getCD_Postal(){return this.cd_Postal;}

        public void setNumber(int n){this.number = n;}
        public void setRua(String rua1){this.rua = rua1;}
        public void setCd_Postal(int cd_Postal) {this.cd_Postal = cd_Postal;}
        public void setCidade(String cidade) {this.cidade = cidade;}
        public void setN_apart(int n_apart) {N_apart = n_apart;}

        public String showObjet(){
            StringBuilder aux = new StringBuilder();

            aux.append("Rua: " + this.rua + "\n");
            aux.append("Cidade: " + this.cidade + "\n");
            aux.append("Codigo Postal: " + this.cd_Postal + "\n");

            return aux.toString();
        }

        public Boolean vemAntes(Endereco other){
            if(this.cd_Postal < other.getCD_Postal())
                return true;
            else
                return false;
        }

        public Endereco clone(){
            return new Endereco(this);
        }
}
