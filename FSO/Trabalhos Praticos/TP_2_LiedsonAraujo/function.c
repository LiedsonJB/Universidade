#include "function.h"

// Função para calcular a nota dos testes
float NotaTeste(){
    float notaFinal = 0, valor;

    // Loop para coletar as notas dos 2 testes
    for(int i = 0; i < 2; i++){
        printf("Nota do %d teste: ", i+1);
        scanf("%f", &valor);  // Lê a nota do teste
        notaFinal += valor * 0.15;  // Calcula 15% da nota do teste e adiciona à nota final
    }

    return notaFinal;  // Retorna a nota final dos testes
}

// Função para calcular a nota dos trabalhos práticos
float TPraticos(){
    float notaFinal = 0, valor;

    // Loop para coletar as notas dos 4 trabalhos práticos
    for(int i = 0; i < 4; i++){
        printf("Nota do %d T_Praticos: ", i+1);
        scanf("%f", &valor);  // Lê a nota do trabalho prático
        notaFinal += valor * 0.1;  // Calcula 10% da nota do trabalho e adiciona à nota final
    }

    return notaFinal;  // Retorna a nota final dos trabalhos práticos
}

// Função para calcular a nota final (considerando participação e trabalho em grupo)
float NotaFinal(){
    float Participacao, T_Grupo = 0, valor;
    float v[2] = {0.05, 0.2};  // Pesos para os dois trabalhos de grupo

    // Loop para coletar as notas dos 2 trabalhos de grupo
    for(int i = 0; i < 2; i++){
        printf("Nota do %d T_Grupo: ", i+1);
        scanf("%f", &valor);  // Lê a nota do trabalho de grupo
        T_Grupo += valor * v[i];  // Calcula o peso de cada trabalho e adiciona à nota final do grupo
    }

    printf("\nParticipacao: ");
    scanf("%f", &Participacao);  // Lê a nota de participação
    T_Grupo += Participacao * v[0];  // Calcula a participação e adiciona à nota final do grupo

    return T_Grupo;  // Retorna a nota final considerando os trabalhos de grupo e participação
}