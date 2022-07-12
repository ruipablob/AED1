#include <stdlib.h>
#include <stdio.h>
#include "est_seq_ord.h"
#define MAX 5

struct lista{
    int no[MAX];
    int fim;
};

Lista cria_lista(){
    Lista lst;
    lst = (Lista)malloc(sizeof(struct lista));
    if(lst != NULL)
        lst->fim = 0;
    return lst;
}

int lista_vazia(Lista lst){
    if(lst->fim == 0){
        return 1;
    }else{
        return 0;
    }
}

int lista_cheia(Lista lst){
    if(lst -> fim == MAX){
        return 1;
    }else{
        return 0;
    }
}

int insere_elem(Lista lst, int elem){
    if(lista_cheia(lst) == 1 || lst == NULL){
        return 0;
    }
    if(lista_vazia(lst) == 1 || elem >= lst->no[lst->fim-1]){
        lst->no[lst->fim] = elem;
    }else{
        int i, aux = 0;
        while (elem >= lst->no[aux])
            aux++;
        for(i = lst->fim;i > aux; i--)
            lst->no[i] = lst->no[i-1];
        lst->no[aux] = elem;
        
    }
    lst->fim++;
    return 1;
}

int remove_elem(Lista lst, int elem){
    if(lista_vazia(lst) == 1 || lst == NULL || elem < lst->no[0] || elem > lst->no[lst->fim-1]){
        return 0;
    }
    int i,aux = 0;
    while(aux < lst->fim && lst->no[aux] < elem)
        aux++;
    if(aux == lst->fim || lst->no[aux] > elem)
        return 0;
    for(i = aux+1; i < lst->fim;i++)
        lst->no[i-1] = lst->no[i];
    lst->fim--;
    return 1;
}

int remove_impares(Lista lst){ 
    if(lista_vazia(lst) == 1 || lst == NULL){
        return 0;
    }
    int i, aux = 0;
    while(aux < lst->fim ){
        while ((lst->no[aux]%2) == 0){
            if(aux == lst->fim && (lst->no[aux]%2) == 0)
                return 0;
            else
                aux++;
    }
        for(i = aux+1; i < lst->fim;i++)
            lst->no[i-1] = lst->no[i];
        lst->fim--;
    }
    return 1;
}

int menor(Lista lst){
    if(lista_vazia(lst) == 1 || lst == NULL){
        return 0;
    }
    int i, menor;
    if(tamanho(lst) == 1){
        menor = lst->no[0];
    }else{
        menor = lst->no[0];
        for(i = 0; i < lst->fim;i++){
            if(lst->no[i] < menor)
                menor = lst->no[i];
        }
        
    }
    return menor;  
}

int tamanho(Lista lst){ 
    if(lista_vazia(lst) == 1 || lst == NULL){
        return 0;
    }
    int i, aux = 0;
    while(aux < lst->fim)
        aux++;
    return aux;
}

int concatena(Lista lst, Lista lst1){ //ERRO
    if(lista_vazia(lst) == 1 || lst == NULL && lista_vazia(lst1) == 1 && lst1 == NULL){
        return 0;
    }
    if(lista_vazia(lst) == 1 && lista_cheia(lst1) == 1){
        return 0;
    }
    if(lista_vazia(lst1) == 1 && lista_cheia(lst) == 1){
        return 0;
    }else{
        Lista concat;
        concat->no[MAX*2];
        for(int i = 0; i < lst->fim;i++){
            for(int j = 0; j < concat -> fim; j++){
                concat->no[j] = lst->no[i];
            }
        }
        int tam = tamanho(concat);
        for(int i = 0; i < lst1->fim;i++){
            for(int j = tam; j < concat->fim;j++){
                concat->no[j] = lst1->no[i];
            }
        }
        return 1;
    }

}

void imprime(Lista lst){
    if(lista_vazia(lst) == 1 || lst == NULL){
        printf("Lista vazia \n");
    }
    for(int i = 0; i < lst->fim;i++){
        printf("%d ", lst->no[i]);
    }
}