#include<stdio.h>
#include<stdlib.h>

int main(){
    char nome[10];
    setbuf(stdin, NULL);
    gets(nome);
    for(int i=0;i<strlen(nome);i++){
        printf("%c", toupper(nome[i]));
    }
return 0;
}