#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha-din-enc.h"
#define max 20

struct no
{
    int info;
    struct no *prox;
};

// Cria pilha
Pilha cria_pilha()
{
    return NULL;
}

// Pilha vazia
int pilha_vazia(Pilha p)
{
    if (p == NULL)
        return 1;
    else
        return 0;
}

// Empilha
int push(Pilha *p, int elem)
{
    Pilha N = (Pilha)malloc(sizeof(struct no));
    if (N == NULL)
        return 0;
    N->info = elem;
    N->prox = *p;
    *p = N;
    return 1;
}

// Desempilha
int pop(Pilha *p, int *elem)
{
    if (pilha_vazia(*p) == 1)
        return 0;
    Pilha aux = *p;
    *elem = aux->info;
    *p = aux->prox;
    free(aux);
    return 1;
}

// Lê topo
int le_topo(Pilha *p, int *elem)
{
    if (pilha_vazia(*p) == 1)
        return 0;
    *elem = (*p)->info;
    return 1;
}

// Imprime
void imprime(Pilha p)
{
    if (pilha_vazia(p))
        printf("\nPilha vazia!!\n");
    printf("Pilha : {");
    while (p != NULL)
    {
        printf((p->prox != NULL) ? "%d, " : "%d}", p->info);
        p = p->prox;
    }
}

// Imprime reverso
void imprime_reversa(Pilha p)
{
    if (pilha_vazia(p) == 1 || p != NULL)
        printf("Erro ao imprimir! ");
    if (p == NULL)
        return;
    imprime_reversa(p->prox);
    printf("%d ", p->info);
}

// Libera pilha
int liberar(Pilha *p)
{
    if (pilha_vazia(*p) == 1)
        return 0;
    int elem;
    while (pilha_vazia(*p) != 1)
        pop(p, &elem);
    return 1;
}

// Verifica se é palindromo
int palindromo(char *vet)
{
    int tamanho, meio, elem;
    int i;
    Pilha p;
    p = cria_pilha();
    tamanho = strlen(vet);
    meio = tamanho / 2;
    for (i = 0; i < meio; i++)
        push(&p, vet[i]);
    if (tamanho % 2 == 0)
        i = i;
    else
        i++;
    while (vet[i] != '\0')
    {
        pop(&p, &elem);
        if (elem != vet[i])
            return 0;
        i++;
    }
    return 1;
}

int verifica_lista_elem(Pilha p,int elem){
    if (p == NULL || pilha_vazia(p) == 1)
        return 0;
    Pilha aux = cria_pilha();
    Pilha aux2 = cria_pilha();
    int elemAux;
    for(p; p != NULL; p = p->prox){
        push(&aux, p->info);
    }
    while(aux != NULL && aux->info != elem){
        push(&aux2, aux->info);
        pop(&aux, &elemAux);
    }
    if(aux == NULL)
        return 0;
    else{
        return 1;
    }
    
}

int elimina(Pilha *p, int elem)
{
    int elemAux, j = 0;
    if ((*p) == NULL || pilha_vazia(*p) == 1)
        return 0;
    Pilha aux = cria_pilha();
    if (verifica_lista_elem((*p),elem) == 1)
    {
        while ((*p)->info != elem)
        {
            push(&aux, (*p)->info);
            pop(&(*p), &elemAux);
        }
        pop(&(*p), &elemAux);
        for (aux; aux != NULL; aux = aux->prox)
        {
            push(&(*p), aux->info);
        }
        return 1;
    }
    else
    {
        return 0;
    }
}

// Retorna os pares e impares
void pares_e_impares(Pilha p)
{
    Pilha par = cria_pilha();
    Pilha impar = cria_pilha();
    int i = 0, j = 0;
    for (p; p != NULL; p = p->prox)
    {
        if (p->info % 2 == 0)
            push(&par, p->info);
        else
            push(&impar, p->info);
    }
    printf("NUMEROS PARES:\n");
    imprime(par);
    printf("\n");
    printf("NUMEROS impares:\n");
    imprime(impar);
}