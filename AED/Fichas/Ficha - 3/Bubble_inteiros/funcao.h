#ifndef FUNCAO_H_INCLUDED
#define FUNCAO_H_INCLUDED

//Bibliotecas
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef int Item;

//definicao dos macros
#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define exch(A, B) { Item t = A; A = B; B = t; }
#define compexch(A, B) if (less(B, A)) exch(A, B)

//Funcoes a utilizar
int *realocar(int *v, int n);
void subMenu1(int *v, int n);
int binaria(int *v, int n, int A);
void linear(int *v, int n);
void subMenu2(int *v, int n);
void menu_inicial(int *v, int n);
void mostrar(int *v, int n);
void ler(int *v, int n);
int *alocar(int *v, int n);
void bubble1(int *v, int T);
void selection(int a[], int l, int r);
void insertion(int a[], int l, int r);
void FixHeap (int a[], int n, int pos);
void buildheap(Item a[], int n);
void heapsort(Item a[], int n);
void merge1(Item a[], int l, int m, int r);
void mergesort(Item a[], int l, int r);

#endif // FUNCAO_H_INCLUDED
