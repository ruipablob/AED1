typedef struct ponto Ponto;
Ponto * gera_pto();
float set_pto(Ponto *p, float N1, float N2);
float get_pto(Ponto *p,float *N1, float *N2);
void libera_pto(Ponto **p);
float distancia_pto(Ponto *p1, Ponto *p2);

