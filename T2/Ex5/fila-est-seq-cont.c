#include <stdio.h>
#include <stdlib.h>
#include "fila-est-seq-cont.h"
#define max 20

struct fila
{
    int no[max];
    int ini, cont;
};

// Cria fila
Fila cria_fila()
{
    Fila f;
    f = (Fila)malloc(sizeof(struct fila));
    if (f != NULL)
    {
        f->ini = 0;
        f->cont = 0;
    }
    return f;
}

// Verifica se fila está vazia
int fila_vazia(Fila f)
{
    if (f->cont == 0)
        return 1;
    else
        return 0;
}

// Verifica se fila está cheia
int fila_cheia(Fila f)
{
    if (f->cont == max)
        return 1;
    else
        return 0;
}

// Insere elemento no fim da fila
int insere_fim(Fila f, int elem)
{
    if (fila_cheia(f) == 1)
        return 0;
    // insere elemento no final
    f->no[(f->ini + f->cont) % max] = elem;
    f->cont++; // Incremento não circular
    return 1;
}

// Remove elemento do inicio da fila
int remove_ini(Fila f, int *elem)
{
    if (fila_vazia(f) == 1)
        return 0;
    // Remove o elemento do incio
    *elem = f->no[f->ini];
    f->ini = (f->ini + 1) % max; // Incremento circular
    f->cont--;                   // Decremento não circular
    return 1;
}

// Imprime fila
void imprime(Fila f)
{
    if (fila_vazia(f) == 1)
        printf("Fila vazia! \n");
    else
    {
        printf("Fila : {");
        int i = (f->ini) % max;
        int j = (f->cont) % max;
        for (i; i < j; i++)
            printf((i != j - 1) ? "%d, " : "%d}", f->no[i]);
    }
}
