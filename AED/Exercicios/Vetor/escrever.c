#include "vetor_10.h"
#include <stdio.h>

void escrever(int v[], int t){

    /*for(int i = 0; i < t; i++){

        printf("%d Elemento: %d\n", i+1, v[i]);

    }*/
     t--;
    if(t > 0){
        printf("%d elemento: %d\n", t+1, v[t]);
        escrever(v,t);
    }else
         printf("%d elemento: %d", t+1, v[t]);

}
