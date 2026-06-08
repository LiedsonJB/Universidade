#include "function.h"

int main() {
    int id;
    float testes, TP, Final;
    float soma[3];  // array para os resultados

    for (int i = 0; i < 3; i++) {

        id = fork();

        if (id == 0) {
            switch (i) {
                case 0:
                    sleep(1); //durmir por 1s
                    system("clear");    
                    testes = NotaTeste();
                    testes *= 10;   /* multiplica por 10 para recuperar as casas decimais*/
                    exit((int)testes);  //Converter para int
                break;
                case 1:
                    sleep(5);
                    system("clear");
                    TP = TPraticos();
                    TP *= 10;
                    exit((int)TP);  // Converter para int
                break;
                case 2:
                    sleep(10);
                    system("clear");
                    Final = NotaFinal();
                    Final *= 10;
                    exit((int)Final);  // Converter para int
                break;
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        int status;
        wait(&status);  // Aguarda o fim do processo filho e recebe o valor no status

        if (WIFEXITED(status)) {
            soma[i] = (float)WEXITSTATUS(status) /10.0;  // Obtém o valor da saída do processo filho
        }

    }

    float resultado = soma[0] + soma[1] + soma[2]; //somar  as notas
    printf("\nNota Final em FSO: %.2f\n", resultado);

    return 0;
}