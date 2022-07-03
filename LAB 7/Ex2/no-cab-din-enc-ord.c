#include<stdio.h>
#include<stdlib.h>
#include"no-cab-din-enc-ord.h"

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
    //Aloca novo nó
    Lista N = (Lista) malloc(sizeof(struct no));
    if(N == NULL){return 0;}//falha nó não alocado
    N->info = elem;//insere o conteudo (valor do elem)
    Lista aux = *lst; //Faz aux apontar para o cabeçalho
    while (aux->prox != NULL && aux->prox->info < elem)
        aux = aux->prox;//avança
    //insere o novo nó na lista
    N->prox = aux->prox;
    aux->prox = N;
    (*lst)->info++;
    return 1;
}
int remove_ord(Lista *lst, int elem){
    if(lista_vazia(*lst) == 1)
        return 0;//falha
    Lista aux = *lst;//ponterio auxiliar para o nó cabeçalho
    //percorrimento até final de lista, achar elem ou nó maior
    while (aux->prox != NULL && aux->prox->info < elem)
        aux = aux->prox;
    if(aux->prox == NULL || aux->prox->info > elem)
        return 0;//falha
    //Remove elemento ≠ 1º nó da lista
    Lista aux2 = aux->prox;//aponta nó a ser removido
    aux->prox = aux2->prox;//retira no da lista
    free(aux2);//Libera memória alocada
    (*lst)->info--;//Opcional: Decrementa qtde de nós na lista
    return 1;
}
void imprime(Lista lst){
    int i = 0,cont=0;
    if(lista_vazia(lst)==1){
        printf("\nNao ha elementos na lista\n");
    }else
        for(lst;lst!=NULL;lst=lst->prox){
        printf(i == 0 ? ""  : "list[%d] = %d\t", cont-1, lst->info );
        i++;
        cont++;
    }
}