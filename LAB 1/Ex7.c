#include<stdio.h>
#include<stdlib.h>

int main(){
    int n = 10,r = 1, fatorial = 1;
    for(int i=10;i>0;i--){

        fatorial = fatorial * i;
    }
    printf("Fatorial de 10: ");
    printf("%d \n", fatorial);

    for(int i=15;i>10;i--){
        fatorial = fatorial * i;
        printf("%d ", fatorial);
    }
    //Deu erro pois estourou a quantidade permitida no inteiro.


return 0;
}
