#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "bebidas-est-seq.h"

#define max 10

struct bebidas
{
    char nome[20];
    int volume;
    float preco;
};
struct lista
{
    int Fim;
    struct bebidas b[max];
};

Lista  cria_lista(){
    Lista lst;
    lst = (Lista) malloc(sizeof(struct lista));

    if(lst != NULL)
        lst->Fim = 0;//Lista vazia
    
    return lst;
}

//lista_vazia
int lista_vazia(Lista lst){
    if(lst->Fim == 0)
        return 1;//lista vazia
    else
        return 0;//lista NÃO vazia
}

//lista_cheia
int lista_cheia(Lista lst){
    if(lst->Fim == max)
        return 1; //Lista cheia
    else
        return 0; //Lista NÃO cheia
}

//insere_elem
int insere_elem(Lista lst, char *nome, int volume, float preco){
    struct bebidas elem;
    strcpy(elem.nome,nome);
    elem.volume = volume;
    elem.preco = preco;
    if (lst == NULL || lista_cheia(lst) == 1)
        return 0;
    lst->b[lst->Fim] = elem;
    lst->Fim++; //Avança o Fim
    return 1;
}

//remove_elem
int remove_elem(Lista lst, char *nome){
    if(lst == NULL || lista_vazia(lst) == 1)
        return 0; //Falha
    int i, Aux = 0;

    //Percorre ate achar o elem ou o final da lista
    while(Aux < lst->Fim && strcmp(lst->b[Aux].nome, nome))
        Aux++;
    if(Aux == lst->Fim)
        return 0;
    //Deslocamento à esquerda do sucessor até o final da lista 
    for (i=Aux+1; i<lst->Fim; i++)
        strcpy(lst->b[i-1].nome, lst->b[i].nome);
    
    lst->Fim--;//Decremento do campo Fim
    return 1;//Sucesso
}
//imprimi_lista
void imprime_lista(Lista lst){
    if(lista_vazia(lst) == 0)
        for(int i=0; i<lst->Fim;i++){
        printf("Bebida: %s\n", lst->b[i].nome);
        printf("Volume: %d\n", lst->b[i].volume);
        printf("Preco: %.2f\n", lst->b[i].preco);
        printf("\n");
    }
}
