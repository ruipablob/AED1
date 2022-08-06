#include <stdio.h>
#include <stdlib.h>
#include "fila-est-seq-circ.h"

int main()
{
    Fila f;
    int elem;
    int op;
    int x = 0;

    do
    {

        do
        {
            printf(" \n--- FILA ESTATICA SEQUENCIAL --- \n\n");
            printf(" Escolha uma opcao\n");
            printf(" 1. Criar fila\n");
            printf(" 2. Verificar fila vazia\n");
            printf(" 3. Verificar fila cheia\n");
            printf(" 4. Inserir elemento no Final\n");
            printf(" 5. Remover inicio\n");
            printf(" 6. Imprime fila\n");
            printf(" 7. SAIR\n");
            printf(" Opcao: ");
            scanf("%d", &op);
            if ((op < 1) || (op > 7))
            {

                printf("\n\n Opcao Invalida! Tente novamente...");
            }
        } while ((op < 1) || (op > 7));

        switch (op)
        {
            // Inicializa fila
        case 1:
            if (x == 1)
            {
                printf("Fila ja criada! \n");
            }
            else
            {
                f = inicializar_fila();
                if (f != NULL)
                {
                    printf("\nFila criada!!\n");
                    x = 1;
                }
                else
                    printf("\nERRO ao criar fila!!\n");
            }
            break;

            // Verifica se fila é vazia
        case 2:
            if (x != 1)
            {
                printf("Pilha nao criada! \n");
            }
            else
            {
                if (fila_vazia(f))
                    printf("\nA Fila esta vazia!!\n");
                else
                    printf("\nA Fila contem elementos!!\n");
            }
            break;

            // Verifica se fila é cheia
        case 3:
            if (x != 1)
            {
                printf("Pilha nao criada! \n");
            }
            else
            {
                if (fila_cheia(f))
                    printf("\nA Fila esta cheia!!\n");
                else
                    printf("\nA Fila nao esta cheia!!\n");
            }
            break;

            // Insere elemento na Fila
        case 4:
            if (x != 1)
            {
                printf("Pilha nao criada! \n");
            }
            else
            {
                if (f == NULL)
                    printf("\nFila nao criada!\n");
                else
                {
                    printf("Digite o elemento a ser inserido:\n");
                    scanf("%d", &elem);
                    if (insere_fila(f, elem))
                        printf("\nelemento inserido com sucesso!\n");
                    else
                        printf("\nErro ao inserir elemento");
                }
            }
            break;

            // Remove elemento do inicio da Fila
        case 5:
            if (x != 1)
            {
                printf("Pilha nao criada! \n");
            }
            else
            {
                if (remove_fila(f, &elem) == 1)
                    printf("\nElemento removido com sucesso!\nO elemento removido foi %d\n", elem);
                else
                    printf("\nErro ao remover elemento");
            }
            break;

            // Imprime fila do inicio para o final
        case 6:
            if (x != 1)
                printf("Pilha nao criada! \n");
            else
                imprime(f);
            break;
        default:
            printf("\n\n FINALIZADO!");
        }
    } while (op != 7);

    return 0;
}