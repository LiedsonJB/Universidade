#ifndef FUNCTION_H
#define FUNCTION_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#define N_B 10
#define NUM_V 3

int numB = N_B;

typedef struct filme{
    char *nome;
    int NumBl;
    struct node *next;
    
};

#endif