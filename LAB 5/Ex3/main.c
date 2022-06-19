#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "bebidas-est-seq.h"

int main()
{
    Lista lst;
    char nome[20];
    int op, volume;
    float preco;

    do{

        do{
            printf(" --- LISTAS ESTATICAS SEQUENCIAIS --- \n\n");
            printf(" Escolha uma opcao\n");
            printf(" 1. Criar lista\n");
            printf(" 2. Verificar lista vazia\n");
            printf(" 3. Verificar lista cheia\n");
            printf(" 4. Inserir elemento\n");
            printf(" 5. Excluir elemento\n");
            printf(" 6. Imprimir lista\n");
            printf(" 7. SAIR\n");
            printf(" Opcao: ");
            scanf("%d", &op);
            if((op < 1) || (op >7)) {

                printf("\n\n Opcao Invalida! Tente novamente...");
            }
        } while((op < 1) || (op > 7));

        switch(op)
        {   
            case 1:
                lst = cria_lista();
                printf("\n\n Lista Criada!\n");
                break;

            case 2:
                if(lista_vazia(lst) == 1)
                    printf("Lista vazia!!!\n");
                else 
                    printf("Lista não vazia!!!\n");
                break;

            case 3:
                if(lista_cheia(lst) == 1)
                    printf("Lista cheia!!!\n");
                else 
                    printf("Lista não cheia!!!\n");
                break;

            case 4:
                printf("Digite o nome da bebida:\n");
                setbuf(stdin,NULL);
                gets(nome);
                printf("Digite o volume:\n");
                scanf("%d", &volume);
                printf("Digite o preco:\n");
                scanf("%f", &preco);
                if(insere_elem(lst, nome, volume, preco) == 1){
                printf("\n\n Elemento inserido!!!");
                }else printf("\n elemento nao inserido!");
                break;

            case 5:
                printf("Digite o elemento a ser nome da bebida a ser removida:\n");
                setbuf(stdin,NULL);
                gets(nome);
                if(remove_elem(lst,nome)==1)
                printf("\n\n Elemento removido!!!");
                else printf("\n\n Elemento nao removido!!!");
                break;

            case 6:
                imprime_lista(lst);
                break;

            default:
				printf("\n\n FINALIZADO!");
        }
    } while(op != 7);

    return 0;
}