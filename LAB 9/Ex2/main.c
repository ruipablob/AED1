#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main()
{
    Pilha p;
    int elem;
    int op;

    do
    {

        do
        {
            printf(" \n--- PILHA ESTATICA SEQUENCIAL --- \n\n");
            printf(" Escolha uma opcao\n");
            printf(" 1. Criar pilha\n");
            printf(" 2. Verificar pilha vazia\n");
            printf(" 3. Empilhar elemento (Push)\n");
            printf(" 4. Desempilhar elemento (Pop)\n");
            printf(" 5. Le topo\n");
            printf(" 6. Imprime Pilha\n");
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
        case 1:
            p = cria_pilha();
            if (p == NULL)
                printf("\nPilha criada!!\n");
            else
                printf("\nErro ao criar pilha!!\n");
            break;
        case 2:
            if (pilha_vazia(p))
                printf("\nA Pilha esta vazia!!\n");
            else
                printf("\nA Pilha contem elementos\n");
            break;
        case 3:
            printf("Digite o elemento que deseja inserir:\n");
            scanf("%d", &elem);
            if (push(&p, elem) == 1)
                printf("\nElemento inserido com sucesso!!\n");
            else
                printf("\nERRO ao inserir elemento!!\n");
            break;
        case 4:
            if (pop(&p, &elem) == 1)
                printf("\nElemento desempilhado com sucesso!!\nO elemento removido foi: %d\n", elem);
            else
                printf("\nERRO ao desempilhar elemento!!\n");
            break;
        case 5:
            if(le_topo(&p,&elem) == 1)
            printf("\nO elemento do topo eh: %d\n", elem);
            else
            printf("\nERRO ao retornar elemento\n");
            break;
        case 6:
            imprime(p);
            break;
        default:
            printf("\n\n FINALIZADO!");
        }
    } while (op != 7);

    return 0;
}