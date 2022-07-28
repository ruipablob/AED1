#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#define max 20

struct pilha
{
    int no[max];
    int topo;
};

Pilha cria_pilha()
{
    Pilha p;
    p = (Pilha)malloc(sizeof(struct pilha));
    if (p != NULL)
        p->topo = -1;
    return p;
}

int pilha_vazia(Pilha p)
{
    if (p->topo == -1)
        return 1;
    else
        return 0;
}

int pilha_cheia(Pilha p){
    if (p->topo == max - 1)
        return 1;
    else
        return 0;
}

int push(Pilha p, int elem){
    if(p == NULL || pilha_cheia(p) == 1)
        return 0;
    p->topo++;
    p->no[p->topo] = elem;
    return 1;
}

int pop(Pilha p, int *elem){
    if(p == NULL || pilha_vazia(p) == 1)
        return 0;
    *elem = p->no[p->topo];
    p->topo--;
    return 1;
}

int le_topo(Pilha p, int *elem){
    if(p == NULL || pilha_vazia(p) == 1)
        return 0;
    *elem = p->no[p->topo];
    return 1;
}

void imprime(Pilha p){
    if(pilha_vazia(p))
        printf("\nPilha vazia!!\n");
    int i = 0;
    printf("Pilha : {");
    while(i <= p->topo){
        printf((i < p->topo) ? "%d, " : "%d}", p->no[i]);
        i++;
    }
}