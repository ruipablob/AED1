typedef struct lista *Lista;
Lista cria_lista();
int lista_vazia(Lista lst);
int lista_cheia(Lista lst);
int insere_elem(Lista lst, char *nome, int volume, float preco);
int remove_elem(Lista lst, char *nome);
void imprime_lista(Lista lst);