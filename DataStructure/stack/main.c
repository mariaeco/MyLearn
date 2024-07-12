/*
PROGRAMA: PILHA
AUTOR: MARIA MARCOLINA CARDOSO

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"




int main(int argc, char const *argv[]){

    int choice = 0;
    int num;
    Lista *topo, *remover;



    // MEU MENU -------------------------------------------------
    do{
        printf ("MEU MENU\n");
        printf("1 - Cria Pilha\n");
        printf("2 - Inserir Elemento\n");
        printf("3 - Remover Elemento\n");
        printf("4 - Mostrar Elemento do Topo\n");
        printf("5 - Limpar Lista\n");
        printf("0 - Sair\n");

           
        scanf("%d", &choice);
        system("cls||clear");

        switch(choice){
            case 1: //CriaPilha
                criaPilha(&topo);
                system("cls");
                break;
            case 2: //Push
                topo = empilhar(topo);
                system("cls");
                break;
            case 3: //Pop
                remover = desempilhar(&topo);
                system("cls");
                break;
            case 4: //mostraLista
                mostra(topo);
                system("cls");
                break;
            case 5: //Limpar lista
                limparLista(&topo);
                system("cls");
                break;
            default:
                if(choice==0){
                limparLista(&topo);
                exit(0);
                }
                printf("Digite uma opcao valida!\n");
                break;
            }
    }while(choice!= 0);

    
    return 0;
}
