#include <stdio.h>
#include <stdlib.h>
#include "fila-din-encad-simples.h"

int main()
{
    Fila f;
    int elem;
    int op, x = 0;
    do
    {
        do
        {
            printf(" \n--- Fila Dinamica ENCADIAMENTO SIMPLES --- \n\n");
            printf(" Escolha uma opcao\n");
            printf(" 1. Criar fila\n");
            printf(" 2. Verificar fila vazia\n");
            printf(" 3. Inserir elemento no Final\n");
            printf(" 4. Remover inicio\n");
            printf(" 5. Imprime fila\n");
            printf(" 6. SAIR\n");
            printf(" Opcao: ");
            scanf("%d", &op);
            if ((op < 1) || (op > 6))
            {
                printf("\n\n Opcao Invalida! Tente novamente...");
            }
        } while ((op < 1) || (op > 6));

        switch (op)
        {
            // inicializa a fila
        case 1:
            if (x == 1)
            {
                printf("Fila ja criada! \n");
            }
            else
            {
                f = cria_fila();
                if (f != NULL)
                {
                    printf("\nFila criada!!\n");
                    x = 1;
                }
                else
                    printf("\nERRO ao criar fila!!\n");
            }
            break;

            // Verifica se fila está vazia
        case 2:
            if (x != 1)
            {
                printf("Fila nao criada! \n");
            }
            else
            {
                if (fila_vazia(f))
                    printf("\nA Fila esta vazia!!\n");
                else
                    printf("\nA Fila contem elementos!!\n");
            }
            break;

            // Insere elemento no final da fila
        case 3:
            if (x != 1)
            {
                printf("Fila nao criada! \n");
            }
            else
            {
                printf("Digite o elemento a ser inserido:\n");
                scanf("%d", &elem);
                if (insere_fim(f, elem))
                    printf("\nelemento inserido com sucesso!\n");
                else
                    printf("\nErro ao inserir elemento");
            }
            break;

            // Remove elemento no inicio da fila
        case 4:
            if (x != 1)
            {
                printf("Fila nao criada! \n");
            }
            else
            {
                if (remove_ini(f, &elem) == 1)
                    printf("\nElemento removido com sucesso!\nO elemento removido foi %d\n", elem);
                else
                    printf("\nErro ao remover elemento");
            }
            break;

            // Imprime fila
        case 5:
            if (x != 1)
                printf("Fila nao criada! \n");
            else
                imprime(f);
            break;
        default:
            printf("\n\n FINALIZADO!");
        }
    } while (op != 6);

    return 0;
}