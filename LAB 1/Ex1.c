#include<stdio.h>
#include<stdlib.h>

int main(){
    float x, y, z, premio;
    printf("Apostador 1:\n");
    scanf("%f", &x);
    printf("Apostador 2:\n");
    scanf("%f", &y);
    printf("Apostador 3:\n");
    scanf("%f", &z);
    printf("Valor da Premiacao:\n");
    scanf("%f", &premio);
    
    printf("O jogador 1 recebera: %.2f\n", (premio/(x+y+z)*x));
    printf("O jogador 1 recebera: %.2f\n", (premio/(x+y+z)*y));
    printf("O jogador 1 recebera: %.2f\n", (premio/(x+y+z)*z));
return 0;
}

