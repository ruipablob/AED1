typedef struct lista Lista;
Lista* cria_lista();
int lista_vazia(Lista* lst);
int lista_cheia(Lista* lst);
int insere_ord(Lista* lst, int elem);
int remove_ord(Lista* lst, int elem);
void imprimi_lista(Lista* lst);