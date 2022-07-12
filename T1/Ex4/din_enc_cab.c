#include <stdlib.h>
#include <stdio.h>
#include "din_enc_cab.h"

struct no{
    int info;
    struct no *prox;
};

Lista cria_lista(){
    Lista cab;
    cab = (Lista)malloc(sizeof(struct no));
    if(cab != NULL){
        cab->prox = NULL;
        cab->info = 0;
    }
    return cab;
}

int lista_vazia(Lista lst){
    if(lst->prox == NULL)
        return 1;
    else
        return 0;
}

int insere_ord(Lista *lst, int elem){
    Lista N = (Lista)malloc(sizeof(struct no));
    if(N == NULL)
        return 0;
    N->info = elem;
    Lista aux = *lst;
    while(aux->prox != NULL && aux->prox->info < elem)
        aux = aux->prox;
    N->prox = aux->prox;
    aux->prox = N;
    (*lst)->info++;
    return 1;
}

int remove_ord(Lista *lst, int elem){
    Lista aux = *lst;
    while (aux->prox != NULL && aux->prox->info < elem)
        aux = aux->prox;
    if(aux->prox == NULL || aux->prox->info > elem)
        return 0;
    Lista aux2 = aux->prox;
    aux->prox = aux2->prox;
    free(aux2);
    (*lst)->info--;
    return 1;
}

void imprime(Lista lst){
    int i = 0;
    if (lista_vazia(lst) == 1){
        printf("Erro! Lista vazia! \n");
    }else{
        lst = lst->prox;
        for (lst;lst != NULL; lst = lst->prox){
            printf("%d \n", lst->info);
        }
    }
    
}

int tamanho(Lista lst){
    return lst->info;
}

double media(Lista lst){
    int tam = tamanho(lst);
    double med,soma = 0;
    lst = lst->prox;
    for(lst; lst != NULL; lst = lst->prox)
        soma = soma + lst->info;
    med = soma/tam;
    return med;
}

int iguais(Lista lst, Lista lst1){
    if(lista_vazia(lst) == 1 && lista_vazia(lst1) == 1)
        return -1;
    if(tamanho(lst) != tamanho(lst1))
        return 0;
    else{
        lst = lst->prox;
        lst1 = lst1->prox;
        while(lst != NULL){
            if(lst->info != lst1->info)
                return 0;
            else{
                lst = lst->prox;
                lst1 = lst1->prox;
            }
        }
        return 1;
    }
}

int ret_impares(Lista lst){ 
    if(lista_vazia(lst) == 1)  
        return 0;
    lst = lst->prox;
    for(lst; lst != NULL; lst = lst->prox){
            if(lst->info%2 != 0)
                printf("%d ",lst->info);            
        }
}
