#ifndef FUNCOES_H
#define FUNCOES_H


int* abrirArquivo(const char* nomeArquivo, int nlinhas);
int contarLinhasArquivo(const char* nomeArquivo);
void selection_sort(int *v, int n);
void insertion_sort(int *v, int tam);
int mergeSort(int *v, int inicio, int fim);
void merge(int *v, int inicio, int meio, int fim);
void imprimir(int *v, int tam);

#endif // FUNCOES_H