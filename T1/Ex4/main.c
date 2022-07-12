#include <stdlib.h>
#include <stdio.h>
#include "din_enc_cab.h"

int main()
{
    int op, n;
    Lista lista;
    do{
        do{
            printf("\n --- LISTA DINAMICA ENCADEADA ORDENADA --- \n");
            printf(" Escolha uma opcao\n");
            printf(" 1. Criar lista\n");
            printf(" 2. Verificar lista vazia\n");
            printf(" 3. Inserir elemento\n");
            printf(" 4. Excluir elemento\n");
            printf(" 5. Tamanho lista\n");
            printf(" 6. Media \n");
            printf(" 7. Listas Iguais\n");
            printf(" 8. Intercala \n");
            printf(" 9. Inverte lista \n");
            printf(" 10. Retorna impares \n");
            printf(" 11. Imprime Lista\n");
            printf(" 12. SAIR\n");
            printf(" Opcao: ");
            scanf("%d", &op);
            if((op < 1) || (op > 12)) {

                printf("\n\n Opcao Invalida! Tente novamente...");
            }
        } while((op < 1) || (op > 12));

        switch(op)
        {   
            case 1:
                lista = cria_lista();
                printf("Lista criada.\n");
                break;

            case 2:
               if (lista_vazia(lista) == 1){
                    printf("Lista vazia. \n");
                }else{
                    printf("Lista nao vazia. \n");
                }
               break;

            case 3:
                printf("Qual elemento deseja inserir: \n");
                scanf("%d", &n);
                if(insere_ord(&lista, n) == 1)
                    printf("Numero inserido \n");
                else
                    printf("Numero nao inserido \n");
                break;

            case 4:
                printf("\n Qual elemento deseja remover: \n");
                scanf("%d", &n);
                if (remove_ord(&lista,n) == 1)
                {
                    printf("Numero removido \n");
                }else{
                    printf("Numero nao encontrado \n");
                }
                break;
            case 5:
                if(tamanho(lista) == 0){
                    printf("Lista vazia\n");
                }else{
                    printf("Tamanho: %d", tamanho(lista));
                }
                break;

            case 6:
                double medi = media(lista);
                if(lista_vazia(lista) == 1){
                    printf("Lista vazia! \n");
                }else{
                    printf("%.2f \n", medi);
                }
                break;

            case 7:
                Lista lst;
                lst = cria_lista();
                printf("Nova lista criada! \n");
                int op1,n1;
                do
                {
                    do
                    {
                        printf("\n Escolha uma opcao\n");
                        printf(" 1. Inserir elemento\n");
                        printf(" 2. Excluir elemento\n");
                        printf(" 3. Imprime Lista\n");
                        printf(" 4. Listas Iguais? \n");
                        printf(" 5. Sair \n");
                        printf(" Opcao: ");
                        scanf("%d", &op1);
                        if((op1 < 1) || (op1 > 5))
                            printf("Opcao Invalida! Tente novamente... \n");
                    }while((op1 < 1) || (op1 > 5));
                    
                    switch (op1){
                        case 1:
                            printf("Qual elemento deseja inserir: \n");
                            scanf("%d", &n1);
                            if(insere_ord(&lst,n1) == 1)
                                printf("Numero inserido \n");
                            else
                                printf("Numero nao inserido \n");
                            break;
                        case 2:
                            printf("\n Qual elemento deseja remover: \n");
                            scanf("%d", &n1);
                            if (remove_ord(&lst,n1) == 1)
                            {
                                printf("Numero removido \n");
                            }else{
                                printf("Numero nao encontrado \n");
                            }
                            break;
                        case 3: 
                            imprime(lst);
                            break;
                        case 4:
                            int aux = iguais(lista,lst);
                            if(aux == 1){
                                printf("Listas Iguais! \n");
                            }else if(aux == 0){
                                printf("Listas Diferentes! \n");
                            }else{
                                printf("Listas vazias! \n");
                            }
                            break;
                    }
                } while (op1 != 5);

                break;
            case 8:
                Lista lstIn;
                lstIn = cria_lista();
                printf("Nova lista criada! \n");
                int op2,n2;
                do
                {
                    do
                    {
                        printf("\n Escolha uma opcao\n");
                        printf(" 1. Inserir elemento\n");
                        printf(" 2. Excluir elemento\n");
                        printf(" 3. Imprime Lista\n");
                        printf(" 4. Intercalar listas \n");
                        printf(" 5. Sair \n");
                        printf(" Opcao: ");
                        scanf("%d", &op2);
                        if((op2 < 1) || (op2 > 5))
                            printf("Opcao Invalida! Tente novamente... \n");
                    }while((op2 < 1) || (op2 > 5));
                    
                    switch (op2){
                        case 1:
                            printf("Qual elemento deseja inserir: \n");
                            scanf("%d", &n2);
                            if(insere_ord(&lstIn,n2) == 1)
                                printf("Numero inserido \n");
                            else
                                printf("Numero nao inserido \n");
                            break;
                        case 2:
                            printf("\n Qual elemento deseja remover: \n");
                            scanf("%d", &n2);
                            if (remove_ord(&lstIn,n2) == 1)
                            {
                                printf("Numero removido \n");
                            }else{
                                printf("Numero nao encontrado \n");
                            }
                            break;
                        case 3: 
                            imprime(lstIn);
                            break;
                        case 4:
                            // int aux = intercala(lista,lstIn);
                            // if(aux == 1)
                            //     printf("Listas Intercaladas! \n");
                            // else
                            //     printf("Erro ao intercalar! \n");
                            break;
                    }
                } while (op2 != 5);
                break;
            case 9:
                //inverter(lista);
                break;
            case 10:
                ret_impares(lista);
                break;
            case 11:
                imprime(lista);
                break;              

        }
    } while(op != 12);
    return 0;
}