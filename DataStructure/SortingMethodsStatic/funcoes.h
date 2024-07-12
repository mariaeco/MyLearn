#ifndef FUNCOES_H
#define FUNCOES_H

#define MAX_SIZE 100000 // Tamanho máximo do vetor, ajuste conforme necessário

void abrirArquivo(const char* nomeArquivo, int nlinhas, int v[]);
int contarLinhasArquivo(const char* nomeArquivo);
void selection_sort(int v[], int n);
void insertion_sort(int v[], int tam);
int merge_sort(int v[], int inicio, int fim);
void merge(int v[], int inicio, int meio, int fim);
void imprimir(int v[], int tam);

#endif // FUNCOES_H