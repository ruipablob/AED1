typedef struct lista Lista;
Lista* cria_lista();
int lista_vazia(Lista* lst);
int lista_cheia(Lista* lst);
int insere_elem(Lista* lst, int elem);
int remove_elem(Lista* lst, int elem);
void imprimi_lista(Lista* lst);