#include <stdio.h>
#include <stdlib.h>
#include "fila-est-seq-circ.h"
#define max 20

struct fila
{
    int no[max];
    int ini, fim;
};
// Inicializa fila
Fila inicializar_fila()
{
    Fila f;
    f = (Fila)malloc(sizeof(struct fila));
    if (f != NULL)
    {
        f->ini = 0;
        f->fim = 0;
    }
    return f;
}

// Fila vazia
int fila_vazia(Fila f)
{
    if (f->ini == f->fim)
        return 1;
    else
        return 0;
}

// Fila cheia
int fila_cheia(Fila f)
{
    if (f->ini == (f->fim + 1) % max)
        return 1;
    else
        return 0;
}

// Insere elemento na fila
int insere_fila(Fila f, int elem)
{
    if (fila_cheia(f) == 1)
        return 0;
    // Insere elemento no final
    f->no[f->fim] = elem;
    f->fim = (f->fim + 1) % max; // Incremento circular
    return 1;
}

// Remove elemento no inicio da fila
int remove_fila(Fila f, int *elem)
{
    if (fila_vazia(f) == 1)
        return 0;
    // remove o elemento do inicio
    *elem = f->no[f->ini];
    f->ini = (f->ini + 1) % max; // incremento circular
    return 1;
}

// Imprime Fila
void imprime(Fila f)
{
    if (fila_vazia(f) == 1)
        printf("Fila vazia! \n");
    else
    {
        printf("Fila : {");
        int i = (f->ini) % max;
        int j = (f->fim) % max;
        for (i; i < j; i++)
            printf((i != j - 1) ? "%d, " : "%d}", f->no[i]);
    }
}
