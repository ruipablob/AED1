#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha-est-seq.h"
#define max 20

struct pilha
{
    int no[max];
    int topo;
};

// Cria pilha
Pilha cria_pilha()
{
    Pilha p;
    p = (Pilha)malloc(sizeof(struct pilha));
    if (p != NULL)
        p->topo = -1;
    return p;
}

// Pilha vazia
int pilha_vazia(Pilha p)
{
    if (p->topo == -1)
        return 1; // vazia
    else
        return 0; // contem elementos
}

// Pilha cheia
int pilha_cheia(Pilha p)
{
    if (p->topo == max - 1)
        return 1; // cheia
    else
        return 0; // nao cheia
}

// Empilha
int push(Pilha p, int elem)
{
    if (p == NULL || pilha_cheia(p) == 1)
        return 0;
    // insere elemento no topo
    p->topo++;
    p->no[p->topo] = elem;
    return 1;
}

// Desempilha
int pop(Pilha p, int *elem)
{
    if (p == NULL || pilha_vazia(p) == 1)
        return 0;
    *elem = p->no[p->topo]; // retorna elemento
    p->topo--;              // remove o elemento do topo
    return 1;
}

// Lê topo
int le_topo(Pilha p, int *elem)
{
    if (p == NULL || pilha_vazia(p) == 1)
        return 0;
    *elem = p->no[p->topo]; // retorna elemento
    return 1;
}

// Imprime Pilha
void imprime(Pilha p)
{
    if (pilha_vazia(p))
        printf("\nErro ao imprimir!!\n");
    int i = 0;
    printf("Pilha : {");
    while (i <= p->topo)
    {
        printf((i < p->topo) ? "%d, " : "%d}", p->no[i]);
        i++;
    }
}

// Imprime Reversa
void imprime_reversa(Pilha p)
{
    if (p == NULL || pilha_vazia(p) == 1)
        printf("Erro ao imprimir!");
    int i;
    for (i = p->topo; i >= 0; i--)
        printf("%d ", p->no[i]);
}

// Libera todos elementos da Pilha
int liberar(Pilha p)
{
    if (p == NULL || pilha_vazia(p) == 1)
        return 0;
    int elem;
    while (pilha_vazia(p) == 0)
    {
        p->topo--;
    }
    return 1;
}

// Verifica se é Palindromo(PALAVRA)
int palindromo(char vet[])
{
    int tamanho, meio, elem;
    int i;
    Pilha p;
    p = cria_pilha();
    tamanho = strlen(vet);
    meio = tamanho / 2;
    for (i = 0; i < meio; i++)
        push(p, vet[i]);
    if (tamanho % 2 == 0)
        i = i;
    else
        i++;
    while (vet[i] != '\0')
    {
        pop(p, &elem);
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
    int elemAux, i;
    while (i <= p->topo){
        push(aux, p->topo);
    }
    while (i <= aux->topo && aux->topo != elem){
        push(aux2, aux->topo);
        pop(aux, &elemAux);
    }
    if(aux == NULL)
        return 0;
    else{
        return 1;
    }
    
}

// elimina elemento(ERRO EM REMOVER ELEM Q NAO PERTENCE A PILHA)
int elimina(Pilha p, int elem)
{
    if (p == NULL || pilha_vazia(p) == 1)
        return 0;
    Pilha aux = cria_pilha();
    int i = 0, j = 0;
    for (i = 0; i <= p->topo; i++)
    {
        if (p->no[i] == elem)
            j = 1;
    }
    if (j == 1)
    {
        while (p->no[p->topo] != elem)
        {
            push(aux, p->no[p->topo]);
            pop(p, &p->no[p->topo]);
        }
        p->topo--;
        for (i = aux->topo; i >= 0; i--)
        {
            push(p, aux->no[i]);
        }
        return 1;
    }
    else
    {
        return 0;
    }
}

// Pares e impares
void pares_e_impares(Pilha p)
{
    Pilha par, impar;
    par = cria_pilha();
    impar = cria_pilha();
    int i = 0;
    for (i = 0; i <= p->topo; i++)
    {
        if (p->no[i] % 2 == 0)
            push(par, p->no[i]);
        else
            push(impar, p->no[i]);
    }

    printf("\nNUMEROS PARES:\n");
    imprime(par);
    printf("\nNUMEROS IMPARES:\n");
    imprime(impar);
}