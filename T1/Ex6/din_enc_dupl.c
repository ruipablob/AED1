#include <stdio.h>
#include <stdlib.h>
#include "din_enc_dupl.h"

struct no{
    int info;
    struct no *prox;
    struct no *ant;
};

Lista cria_lista(){
    return NULL;
}

int lista_vazia(Lista lst){
    if(lst == NULL)
        return 1;
    else 
        return 0;
}

int insere_ord(Lista *lst, int elem){
    Lista N = (Lista)malloc(sizeof(struct no));
    if(N == NULL) {return 0;}
    N->info = elem;
    if (lista_vazia(*lst) || elem <= (*lst)->info)
    {
        N->prox = *lst;
        N->ant = NULL;
        *lst = N;
        return 1;
    }
    Lista aux = *lst;
    while (aux->prox != NULL && aux->prox->info < elem){
        aux = aux ->prox;
    }
    N->prox = aux->prox;
    aux->prox->ant = N;
    aux->ant = N->prox;
    aux->ant->prox = N;
    return 1; 
}

int remove_ord(Lista *lst,int elem){
    if(lista_vazia(*lst) == 1 || elem < (*lst)->info)
        return 0;
    Lista aux = *lst;
    if(elem == (*lst)->info){
        *lst = aux->prox;
        free(aux);
        return 1;
    }
    while(aux->prox != NULL && aux->prox->info < elem)
        aux = aux->prox;
    if(aux->prox == NULL || aux->prox->info > elem)
        return 0;
    Lista aux2 = aux->prox;
    aux->prox = aux2->prox;
    free(aux2);
    return 1;
}

void imprime(Lista lst){
    if(lista_vazia(lst) == 1)
        printf("Lista vazia! \n");
    for(lst; lst != NULL; lst = lst->prox)
        printf("%d ",lst->info);
}