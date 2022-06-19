#include<stdio.h>
#include<stdlib.h>
#include "lista-linear-nord.h"

#define max 10

struct lista
{
    int no[max];
    int Fim;
};

//criar_lista
Lista*  cria_lista(){
    Lista *lst;
    lst = (Lista*) malloc(sizeof(struct lista));

    if(lst != NULL)
        lst->Fim = 0;//Lista vazia
    
    return lst;
}

//lista_vazia
int lista_vazia(Lista* lst){
    if(lst->Fim == 0)
        return 1;//lista vazia
    else
        return 0;//lista NÃO vazia
}

//lista_cheia
int lista_cheia(Lista* lst){
    if(lst->Fim == max)
        return 1; //Lista cheia
    else
        return 0; //Lista NÃO cheia
}

//insere_elem
int insere_elem(Lista* lst, int elem){
    if (lst == NULL || lista_cheia(lst) == 1)
        return 0;
    
    lst->no[lst->Fim] = elem; //insere elemento
    lst->Fim++; //Avança o Fim
    return 1;
}

//remove_elem
int remove_elem(Lista* lst, int elem){
    if(lst == NULL || lista_vazia(lst) == 1)
        return 0; //Falha
    int i, Aux = 0;

    //Percorre ate achar o elem ou o final da lista
    while(Aux < lst->Fim && lst->no[Aux] != elem)
        Aux++;
    if(Aux == lst->Fim)
        return 0;
    //Deslocamento à esquerda do sucessor até o final da lista 
    for (i=Aux+1; i<lst->Fim; i++)
        lst->no[i-1] = lst->no[i];
    
    lst->Fim--;//Decremento do campo Fim
    return 1;//Sucesso
}
//imprimi_lista
void imprimi_lista(Lista* lst){
    if(lista_vazia(lst) == 0)
        for(int i=0; i<lst->Fim;i++)
            printf("Elemento [%d] = %d\n", i, lst->no[i]); 
}



