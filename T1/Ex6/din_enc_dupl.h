typedef struct no *Lista;
Lista cria_lista();
int lista_vazia(Lista lst);
int insere_ord(Lista *lst, int elem);
void imprime(Lista lst);
int remove_ord(Lista *lst,int elem);