#include<stdio.h>
#include<stdlib.h>

int main(){
    float soma = 0, n[5];
    float dPadrao = 0, media=0;
    //LEIURA DOS NUMEROS
    for(int i = 0; i<5; i++){
        printf("Digite o valor %d\n", i+1);
        scanf("%f", &n[i]);
    }
    //CALC MEDIA
    for(int i = 0; i<5; i++){
        soma = soma+(n[i]);
    }
    media = soma/5;

    //DESVIO PADRAO
    for(int i = 0; i<5; i++){
        dPadrao = dPadrao + pow((n[i]-media),2);

    }
    printf("%f\n", dPadrao);
    dPadrao = sqrt((dPadrao)/4.0);
    printf("A media eh %f e o desvio padrao eh %f\n",media, dPadrao);

return 0;
}
