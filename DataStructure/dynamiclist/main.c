/*
PROGRAMA: LISTA COM ALOCACAO DINAMICA
AUTOR: MARIA MARCOLINA CARDOSO
Objetivos: 
    Menu Inicial:
    - Cria Lista
    - Limpa Lista
    - Insere no Inicio da Lista
    - Insere no Fim da Lista
    - Remove do Inicio da Lista
    - Remove do Fim da Lista
    - Mostra Lista
    - Ver se esta vazia a Lista
    - Ver se esta cheia a Lista
    - Consulta Valor na Lista
    - Altera Elemento da Lista

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

typedef struct _lista{
    int info;
}Lista;

typedef struct _controle{
    int c; //minha variavel de controle
}Ctr;


int main(int argc, char const *argv[]){

    int choice = 0;
    int num, pos, new;
    Lista *lista;   


    // MEU MENU -------------------------------------------------
    do{
        printf ("MEU MENU\n");
        printf("1 - Cria Lista\n");
        printf("2 - Insere no Fim da Lista\n");
        printf("3 - Remove do Fim da Lista\n");
        printf("4 - Mostrar Lista\n");
        printf("5 - Limpa Lista\n");
        printf("0 - Sair\n");

           
        scanf("%d", &choice);
        system("cls||clear");

        switch(choice){
            case 1: //Cria lista
            printf("Insira a quantidade de dados que você deseja inserir: \n");
                scanf("%i", &num);
                criaLista(&lista, num);
                system("cls");
                break;
            case 2: //addFIM
                printf("Insira um numero: \n");
                scanf("%i", &num);
                insereFinal(lista,num);
                system("cls");
                break;
            case 3: //removeFim
                removeFim(lista);
                system("cls");
                break;
            case 4: //printLista
                printf("\nMINHA LISTA\n");
                imprimeLista(lista);
                system("cls");
                break;
            case 5: //LIMPA LISTA
                limparLista(lista);
                system("cls");
                break;
            default:
                if(choice==0){
                exit(0);
                }
                printf("Digite uma opcao valida!\n");
                break;
            }
    }while(choice!= 0);

    
    return 0;
}
