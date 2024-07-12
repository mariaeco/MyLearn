/*
PROGRAMA: ALGORITIMOS DE ORDENACAO
AUTOR: MARIA MARCOLINA CARDOSO

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "funcoes.h"



int main(){
    
    int choice;
    int num;
    int inicio, fim;
    clock_t end, start;
    int *vetor;
    const char *caminhoDoArquivo =  "teste2.txt"; //"teste.txt";"num.1000.1.txt"
    
    num = contarLinhasArquivo(caminhoDoArquivo); // Obtenha o tamanho do vetor
    



    // MEU MENU -------------------------------------------------
    do{
        printf ("MEU MENU\n");
        printf("1 - Ordenar por Selection Sort\n");
        printf("2 - Ordenar por Insertion Sort\n");
        printf("3 - Ordenar por Merge Sort\n");
        printf("4 - Imprimir tempos\n");
        printf("0 - Sair\n");
   
        scanf("%d", &choice);
        system("cls||clear");

        switch(choice){
            case 1:
                vetor = abrirArquivo(caminhoDoArquivo, num);
                start = clock();
                selection_sort(vetor, num);
                imprimir(vetor, num);
                double timeS = ((double)(end-start))/CLOCKS_PER_SEC;
                printf("\n\nTempo gasto: %f\n\n", timeS);
                system("pause");
                system("cls");
                break;
            case 2: 
                vetor = abrirArquivo(caminhoDoArquivo, num);
                start = clock();
                insertion_sort(vetor, num);
                imprimir(vetor, num);
                double timeI = ((double)(end-start))/CLOCKS_PER_SEC;
                printf("\n\nTempo gasto: %f\n\n", timeI);
                system("pause");
                system("cls");
                break;
            case 3:
                vetor = abrirArquivo(caminhoDoArquivo, num);
                inicio = 0;
                fim = num;
                start = clock();
                mergeSort(vetor, inicio, fim);
                imprimir(vetor, num);
                double timeM = ((double)(end-start))/CLOCKS_PER_SEC;
                printf("\n\nTempo gasto: %f\n\n", timeM);
                end = clock();
                system("pause");
                system("cls");
                break;
            case 4:
                printf("Run Time:\n");
                printf("Selection Sort: %f\n", timeS);
                printf("Insertion Sort: %f\n", timeI);
                printf("Nerge Sort:     %f\n", timeM);
                system("pause");
                system("cls");
            case 0:
                break;
            default:
                printf("Digite uma opcao valida!\n");
                break;
            }
    }while(choice!= 0);

    return 0;
}
