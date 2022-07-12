#include <stdio.h>
#include <stdlib.h>
#include "din_enc_cicl.h"

struct no{
    int info;
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

int insere_final(Lista *lst, int elem){
    Lista N = (Lista)malloc(sizeof(struct no));
    if(N == NULL)
        return 0;
    N->info = elem;
    if(lista_vazia(*lst) == 1){
        N->prox = N;
        *lst = N;
    }else{
        N->prox = (*lst)->prox;
        (*lst)->prox = N;
        *lst = N;
    }
    return 1;
}

int remove_inicio(Lista *lst, int *elem){
    if(lista_vazia(*lst) == 1)
        return 0;
    Lista aux = (*lst)->prox;
    *elem = aux->info;
    if(*lst == (*lst)->prox)
        *lst = NULL;
    else
        (*lst)->prox = aux->prox;
    free(aux);
    return 1;
}

int insere_inicio(Lista *lst, int elem){ //ERRO
    Lista N = (Lista)malloc(sizeof(struct no));
    if(N == NULL)
        return 0;
    N->info = elem;
    if(lista_vazia(*lst) == 1){
        N->prox = N;
        *lst = N;
    }
    return 1;
}

void imprime(Lista lst){ //ERRO MAS FUNCIONA
    Lista primeiro = lst;
    do{
        printf("%d\n", lst->info);
        lst = lst->prox;
    }while(lst != primeiro);
    printf("\n");
}

int tamanho(Lista lst){
    int tam = 0;
    if(lista_vazia(lst) == 1)
        return 0;
    Lista primeiro = lst;
    do
    {
        tam = tam+1;
        lst = lst->prox; 
    }while(lst != primeiro);
    return tam;
}

int maior(Lista lst){ //ERRO
    if(lista_vazia(lst) == 1)
        return 0;
    Lista primeiro = lst;
    while(lst != primeiro){
        if(lst->info > lst->prox->info)
            return lst->info;
        else
            return lst->prox->info;
        lst = lst->prox;
    }
}

int remove_pares(Lista *lst){
    int tam = tamanho(*lst);
    if(lista_vazia(*lst) == 1)
        return 0;
    if (tam == 1 && (*lst)->info % 2 == 0)
        *lst = NULL;
    // if((*lst)->info % 2 == 0)
    //     (*lst)->prox = aux->prox;
    //free(aux);
    imprime(*lst);
    return 1;
}

//int insere_pos(Lista *lst, int elem, int pos);
// int remove_pos(Lista *lst, int pos);
// int remove_pares(Lista *lst);


