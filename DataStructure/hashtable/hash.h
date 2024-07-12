#ifndef HASH_H
#define HASH_H

#define TAM 31

typedef struct no{
    int chave;
    struct no* prox;
}No;

typedef struct {
    No* inicio;
    int tam;
}Lista;


void iniciaLista(Lista *L);
void inserirLista(Lista *L, int valor);
int buscar_na_lista(Lista *L, int valor);
void imprimir_lista(Lista *L);
void inicializaTabela(Lista t[]);
int funcaoHash(int chave);
void inserir(Lista t[], int valor);
int busca(Lista t[], int chave);
void imprimir(Lista t[]);




#endif // 