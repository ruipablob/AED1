#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "ponto.h"

struct ponto
{
    float x,y;
};

// gera_pto: cria uma instância de um ponto sem valores;
Ponto * gera_pto(){
    Ponto *p;
    p = (Ponto *) malloc(sizeof(Ponto));
    return p;
}
// set_pto: atribui os valores das coordenadas x e y de um ponto;
float set_pto(Ponto *p, float N1, float N2){
    if(p == NULL)
        return 0; //erro
    
    p->x = N1;
    p->y = N1;

    return 1; //sucesso
}
// get_pto: retorna os valores das coordenadas x e y de um ponto;
float get_pto(Ponto *p,float *N1, float *N2){
    if(p == NULL)
        return 0; //erro
    
    *N1 = p->x;
    *N2 = p->y;

    return 1; //sucesso
}
// libera_pto: operação que elimina um ponto criado;
void libera_pto(Ponto **p){
    free(*p);
    *p = NULL;
}
// distancia_pto: calcula a distância entre dois pontos;
float distancia_pto(Ponto *p1, Ponto *p2){
    float result;
    result = sqrt(pow((p2->x) - (p1->x),2) + pow((p2->y) - (p1->x),2));
    return result;
}

