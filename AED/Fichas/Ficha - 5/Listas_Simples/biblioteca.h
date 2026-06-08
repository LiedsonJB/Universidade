#ifndef BIBLIOTECA_H_INCLUDED
#define BIBLIOTECA_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

struct aluno {

    int numero;
    char *nome;
    int ano;
    char *curso;

    struct aluno* next;

};

typedef struct aluno Aluno;
typedef Aluno * PALUNO;

char *newName(char *name);
void show_student(int number, char *name);
int itemCompare(char *name1, char *name2);
PALUNO insertStudentSorted(PALUNO head, char *name, int number);
void show(PALUNO head);
int searchByname(PALUNO head, char *name);
int searchBynumber(PALUNO head, int number);
PALUNO deleteStudent(PALUNO head, char *name);
void print_Lista(PALUNO head);
int menu();
char *Lernome();

#endif // BIBLIOTECA_H_INCLUDED
