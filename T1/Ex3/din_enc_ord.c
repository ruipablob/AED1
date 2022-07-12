#include <stdlib.h>
#include <stdio.h>
#include "din_enc_ord.h"

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

int insere_ord(Lista *lst, int elem){
    Lista N = (Lista)malloc(sizeof(struct no));
    if(N == NULL) {return 0;}
    N->info = elem;
    if (lista_vazia(*lst) || elem <= (*lst)->info)
    {
        N->prox = *lst;
        *lst = N;
        return 1;
    }
    Lista aux = *lst;
    while (aux->prox != NULL && aux->prox->info < elem){
        aux = aux ->prox;
    }
    N->prox = aux->prox;
    aux->prox = N;
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

int tamanho(Lista lst){
    Lista aux = lst;
    int tam = 0;
    while(aux != NULL){
        tam++;
        aux = aux->prox;
    }
    return tam;
}
double media(Lista lst){
    int tam = tamanho(lst);
    double med,soma = 0;
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

int intercala(Lista lst, Lista lst1){ //ERRO
    Lista N = cria_lista();
    if(lista_vazia(lst) == 1 && lista_vazia(lst1) == 1)
        return 0;
    while (lst != NULL){
        while(lst1 != NULL){
            N->info = lst->info;
            N->prox->info = lst1->info;
            lst->prox;
            lst1->prox;
        }
    }
    imprime(N);
    return 1;
}

int ret_impares(Lista lst){ 
    if(lista_vazia(lst) == 1)  
        return 0;
    for(lst; lst != NULL; lst = lst->prox){
            if(lst->info%2 != 0)
                printf("%d ",lst->info);            
        }
}

// void inverter(Lista lst){
//     if(lista_vazia(lst) == 1)
//         printf("Lista vazia! \n");
//     int tam = tamanho(lst),vet[tam], i = 0 ;
//     while(i < tam){
//         vet[i] = lst->info;
//         lst = lst->prox;
//         i++;
//         //printf("%d ",lst->info);
//     }
//     imprime(lst);
    
// }

// void inverter(Lista lst){
//     if(lista_vazia(lst) == 1)
//         printf("Lista vazia! \n");
//     Lista nova_lista = cria_lista();
//     Lista tmp = cria_lista();
//     while (lst != NULL){
//         tmp = lst;
//         lst = lst->prox;
//         tmp->prox = nova_lista;
//         nova_lista = tmp;
//     }
//     imprime(nova_lista);
// }


