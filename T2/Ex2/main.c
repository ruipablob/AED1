#include <stdio.h>
#include <stdlib.h>
#include "pilha-din-enc.h"

int main()
{
    Pilha p;
    int elem;
    int op;
    int x = 0;

    do
    {

        do
        {
            printf("\n\n---------- Pilha Dinamica Encadeada ---------- \n");
            printf("1. Cria Pilha\n");
            printf("2. Pilha vazia\n");
            printf("3. Insere elemento\n");
            printf("4. Remove elemento\n");
            printf("5. Le topo\n");
            printf("6. Imprime\n");
            printf("7. Imprimir reversa\n");
            printf("8. Remover todos os elementos da pilha\n");
            printf("9. Palindromo\n");
            printf("10. Elimina\n");
            printf("11. Pares e impares\n");
            printf("12. Sair\n");
            printf("Digite a opcao que deseja: \n");
            scanf("%d", &op);
            if ((op < 1) || (op > 12))
            {

                printf("\n\n Opcao Invalida! Tente novamente...");
            }
        } while ((op < 1) || (op > 12));

        switch (op)
        {
            // inicializa pilha
        case 1:
            if (x == 1)
            {
                printf("\nPilha ja criada! \n");
            }
            else
            {
                p = cria_pilha();
                if (p == NULL)
                {
                    printf("\nPilha criada! \n");
                    x = 1;
                }
                else
                    printf("\nPilha nao criada");
            }
            break;

            // verifica se está vazia
        case 2:
            if (x != 1)
            {
                printf("\nPilha nao criada! \n");
            }
            else
            {
                if (pilha_vazia(p) == 1)
                    printf("\nPilha vazia! \n");
                else
                    printf("\nPilha nao esta vazia! \n");
            }
            break;

            // Empilha elemento(push)
        case 3:
            if (x != 1)
            {
                printf("\nPilha nao criada! \n");
            }
            else
            {
                printf("\nDigite o elemento que deseja inserir: \n");
                scanf("%d", &elem);
                if (push(&p, elem) == 1)
                    printf("\nElemento inserido! \n");
                else
                    printf("\nErro! Elemento nao inserido. \n");
            }
            break;

            // Desempilha(pop)
        case 4:
            if (x != 1)
            {
                printf("\nPilha nao criada! \n");
            }
            else
            {
                if (pop(&p, &elem) == 1)
                    printf("Elemento removido!\n O elemento removido foi: %d\n", elem);
                else
                    printf("\nErro! Elemento nao removido. \n");
            }
            break;

            // Retona elemento do topo
        case 5:
            if (x != 1)
            {
                printf("\nPilha nao criada! \n");
            }
            else
            {
                if (le_topo(&p, &elem) == 1)
                    printf("\nO elemento do topo eh: %d\n", elem);
                else
                    printf("\nERRO ao retornar elemento\n");
            }
            break;

            // Imprime Pilha
        case 6:
            if (x != 1)
                printf("\nPilha nao criada! \n");
            else
                imprime(p);
            break;

            // Imprime reverso
        case 7:
            if (x != 1)
                printf("\nPilha nao criada! \n");
            else
                imprime_reversa(p);
            break;

            // Libera Pilha
        case 8:
            if (x != 1)
            {
                printf("\nPilha nao criada! \n");
            }
            else
            {
                if (liberar(&p) == 1)
                    printf("\nPilha vazia! \n");
                else
                    printf("\nErro ao liberar a pilha! \n");
            }
            break;

            // Verifica palindromo
        case 9:
            char vet[20];
            printf("\nDigite a string que deseja verificar se e palindromo:\n");
            setbuf(stdin, NULL);
            gets(vet);
            if (palindromo(vet) == 1)
                printf("\nE Palindromo! \n");
            else
                printf("\nNao e Palindromo! \n");
            break;

            // Remove elemento
        case 10:
            if (x != 1)
            {
                printf("\nPilha nao criada! \n");
            }
            else
            {
                printf("\nDigite o numero que deseja remover: \n");
                scanf("%d", &elem);
                if (elimina(&p, elem) == 1)
                    printf("\nElemento removido! \n");
                else
                    printf("\nErro ao remover elemento! \n");
            }
            break;
            // Retorna pares e impares
        case 11:
            if (x != 1)
                printf("\nPilha nao criada! \n");
            else
                pares_e_impares(p);
            break;
        default:
            printf("\n\n FINALIZADO!\n");
        }
    } while (op != 12);

    return 0;
}