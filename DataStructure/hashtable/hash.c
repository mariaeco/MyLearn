//TABELA HASH COM LISTA
#include <stdio.h>
#include <stdlib.h>
#include "hash.h"


void iniciaLista(Lista *L){
    L->inicio = NULL;
    L->tam = 0;
}

void inserirLista(Lista *L, int valor){
    No *novo = (No*)malloc(sizeof(No));

    if(novo){
        novo->chave = valor;
        novo->prox = L->inicio;
        L->inicio = novo;
        L->tam++;
    }
    else
        printf("\n\tErro ao alocar memoria!\n");
}

// Função para buscar um elemento. Retorna o elemento encontrado ou zero caso contrário.
int buscar_na_lista(Lista *L, int valor){
    No *aux = L->inicio;
    while(aux && aux->chave != valor)
        aux = aux->prox;
    if(aux)
        return aux->chave;
    return 0;
}

// Procedimento para imprimir a lista recebida como parâmetro.
void imprimir_lista(Lista *L){
    No *aux = L->inicio;
    printf(" Tam: %d: ", L->tam);
    while(aux != NULL){
        printf("%d ", aux->chave);
        aux = aux->prox;
    }
}
