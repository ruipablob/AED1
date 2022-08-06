#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha-est-seq.h"

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
            printf(" \n--- PILHA ESTATICA SEQUENCIAL ---\n\n");
            printf(" Escolha uma opcao\n");
            printf(" 1. Criar pilha\n");
            printf(" 2. Verificar pilha vazia\n");
            printf(" 3. Verificar pilha cheia\n");
            printf(" 4. Empilhar elemento (Push)\n");
            printf(" 5. Desempilhar elemento (Pop)\n");
            printf(" 6. Le topo\n");
            printf(" 7. Imprime Pilha\n");
            printf(" 8. Imprime reversa\n");
            printf(" 9. Libera Pilha\n");
            printf(" 10. Verifica se eh palindromo\n");
            printf(" 11. Elimina elemento\n");
            printf(" 12. Pares e impares\n");
            printf(" 13. SAIR\n");
            printf(" Opcao: ");
            scanf("%d", &op);
            if ((op < 1) || (op > 13))
            {

                printf("\n\n Opcao Invalida! Tente novamente...");
            }
        } while ((op < 1) || (op > 13));

        switch (op)
        {
            // inicializa pilha
        case 1:
            if (x == 1)
            {
                printf("Pilha ja criada! \n");
            }
            else
            {
                p = cria_pilha();
                if (p != NULL)
                {
                    printf("Pilha criada! \n");
                    x = 1;
                }
                else
                    printf("Pilha nao criada");
            }
            break;

            // verifica se está vazia
        case 2:
            if (x != 1)
            {
                printf("Pilha nao criada! \n");
            }
            else
            {
                if (pilha_vazia(p) == 1)
                    printf("Pilha vazia! \n");
                else
                    printf("Pilha nao esta vazia! \n");
            }
            break;

            // verifica se está cheia
        case 3:
            if (x != 1)
            {
                printf("Pilha nao criada! \n");
            }
            else
            {
                if (pilha_cheia(p) == 1)
                    printf("Pilha cheia! \n");
                else
                    printf("Pilha nao esta cheia! \n");
            }
            break;

            // Empilha elemento(push)
        case 4:
            if (x != 1)
            {
                printf("Pilha nao criada! \n");
            }
            else
            {
                printf("Digite o elemento que deseja inserir: \n");
                scanf("%d", &elem);
                if (push(p, elem) == 1)
                    printf("Elemento inserido! \n");
                else
                    printf("Erro! Elemento nao inserido. \n");
            }
            break;

            // Desempilha(pop)
        case 5:
            if (x != 1)
            {
                printf("Pilha nao criada! \n");
            }
            else
            {
                if (pop(p, &elem) == 1)
                    printf("Elemento removido! \n");
                else
                    printf("Erro! Elemento nao removido. \n");
            }
            break;

            // Retona elemento do topo
        case 6:
            if (x != 1)
            {
                printf("Pilha nao criada! \n");
            }
            else
            {
                if (le_topo(p, &elem) == 1)
                    printf("\nO elemento do topo eh: %d\n", elem);
                else
                    printf("\nERRO ao retornar elemento\n");
            }
            break;

            // Imprime Pilha
        case 7:
            if (x != 1)
                printf("Pilha nao criada! \n");
            else
                imprime(p);
            break;

            // Imprime Reversa
        case 8:
            if (x != 1)
                printf("Pilha nao criada! \n");
            else
                imprime_reversa(p);
            break;

            // Libera Pilha
        case 9:
            if (x != 1)
            {
                printf("Pilha nao criada! \n");
            }
            else
            {
                if (liberar(p) == 1)
                    printf("Pilha vazia! \n");
                else
                    printf("Erro ao liberar a pilha! \n");
            }
            break;

            // Verifica se é palindromo
        case 10:
            char vet[20];
            printf("Digite a string que deseja verificar se e palindromo: ");
            setbuf(stdin, NULL);
            gets(vet);
            if (palindromo(vet) == 1)
                printf("E Palindromo! \n");
            else
                printf("Nao e Palindromo! \n");
            break;

            // Elimina elemento
        case 11:
            if (x != 1)
            {
                printf("Pilha nao criada! \n");
            }
            else
            {
                printf("Digite o numero que deseja remover: \n");
                scanf("%d", &elem);
                if (elimina(p, elem) == 1)
                    printf("Elemento removido! \n");
                else
                    printf("Erro ao remover elemento! \n");
            }
            break;

            // Retorna pilha uma pilha somente com pares e uma com impares.
        case 12:
            if (x != 1)
                printf("Pilha nao criada! \n");
            else
                pares_e_impares(p);
            break;
        
        default:
            printf("\n\n FINALIZADO!");
        }
    } while (op != 14);

    return 0;
}