#ifndef SOMA_H_INCLUDED
#define SOMA_H_INCLUDED

typedef struct{
    int real;
    int im;
}img;

img soma(img x, img y);
void ler(img *x, img *y);

#endif // SOMA_H_INCLUDED
