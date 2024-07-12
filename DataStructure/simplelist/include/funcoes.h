#ifndef FUNCOES_H
#define FUNCOES_H


typedef struct _lista Lista;



void criaLista(Lista *L);
bool list_is_empty(const Lista *list);
bool list_is_full(const Lista *list);
int insereInicio(Lista *L, int valor);
bool insereFinal(Lista *lista, int valor);
void insereMeio(Lista *L, int valor, int pos);
void Ordenar(Lista *L);
void inserirOrdenado(Lista *L, int valor);
void removeInicio(Lista *L);
void removeFim(Lista *L);
void alteraElem(Lista *L, int valor, int new_valor);
void removeElem(Lista *L, int valor);
void imprimeLista(Lista *L);
void limparLista(Lista *L);
void ConsultaVazia(Lista *L);
int comparar(const void *p, const void *q) ;
int soma_todos(Lista *L);


#endif // FUNCOES_H