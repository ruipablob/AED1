#include<stdio.h>
#include<stdlib.h>
#include"no-cab-din-enc-nord.h"

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
int insere_elem(Lista lst, int elem){
    //Aloca novo nó
    Lista N = (Lista) malloc(sizeof(struct no));
    if(N == NULL){return 0;}//falha nó não alocado
    //preenche os campos do novo nó
    N->info = elem;
    N->prox = lst->prox;
    lst->prox = N;
    lst->info++;
    return 1;
}
int remove_elem(Lista *lst, int elem){
    if(lista_vazia(*lst) == 1)
        return 0;//falha
    Lista aux = *lst;//ponteiro auxiliar para no cabeçalho
    // //Trata elemento = 1º no da lista
    // if(elem == (*lst)->info){
    //     *lst = aux->prox;//Lista aponta para o 2º no
    //     free(aux);//Libera memoria alocada
    //     return 1;
    // }
    //percorrimento até achar o elem ou final da lista
    while (aux->prox != NULL && aux->prox->info != elem)
    {
        aux = aux->prox;
    if(aux->prox == NULL)//Trata final de lista
        return 0;//falha
    //Remove elemento ≠ 1º nó da lista
    Lista aux2 = aux->prox;//aponta nó a ser removido
    aux->prox = aux2->prox;//retira no da lista
    free(aux2);//Libera memória alocada
    (*lst)->info--;//Opcional: Decrementa qtde de nós na lista
    return 1;
    }
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