#include<stdio.h>
#include "ponto.h"

int main(){
    Ponto *p1, *p2;
    int x,y,x1,y1;
    float resultado;

    p1 = gera_pto();
    p2 = gera_pto();

    if(p1 == NULL || p2 == NULL){
        printf("Não foi possivel criar os pontos");
        return -1;
    }

    printf("Digite o a coordenada do primeiro pronto p1(X,Y):\n");
    scanf("%d", &x);
    scanf("%d", &y);

    

    printf("Digite o a coordenada do primeiro pronto p2(X,Y):\n");
    scanf("%d", &x1);
    scanf("%d", &y1);

    set_pto(p1,x,y);
    set_pto(p2,x1,y1);

    resultado = distancia_pto(p1,p2);

    printf("A distancia entre o ponto p1(%d,%d) e p2(%d,%d) eh:\n%0.2f", x,y,x1,y1, resultado);

    libera_pto(&p1);
    libera_pto(&p2);


    return 0;
}