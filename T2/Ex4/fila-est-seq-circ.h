typedef struct fila * Fila;
Fila inicializar_fila();
int fila_vazia(Fila f);
int fila_cheia(Fila f);
int insere_fila(Fila f, int elem);
int remove_fila(Fila f, int *elem);
void imprime(Fila f);