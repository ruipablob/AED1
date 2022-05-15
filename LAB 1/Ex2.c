#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    int x,y;
    float dist;
    printf("Entre com a cordenada x:\n");
    scanf("%d", &x);
    printf("Entre com a cordenada y:\n");
    scanf("%d", &y);
    dist = sqrt(pow((x),2)+pow((y),2));
    printf("A distancia entre os pontos(%d,%d) e (0,0) eh %.1f", x,y,dist);
return 0;
}