/*
PROGRAMA: LISTA ESTATICA - SEM ALOCACAO DINAMICA
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
#include <stdbool.h>
#include "funcoes.h"

typedef struct _lista{
    int info[10];
    int c; //minha variavel de controle
}Lista;


int main(){

    int choice = 0;
    int num, pos, newNum;
    Lista lista;   


    // MEU MENU -------------------------------------------------
    do{
        printf ("MEU MENU\n");
        printf("1 - Cria Lista\n");
        printf("2 - Insere no Inicio da Lista\n");
        printf("3 - Insere no Fim da Lista\n");
        printf("4 - Insere no Meio da Lista\n");
        printf("5 - Ordenar\n");
        printf("6 - Inserir Ordenado\n");
        printf("7 - Remove do Inicio da Lista\n");
        printf("8 - Remove do Fim da Lista\n");
        printf("9 - Mostrar Lista\n");
        printf("10 - Limpa Lista\n");
        printf("11 - Consultar Lista\n");
        printf("12 - Alterar elemento\n");
        printf("13 - Remover elemento\n");
        printf("14 - Soma todos os elementos\n");
        printf("0 - Sair\n");

           
        scanf("%d", &choice);
        system("cls||clear");

        switch(choice){
            case 1: //Cria lista
                criaLista(&lista);
                system("pause");
                break;
            case 2: //addInicio
                printf("Insira um numero: \n");
                scanf("%i", &num);
                insereInicio(&lista, num);
                system("pause");
                break;        
            case 3: //addFIM
                printf("Insira um numero: \n");
                scanf("%i", &num);
                insereFinal(&lista,num);
                system("cls");
                break;
            case 4: //add middle
                printf("Insira um numero: \n");
                scanf("%i", &num);
                printf("Insira a posicao que deseja inserir: \n");
                scanf("%i", &pos);
                insereMeio(&lista,num, pos);
                system("cls");
                break;
            case 5: //Ordenar
                Ordenar(&lista);
                system("cls");
                break;
            case 6: //Inserir Ordenado
                printf("Insira um numero: \n");
                scanf("%i", &num);
                inserirOrdenado(&lista, num);
                system("cls");
                break;
            case 7: //removeInicio
                removeInicio(&lista);
                system("cls");
                break;
            case 8: //removeFim
                removeFim(&lista);
                system("cls");
                break;
            case 9: //printLista
                printf("\nMINHA LISTA\n");
                imprimeLista(&lista);
                system("cls");
                break;
            case 10: //LIMPA LISTA
                limparLista(&lista);
                system("cls");
                break;
            case 11: //CONSULTAR SE ESTA VAZIA
                ConsultaVazia(&lista);
                system("cls");
                break;
            case 12: //ALTERAR DETERMINADO ELEMENTO
                printf("Insira um Numero que deseja alterar: \n");
                scanf("%i", &num);
                printf("Insira o Novo Valor: \n");
                scanf("%i", &newNum);
                alteraElem(&lista, num, newNum);
                system("cls");
                break;
            case 13: //REMOVER UM ELEMENTO
                printf("Insira um Numero que deseja remover: \n");
                scanf("%i", &num);
                removeElem(&lista, num);
                system("cls");
                break;
            case 14: //SOMAR OS ELEMENTOS DA LISTA
                printf("Esta funcao soma todos os elementos da lista\n");
                soma_todos(&lista);
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
