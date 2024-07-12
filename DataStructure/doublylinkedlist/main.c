/*
PROGRAMA: LISTA ENCADEADA
AUTOR: MARIA MARCOLINA CARDOSO
Objetivos: 
    Menu Inicial:
    - Cria Lista
    - Limpa Lista
    - Insere no Inicio da Lista
    - Insere no Fim da Lista
    - Insere ordenado
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



int main(int argc, char const *argv[]){

    int choice = 0;
    int num;
    Lista *lista;



    // MEU MENU -------------------------------------------------
    do{
        printf ("MEU MENU\n");
        printf("1 - Cria Lista\n");
        printf("2 - Insere no inicio da Lista\n");
        printf("3 - Insere no fim da Lista\n");
        printf("4 - Insere ordenado\n");
        printf("5 - Ordenar lista\n");
        printf("6 - Mostrar Lista\n");
        printf("7 - Remover do Inicio\n");
        printf("8 - Remover do Fim\n");
        printf("9 - Remover Elemento\n");
        printf("10 - Limpar Lista\n");
        printf("0 - Sair\n");

           
        scanf("%d", &choice);
        system("cls||clear");

        switch(choice){
            case 1: //CriarLista
                criaLista(&lista);
                system("cls");
                break;
            case 2: //addInicio
                printf("Insira um numero: \n");
                scanf("%d", &num);
                insereInicio(&lista,num);
                system("cls");
                break;
            case 3: //addFim
                printf("Insira um numero: \n");
                scanf("%d", &num);
                insereFim(&lista,num);
                system("cls");
                break;
            case 4: //addOrdenado
                printf("Insira um numero: \n");
                scanf("%d", &num);
                insereOrdenado(&lista,num);
                system("cls");
                break;
            case 5: //Ordenar lista
                Ordenar(&lista);
                system("cls");
                break;            
            case 6: //mostraLista
                mostra(lista);
                system("cls");
                break;
            case 7: //Remover do Inicio
                removerInicio(&lista);
                system("cls");
                break;
            case 8: //Remover do Fim
                removerFim(&lista);
                system("cls");
                break;
            case 9: //Remover elemento
                printf("Insira um numero: \n");
                scanf("%d", &num);
                removerElemento(&lista, num);
                system("cls");
                break;
            case 10: //Limpar lista
                limparLista(&lista);
                system("cls");
                break;
            default:
                if(choice==0){
                limparLista(&lista);
                exit(0);
                }
                printf("Digite uma opcao valida!\n");
                break;
            }
    }while(choice!= 0);

    return 0;
}
