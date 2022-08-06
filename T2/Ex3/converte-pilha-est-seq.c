#include <stdio.h>
#include <stdlib.h>
#include "converte-pilha-est-seq.h"
#define MAX 10

struct pilha
{
    int no[MAX];
    int topo;
};

// Cria pilha
Pilha cria_pilha()
{
    Pilha p;
    p = (Pilha)malloc(sizeof(struct pilha));
    if (p != NULL)
        p->topo = -1;
    return p;
}

// Pilha vazia
int pilha_vazia(Pilha p)
{
    if (p->topo == -1)
        return 1;
    else
        return 0;
}

// Pilha cheia(complemento)
int pilha_cheia(Pilha p)
{
    if (p->topo == MAX - 1)
        return 1;
    else
        return 0;
}

// Empilha(Complemento)
int push(Pilha p, int elem)
{
    if (p == NULL || pilha_cheia(p) == 1)
        return 0;
    p->topo++;
    p->no[p->topo] = elem;
    return 1;
}

// Desempilha(Complemento)
int pop(Pilha p, int *elem)
{
    if (p == NULL || pilha_vazia(p) == 1)
        return 0;
    *elem = p->no[p->topo];
    p->topo--;
    return 1;
}

// Libera pilha
int liberar(Pilha p)
{
    if (p == NULL || pilha_vazia(p) == 1)
        return 0;
    int elem;
    while (pilha_vazia(p) == 0)
    {
        p->topo--;
    }
    return 1;
}

// Imprime(Complemento)
void imprime(Pilha p)
{
    if (p == NULL || pilha_vazia(p) == 1)
        printf("Erro ao imprimir! \n");
    int i;
    for (i = 0; i <= p->topo; i++)
    {
        printf("%d ", p->no[i]);
    }
}

// Converte decimal para binario
void decimal_para_Binario(Pilha p, int elem)
{
    int div = elem;
    int resto;
    int elemAux;
    int inicial = elem;
    Pilha aux = cria_pilha();
    if (p == NULL)
    {
        printf("\nERRO!!\n");
    }
    while (div > 0)
    {
        resto = div % 2;
        push(aux, resto);
        div = div / 2;
    }
    while (pilha_vazia(aux) != 1)
    {
        push(p, aux->no[aux->topo]);
        pop(aux, &elemAux);
    }
    printf("\nO numero decimal %d para binario eh:\n", inicial);
    imprime(p);
}

// Converte decimal para octal
void decimal_para_octal(Pilha p, int elem)
{
    int div = elem;
    int resto;
    int elemAux;
    int inicial = elem;
    Pilha aux = cria_pilha();
    if (p == NULL)
    {
        printf("\nERRO!!\n");
    }
    while (div > 0)
    {
        resto = div % 8;
        push(aux, resto);
        div = div / 8;
    }
    while (pilha_vazia(aux) != 1)
    {
        push(p, aux->no[aux->topo]);
        pop(aux, &elemAux);
    }
    printf("\nO numero decimal %d para octal eh:\n", inicial);
    imprime(p);
}

// Converte decimal para hexadecimal
void decimal_para_hexadecimal(Pilha p, int elem)
{
    int div = elem;
    int resto;
    int elemAux;
    int inicial = elem;
    Pilha aux = cria_pilha();
    if (p == NULL)
    {
        printf("\nERRO!!\n");
    }
    while (div > 0)
    {
        resto = div % 16;
        if (resto == 10)
        {
            push(aux, 'A');
        }
        else if (resto == 11)
        {
            push(aux, 'B');
        }
        else if (resto == 12)
        {
            push(aux, 'C');
        }
        else if (resto == 13)
        {
            push(aux, 'D');
        }
        else if (resto == 14)
        {
            push(aux, 'E');
        }
        else if (resto == 15)
        {
            push(aux, 'F');
        }
        else
        {
            push(aux, resto);
        }
        div = div / 16;
    }
    while (pilha_vazia(aux) != 1)
    {
        push(p, aux->no[aux->topo]);
        pop(aux, &elemAux);
    }
    printf("\nEquivalencias numeros com letras: 65 = A, 66 = B, 67 = C, 68 = D, 69 = E, 70 = F. \n");
    printf("\nO numero decimal %d para octal eh:\n", inicial);
    imprime(p);
}
