#include <stdio.h>
#include <stdlib.h>
#include "fila-din-enc-circ.h"

struct no
{
    int info;
    struct no *prox;
};

// Cria fila
Fila cria_fila()
{
    return NULL;
}

//Verifica se a fila está vazia
int fila_vazia(Fila f)
{
    if (f == NULL)
        return 1;
    else
        return 0;
}

//Insere elemento no final da fila
int insere_fim(Fila *f, int elem)
{
    Fila N = (Fila)malloc(sizeof(struct no));
    if (N == NULL)
    {
        return 0;
    }
    N->info = elem;
    if (fila_vazia(*f) == 1)
    {
        N->prox = N;
        *f = N;
    }
    else
    {
        N->prox = (*f)->prox;
        (*f)->prox = N;
        *f = N;
    }
    return 1;
}


//Remove elemento no inicio da fila
int remove_ini(Fila *f, int *elem)
{
    if (fila_vazia(*f) == 1)
        return 0;
    Fila aux = (*f)->prox;
    *elem = aux->info;

    if (*f == (*f)->prox)
        *f = NULL;
    else
        (*f)->prox = aux->prox;
    free(aux);
    return 1;
}


//Imprime a fila
void imprime(Fila f)
{
    if (fila_vazia(f) == 1)
        printf("Erro ao imprimir! ");
    Fila primeiro = cria_fila();
    primeiro = f;
    f = f->prox;
    for (f; f != primeiro; f = f->prox)
        printf("%d ", f->info);
    printf("%d ", primeiro->info);
}