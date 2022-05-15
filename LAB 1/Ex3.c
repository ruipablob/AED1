#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    int x0,x1,x3,x2;
    int dec;
    printf("Digite o 1o. bit:\n");
    scanf("%d",&x0);
    printf("Digite o 2o. bit:\n");
    scanf("%d",&x1);
    printf("Digite o 3o. bit:\n");
    scanf("%d",&x2);
    printf("Digite o 4o. bit:\n");
    scanf("%d",&x3);

    dec = pow((x0 * 2),3)+((x0 * 2),2)+((x0 * 2),1)+((x0 * 2),0);
    printf("O numero binario %c%c%c%c corresponde ao numero decimal %d.",x0,x1,x2,x3,dec);
return 0;
}