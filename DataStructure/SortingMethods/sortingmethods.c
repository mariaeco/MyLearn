#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"



void selection_sort(int *v, int n){//v = vetor
    int my_id;
    int aux; 

    for (int i=0; i < n-1; i++){
        my_id = i;
        for (int j = i+1; j < n; j++){
            if(v[my_id]>v[j]){
                my_id = j;
            }
        }
        if(i != my_id){
            aux = v[i];
            v[i] = v[my_id];
            v[my_id]= aux;
        }
    }
}


void insertion_sort(int *v, int tam){
    int aux, indice;
    for(int i = 1; i < tam; i++){
        aux = v[i];
        indice = i;
        while(indice > 0 & v[indice-1] > aux){
            v[indice] = v[indice-1];
            indice--;
        }
        v[indice] = aux;
    }
}


int mergeSort(int *v, int inicio, int fim){
    int meio;

    if (inicio >= fim){ 
        return 0;
    }
    meio = (inicio+(fim-1))/2;
    mergeSort(v, inicio, meio);
    mergeSort(v, meio+1, fim);
    merge(v, inicio, meio, fim);
}

void merge(int *v, int inicio, int meio, int fim){
    int *aux, i, j, k;
    
    i = inicio;
    j = meio+1;
    k = inicio; // controla o tamanho

    int n = 0;
    while (v[n] != -1) { // Use -1 como marcador de fim, você pode ajustá-lo conforme necessário
        n++;
    }
    aux = (int*)malloc(n*2*sizeof(int));
    if (aux == NULL) {
        printf("Erro ao alocar memoria para o aux.\n");
        exit(1);
    }
    while(i <= meio & j <= fim){
        if(v[i]<v[j]){
            aux[k] = v[i];
            i++;
        }else{
            aux[k] = v[j];
            j++;     
        }
        k++;
    }
    while(i <= meio){
        aux[k] = v[i];
        i++;
        k++;
    }
    while(j <= fim){
        aux[k] = v[j];
        j++;
        k++;
    }
    for(i = inicio; i <= fim; i++){
        v[i] = aux[i];
    }
    free(aux);
}

void imprimir(int *v, int tam){

    printf("\n\n\n ------------------------ VETOR ORDENADO ------------------------------------\n");
    for (int i = 0; i < tam; i++) {
        printf("%d ", v[i]);
    }
    printf("\n\n");
    
}

int contarLinhasArquivo(const char* nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s.\n", arquivo);
        exit(1);
    }
    int contador = 0;
    char linha[100]; // Tamanho arbitrário para uma linha
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        contador++;
    }

    fclose(arquivo);
    return contador;
}

int* abrirArquivo(const char* nomeArquivo, int nlinhas){
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s.\n", arquivo);
        exit(1);
    }
    //sabendo o tamanho do arquivo para poder alocar memora
    
    //alocando um vetor do tamanho do arquivo
    int *v = (int*)malloc(nlinhas * sizeof(int)); // Aloca memória para o vetor
    if (v == NULL) {
        printf("Erro ao alocar memoria para o vetor original.\n");
        exit(1);
    }
    
    rewind(arquivo);// preciso retornar ao inicio do arquivo
    int n = 0;
    char linha[1000]; 
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        v[n] = atoi(linha);
        //printf("%d ", v[n]);
        n++;
    }
    printf("\nTamanho do arquivo: %d\n", n);

    fclose(arquivo);
    return v;
}
