#ifndef FUNCOES_H
#define FUNCOES_H


typedef struct _lista Lista;
typedef struct _controle Ctr;


void criaLista(Lista **L, int n);
void insereFinal(Lista *L, int valor);
void removeFim(Lista *L);
int imprimeLista(Lista *L);
void limparLista(Lista *L);



#endif // FUNCOES_H