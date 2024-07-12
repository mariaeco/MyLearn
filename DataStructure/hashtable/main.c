//MAIN
#include <stdio.h>
#include <stdlib.h>
#include "hash.h"



int main(){
    int op;
    int valor, retorno;
    
    Lista tabela[TAM];

    inicializaTabela(tabela);


    do{
        printf("\n\t 0 - Sair");
        printf("\n\t 1 - Inserir");
        printf("\n\t 2 - Buscar");
        printf("\n\t 3 - Imprimir\n");
        scanf("%d", &op);
        system("cls");

        switch(op){
            case 1:
                printf("\tQual valor deseja inserir? ");
                scanf("%d", &valor);
                inserir(tabela, valor);
                break;
            case 2:
                printf("\tQual valor deseja buscar? ");
                scanf("%d", &valor);
                retorno = busca(tabela, valor);
                if(retorno != -1){
                    printf("\nValor encontrado");
                }else{
                    printf("\nValor nao encontrado.");
                }
                break;
            case 3:
                imprimir(tabela);
                break;
            case 0:
                break;
            default:
                printf("Opcao invalida.\n");
                break;
        }
    }while(op != 0);

    return 0;

}
