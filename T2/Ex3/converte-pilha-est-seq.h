typedef struct pilha * Pilha;
Pilha cria_pilha();
int pilha_vazia(Pilha p);
int pilha_cheia(Pilha p);
int push(Pilha p, int elem);
int pop(Pilha p, int *elem);
int liberar(Pilha p);
void imprime(Pilha p);
void decimal_para_Binario(Pilha p, int elem);
void decimal_para_octal(Pilha p, int elem);
void decimal_para_hexadecimal(Pilha p, int elem);