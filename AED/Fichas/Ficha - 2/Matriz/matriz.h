#ifndef MATRIZ_H_INCLUDED
#define MATRIZ_H_INCLUDED

float **alocar(int n, int m);
void ler(float **v, int a, int s);
void escrever(float **v, int a, int s);
void mediaC(float **v, int a, int s);
void miniLinas(float **v, int a, int s);
void libertar(float **v, int a, int s);

#endif // MATRIZ_H_INCLUDED
