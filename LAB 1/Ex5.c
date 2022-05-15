#include<stdio.h>
#include<stdlib.h>

int main(){
    int n, contador = 1, m = 0;
    scanf("%d", &n);
    for(int i =0; i<=n; i++){
        for(int j = 0; j<=m; j++){
            printf("%d ", contador);
            contador ++;
        }
        m++;
        printf("\n");
    }

return 0;
}

