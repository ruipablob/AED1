#include <stdio.h>
#include <stdlib.h>
#include "din_enc_cicl.h"
int main()
{
    int op, n;
    Lista lista;
    do{
        do{
            printf("\n --- LISTA DINAMICA ENCADEADA COM ENCADEAMENTO CICLICO --- \n");
            printf(" Escolha uma opcao\n");
            printf(" 1. Criar lista\n");
            printf(" 2. Verificar lista vazia\n");
            printf(" 3. Inserir elemento final\n");
            printf(" 4. Excluir elemento inicio\n");
            printf(" 5. Tamanho lista\n");
            printf(" 6. Inserir elemento inicio \n");
            printf(" 7. Inserir em posicao especifica \n");
            printf(" 8. Remove em posicao especifica \n");
            printf(" 9. Maior elemento \n");
            printf(" 10. Remover pares \n");
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
               if (lista_vazia(lista) == 1){ //NAO RETORNA O MENU
                    printf("Lista vazia. \n");
                }else{
                    printf("Lista nao vazia. \n");
                }
               break;

            case 3:
                printf("Qual elemento deseja inserir: \n");
                scanf("%d", &n);
                if(insere_final(&lista, n) == 1)
                    printf("Numero inserido \n");
                else
                    printf("Numero nao inserido \n");
                break;

            case 4:
                printf("\n Qual elemento deseja remover: \n");
                scanf("%d", &n);
                if (remove_inicio(&lista,&n) == 1)
                {
                    printf("Numero removido \n");
                }else{
                    printf("Numero nao encontrado \n");
                }
                break;
            case 5:
                int tam = tamanho(lista);
                if(tam == 0){
                    printf("Lista vazia\n");
                }else{
                    printf("Tamanho: %d", tam);
                }
                break;

            case 6:
                // printf("Qual elemento deseja inserir: \n");
                // scanf("%d", &n);
                // if(insere_inicio(&lista, n) == 1)
                //     printf("Numero inserido \n");
                // else
                //     printf("Numero nao inserido \n");
                // break;

            case 7:
                // int pos;
                // printf("Qual elemento deseja inserir: \n");
                // scanf("%d", &n);
                // if(insere_pos(&lista, n,pos) == 1)
                //     printf("Numero inserido \n");
                // else
                //     printf("Numero nao inserido \n");

                break;
            case 8:
                // int pos;
                // printf("\n Qual elemento deseja remover: \n");
                // scanf("%d", &n);
                // if (remove_pos(&lista,pos) == 1)
                // {
                //     printf("Numero removido \n");
                // }else{
                //     printf("Numero nao encontrado \n");
                // }
                break;
            case 9:
                int mai = maior(lista);
                if(lista_vazia(lista) == 1)
                    printf("Lista vazia! \n");
                else
                    printf("Maior: %d \n", mai);
                break;
            case 10:
                if(remove_pares(&lista) == 1)
                    printf("Numeros removidos! \n");
                else
                    printf("Numeros nao removidos \n");
                break;
            case 11:
                if(lista_vazia(lista) == 1)
                    printf("Lista vazia! /n");
                else
                    imprime(lista);
                break;              

        }
    } while(op != 12);
    return 0;
}