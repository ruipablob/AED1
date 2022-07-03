#include<stdio.h>
#include<stdlib.h>
#include"no-cab-din-enc-nord.h"
int main()
{
    Lista lst;
    int elem;
    int op;

    do{

        do{
            printf(" \n--- LISTAS ESTATICAS SEQUENCIAIS --- \n\n");
            printf(" Escolha uma opcao\n");
            printf(" 1. Criar lista\n");
            printf(" 2. Verificar lista vazia\n");
            printf(" 3. Inserir elemento\n");
            printf(" 4. Excluir elemento\n");
            printf(" 5. Imprimir lista\n");
            printf(" 6. SAIR\n");
            printf(" Opcao: ");
            scanf("%d", &op);
            if((op < 1) || (op >6)) {

                printf("\n\n Opcao Invalida! Tente novamente...");
            }
        } while((op < 1) || (op > 6));

        switch(op)
        {   
            case 1:
                lst = cria_lista();
                if(lst != NULL)
                    printf("\nLista Criada!\n");
                else printf("\nLista não criada\n");
                break;

            case 2:
                if(lista_vazia(lst) == 1)
                    printf("\nLista vazia!\n");
                else printf("\n Lista contem elementos.\n");
                break;

            case 3:
                printf("\nDigite o elemento a ser inserido:\n");
                scanf("%d", &elem);
                if(insere_elem(lst,elem)==1) 
                    printf("\nElemento inserido com sucesso!\n");
                else
                    printf("\nErro ao inserir o elemento!\n");
                break;

            case 4:
                printf("\nDigite o elemento a ser Removido:\n");
                scanf("%d", &elem);
                if(remove_elem(&lst,elem)==1) 
                    printf("\nElemento removido com sucesso!\n");
                else
                    printf("\nErro ao remover o elemento!\n");
                break;

            case 5:
                imprime(lst);
                break;
            default:
				printf("\n\n FINALIZADO!");
        }
    } while(op != 6);

    return 0;
}