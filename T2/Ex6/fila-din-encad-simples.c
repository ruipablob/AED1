#include <stdio.h>
#include <stdlib.h>
#include "fila-din-encad-simples.h"

struct no
{
    int info;
    struct no *prox;
};
struct fila
{
    struct no *ini;
    struct no *fim;
};

// Cria fila
Fila cria_fila()
{
    Fila f;
    f = (Fila)malloc(sizeof(struct fila));
    if (f != NULL)
    {
        f->ini = NULL;
        f->fim = NULL;
    }
    return f;
}

// Verifica se fila está vazia
int fila_vazia(Fila f)
{
    if (f->ini == NULL)
        return 1;
    else
        return 0;
}

// Insere elemento no final da fila
int insere_fim(Fila f, int elem)
{
    struct no *N;
    N = (struct no *)malloc(sizeof(struct no));
    if (N == NULL)
        return 0;
    N->info = elem; // preenche campo info
    N->prox = NULL; // preenche campo prox
    if (fila_vazia(f) == 1)
        f->ini = N; // se a fila for vazia
    else
        (f->fim)->prox = N; // se fila conter elementos
    f->fim = N;             // campo dim aponta para N
    return 1;
}

// Remmove elemento do inicio da fila
int remove_ini(Fila f, int *elem)
{
    if (fila_vazia(f) == 1)
        return 0;
    struct no *aux = f->ini; // Aux aponta para o 1º no
    *elem = aux->info;       // Retorna valor do elemento

    // Verifica se a fila tem um unico nó
    if (f->ini == f->fim)
        f->fim = NULL;

    f->ini = aux->prox; // Retira 1º nó da fila
    free(aux);          // Libera a memoria alocada
    return 1;
}

// Imprime fila
void imprime(Fila f)
{
    if (fila_vazia(f) == 1)
        printf("\nERRO\n");
    struct no *aux = f->ini;

    while (aux != NULL)
    {
        printf("%d ", aux->info);
        aux = aux->prox;
    }
}