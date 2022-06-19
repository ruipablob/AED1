#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "lista-bebidas-din-enc.h"

struct bebidas
{
    char nome[20];
    int volume;
    float preco;
};
struct no{
    struct bebidas b;
    struct no * prox; 
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

int insere_elem(Lista *lst, char *nome, int volume, float preco){
    Lista N = (Lista) malloc(sizeof(struct no));
    if(N == NULL){
        return 0;
    }
    strcpy(N->b.nome,nome);
    N->b.preco = preco;
    N->b.volume = volume;
    N->prox = *lst;

    *lst = N;
    return 1;
}
int remove_elem(Lista *lst, char *nome){
    if(lista_vazia(*lst) == 1)
        return 0;
    Lista aux = *lst;

    if(strcmp((*lst)->b.nome,nome) == 0){
        *lst = aux->prox;
        free(aux);
        return 1;
    }
    while(aux->prox != NULL && strcmp(aux->prox->b.nome,nome) < 0)
        aux = aux->prox;
    if(aux->prox == NULL)
        return 0;
    
    Lista aux2 = aux->prox;
    aux->prox = aux2->prox;
    free(aux2);
    return 1;
}

void imprime(Lista lst){
    if(lista_vazia(lst) == 1){
        printf("Lista Vazia!");
    }
    for(lst;lst!=NULL;lst=lst->prox){
        printf("Bebida: %s\n", lst->b.nome);
        printf("Volume: %d\n", lst->b.volume);
        printf("Preco: %.2f\n", lst->b.preco);
        printf("\n");
    }
}