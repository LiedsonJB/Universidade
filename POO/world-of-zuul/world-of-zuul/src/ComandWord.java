public enum ComandWord {
    IR("ir"), SAIR("sair"), AJUDA("ajuda"), VER("ver");

    private String stringComando;

    ComandWord(String stringComando){
        this.stringComando = stringComando;
    }
}
