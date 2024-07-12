//TABELA HASH COM VETOR
#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

void inicializaTabela(Lista t[]){
    int i;
    for(i = 0; i < TAM; i++){
        iniciaLista(&t[i]);//t[i] = -1;
    }
}

int funcaoHash(int chave){
    return (chave % TAM);
}

void inserir(Lista t[], int valor){
    int id = funcaoHash(valor);
    inserirLista(&t[id], valor);
    /*
    while(t[id] != -1){ //percorrendo ate a posicao vazia
        id = funcaoHash(id+1);
    }
    t[id] = valor;
    */
}

int busca(Lista t[], int chave){
    int id = funcaoHash(chave);
    printf("\nIndice Gerado: %d\n", id);
    return(buscar_na_lista(&t[id], chave));
    /*
    while(t[id] != -1){ //percorrendo ate a posicao vazia
        if(t[id] == chave){
            return t[id];
        }else{
            id = funcaoHash(id+1);
        }
    }
    return (-1);
    */
}

void imprimir(Lista t[]){
    int i;
    for(i = 0; i<TAM; i++){
        printf("%2d =  ", i);
        imprimir_lista(&t[i]);
        printf("\n");
        //printf("%d = %d\n", i, t[i]);
    }
}

