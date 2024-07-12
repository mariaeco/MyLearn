#ifndef PILHA_H
#define PILHA_H

typedef struct{
    int dia, mes, ano;
}Data;

typedef struct{
    char nome[30];
    int idade;
    Data data;
}Pessoa;

typedef struct no{
    Pessoa info;
    struct no* proximo; // na propria estrutura eu aponto para alguem do mesmo tipo dela
} Lista;

/*
typedef struct no Lista; posso usar assim caso eu não faça com typedef
*/

Pessoa get_data();
void imprimirDado();
void criaPilha(Lista **topo);
Lista *empilhar(Lista *topo);
Lista *desempilhar(Lista **topo);
void mostra(Lista *topo);
void limparLista(Lista **topo);

#endif // PILHA_H