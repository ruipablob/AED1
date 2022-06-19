#include<stdio.h>
#include<stdlib.h>
#include "lista-enc-nord.h"

int main()
{

    int elem;
    int op,x=0;

    do{
        do{
            printf("\n --- LISTAS DINAMICA ENCADEADA NAO ORDENADA--- \n\n");
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
                Lista lst = cria_lista();
                if (lst==NULL)
                {
                    printf("Lista Criada!\n");
                    
                }else printf("Lista nao criada!");
                x=1;
                break;

            case 2:

                if(lista_vazia(&lst) == 1)
                    printf("Lista vazia!!!\n");
                else 
                    printf("Lista nao vazia!!!\n");
                
                break;

            case 3:
            if(x!=1){
                printf("Lista nao criada!\n");
            }else{
                printf("Digite um numero:\n");
                scanf("%d",&elem);
                if(insere_elem(&lst,elem)==1){
                    printf("Elemento insirido com sucesso!\n");
                }else{
                    printf("Erro ao inserir o elemento!\n");
                }
            }
                break;

            case 4:
                printf("Digite o elemento a ser removido:\n");
                scanf("%d", &elem);
                if(remove_elem(&lst, elem) == 1){
                printf("\n\n Elemento removido!!!\n");
                }else{
                    printf("Elemento nao removido!\n");
                } 

                break;

            case 5:
                imprime(lst);
                break;

            default:
				printf("\n\n Pressione qualquer tecla para FINALIZAR...");
        }
    } while(op != 6);

    return 0;
}