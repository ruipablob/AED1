#include <stdio.h>
#include <stdlib.h>
#include "converte-pilha-est-seq.h"

int main()
{
    Pilha p;
    int op, elem;
    int x = 0, y = 0;
    do
    {
        do
        {
            printf("\n\n---------- CONVERSOR Pilha Estatica Sequencial ---------- \n");

            printf("1 .Cria Pilha\n");
            printf("2. Pilha vazia\n");
            printf("3. Converter Decimal para Binario\n");
            printf("4. Converter Decimal para Octal\n");
            printf("5. Converter Decimal para Hexadecimal\n");
            printf("6. Liberar para nova consulta\n");
            printf("7. Sair\n");
            printf("Digite a opcao que deseja: \n");
            scanf("%d", &op);
            if ((op < 1) || (op > 7))
            {

                printf("Opcao Invalida! Tente novamente...\n");
            }
        } while ((op < 1) || (op > 7));
        switch (op)
        {
            // cria pilha
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
            // Verifica se está vazia
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
                break;
            }

            // Converde Decimal para binario
        case 3:
            if (x != 1)
            {
                printf("Pilha nao criada! \n");
            }
            else if (y == 1)
            {
                printf("Libere a pilha para fazer uma nova consulta! \n");
            }
            else
            {
                y = 1;
                printf("\nDigite o valor em decimal para ser convertido:\n");
                scanf("%d", &elem);
                decimal_para_Binario(p, elem);
            }
            break;

            // Converde Decimal para Octal
        case 4:
            if (x != 1)
            {
                printf("Pilha nao criada! \n");
            }
            else if (y == 1)
            {
                printf("Libere a pilha para fazer uma nova consulta! \n");
            }
            else
            {
                y = 1;
                printf("\nDigite o valor em decimal para ser convertido:\n");
                scanf("%d", &elem);
                decimal_para_octal(p, elem);
            }
            break;

            // Converde Decimal para Hexadecimal
        case 5:
            if (x != 1)
            {
                printf("Pilha nao criada! \n");
            }
            else if (y == 1)
            {
                printf("Libere a pilha para fazer uma nova consulta! \n");
            }
            else
            {
                y = 1;
                printf("\nDigite o valor em decimal para ser convertido:\n");
                scanf("%d", &elem);
                decimal_para_hexadecimal(p, elem);
            }
            break;

            // Libera pilha para nova consulta
        case 6:
            if (x != 1)
            {
                printf("Pilha nao criada! \n");
            }
            else
            {
                y = 0;
                if (liberar(p) == 1)
                    printf("\nLiberado com sucesso!!\n");
                else
                    printf("\nERRO AO LIBERAR\n");
                break;
            }
        }

    } while (op != 7);
}