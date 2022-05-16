#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(){
    int m[6][6] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,36,35,36};
    int opcao,soma=0;
    for(int i=0; i<6; i++){
        for(int j=0; j<6; j++){
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }

    printf("escolha opcao de 1 a 8:\n");
    scanf("%d",&opcao);

    switch (opcao)
    {
    case 1:
        for(int i=0; i<6; i++){
            for(int j=i+1;j<6;j++){
                printf("%d\t", m[i][j]);
                soma = soma + m[i][j];
            }
            printf("\n");
    }
    printf("\nSoma: %d", soma);
    break;

    case 2:
        for(int i=0; i<6; i++){
            for(int j=0;j<6;j++){
                if(i+j<=4){
                printf("%d\t", m[i][j]);
                soma = soma + m[i][j];
                }
            }
            printf("\n");
    }
    printf("\nSoma: %d", soma);
    break;

    case 4:
        for(int i=0; i<6; i++){
            for(int j=0;j<6;j++){
                if(((i>0 && i<5) && (j==0 || j == 1) && i!=j && i+j!=5)){
                printf("%d\t", m[i][j]);
                soma = soma + m[i][j];
                }
            }
        }
            printf("\nSoma: %d", soma);
            break;            
    }
return 0;
}