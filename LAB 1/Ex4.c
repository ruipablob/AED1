#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    float massa, altura,IMC;

    printf("Digite o peso:\n");
    scanf("%f", &massa);
    printf("Digite a altura:\n");
    scanf("%f", &altura);
    
    IMC = massa / pow(altura,2);
    printf("Valor do IMC:\n %.2f", IMC);

    if(IMC < 18.5){
        printf("Magreza");
    }else if(IMC>18.5 && IMC<=24.9){
        printf("Saudavel");
    }else if(IMC>=25.0 && IMC<29.9){
        printf("Sobrepeso");
    }else if(IMC>=30.0 && IMC<=34.9){
        printf("Obesidade Grau I");
    }else if(IMC>=35.0 && IMC<=39.9){
        printf("Obesidade Grau II (severa)");
    } else printf("Obesidade Grau III (morbida)");

return 0;
}