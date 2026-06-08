import java.util.*;

public class Main {
    public static Scanner src = new Scanner(System.in);

    public static void main(String[] args) {
        Pixel myPixel = new Pixel(0, 0, "#fff");
        String cor;
        float x, y;

        while(true){
        int op = menu();

            switch(op) {
                case 1:
                    System.out.println("A cor do pixel e de: " + myPixel.getCOR());
                    System.out.println();
                    break;

                case 2:
                    System.out.print("Nova cor: ");
                    cor = src.next();
                    myPixel.setCor(cor);
                    System.out.println("Nova cor atualizada: " + myPixel.getCOR());
                    break;

                case 3:
                    System.out.println("Aqui a posicao do pixel: em x" + myPixel.getX() + " em y: " + myPixel.getY());
                    break;

                case 4:
                    System.out.println("Mover para cima");
                    do {
                        System.out.print("Posicao y: ");
                        y = src.nextFloat();

                        if(y < myPixel.getY()){
                            System.out.println("Um valor maior da posicao atual do y ele se encontra em: " + myPixel.getY());
                            continue;
                        }
                    }while(y < myPixel.getY());

                    myPixel.cima(y);
                    System.out.println("posicao alterada");
                    break;

                case 5:
                    do {
                        System.out.println("Mover para direita");
                        System.out.print("Posicao x: ");
                        x = src.nextFloat();

                        if (x < myPixel.getX()) {
                            System.out.println("Um valor maior da posicao atual do x ele se encontra em: " + myPixel.getX());
                            continue;
                        }
                    }while(x < myPixel.getX());

                    myPixel.direita(x);
                    System.out.println("posicao alterada");
                    break;

                case 6:
                    do {
                        System.out.println("Mover para baixo");
                        System.out.print("Posicao y: ");
                        y = src.nextFloat();

                        if (y < myPixel.getY()) {
                            System.out.println("Um valor maior da posicao atual do y ele se encontra em: " + myPixel.getY());
                            continue;
                        }
                    }while(y < myPixel.getY());

                    myPixel.baixo(y);
                    System.out.println("posicao alterada");
                    break;

                case 7:
                    do {
                        System.out.println("Mover para Esquerda");
                        System.out.print("Posicao x: ");
                        x = src.nextFloat();

                        if (x < myPixel.getX()) {
                            System.out.println("Um valor maior da posicao atual do y ele se encontra em: " + myPixel.getX());
                            continue;
                        }
                    }while(x < myPixel.getY());

                    myPixel.esquerda(x);
                    System.out.println("posicao alterada");

                    break;

                case 8:
                    System.out.println("Mover para Aleatorio");
                    System.out.print("Posicao x: ");
                    x = src.nextFloat();

                    System.out.print("Posicao y: ");
                    y = src.nextFloat();

                    myPixel.alt(x, y);
                    System.out.println("posicao alterada");
                    break;

                case 9:
                    System.out.printf("\n--------------------------------------------------\nObrigado volte sempre");
                    System.exit(0);
                    break;
            }
        }

    }

    private static int menu(){
        int op;
        do {
            System.out.println("------------------ Menu -------------------");
            System.out.printf("1. Ver a cor\n2. Mudar de cor\n3. Ver Posicao do pixel ");
            System.out.printf("4. Mover para cima\n5. Mover para direita\n6. Mover para baixo ");
            System.out.printf("7. Mover para esquerda\n8. Mover posicao como desejas\n9. Sair ");

            System.out.print("\nEscolha: ");
            op = src.nextInt();

            if(op < 1 || op > 9){
                System.out.printf("\n------------------------------------\nOpcao invalida\n");
                System.out.println("-------------------------------------");
            }
        }while(op < 1 || op > 9);

        return op;
    }
}