//FUNCOES
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

typedef struct _lista{
    int info;
    int c; // controle
    int tamanho;
}Lista;



//Funcao para criar meu controle
/*
Ctr *criaControle(int n){
    Ctr *ctr;
    ctr->c = -1;
    ctr->tamanho = n;
    printf("Tamanho atual da lista: %d",ctr->c+1);
    printf("\n\nLista criada com sucesso!\n\n");

    return ctr;
}
*/

//Funcao de criacao de lista
void criaLista(Lista **lista, int n){

    Lista *ll = (Lista*)malloc(n*sizeof(Lista));
    ll->c = -1;
    ll->tamanho = n;

    if(!ll){
        printf("Tamanho atual da lista: %d",ll->c+1);
        printf("\n\nLista criada com sucesso!\n\n");
    }

    system("pause");
    return;

}


//Insere elemento no final da lista
void insereFinal(Lista *lista, int valor){
    int arraySize = sizeof(lista->info);
    int intSize = sizeof(lista[0].info);
    int length = arraySize/intSize;// tamanho do meu vetor info

    if (lista->c == length-1){// se minha lista esta cheia
        printf("size: %i\n",length);
        printf("Lista cheia\n");
    }else{// caso nao esteja cheia, quero que insira na ultima posicao vazia
        lista[lista->c+1].info = valor;
        lista->c = lista->c+1;
    }
}


int imprimeLista(Lista *lista){ //Lista *lista

    if(lista == NULL){
        printf("Lista não existe\n");
        system("pause");
        return 0;
    }

    if (lista->c ==-1){
        printf("Lista Vazia!\n");
    }else{
        printf("Lista->");
        for(int i=0; i <= lista->c ; i++){
            printf("%d",lista[i].info);
            printf("->");
        }
        printf("NULL\n");
    }
    system("pause");
}


void removeFim(Lista *lista){
    lista->c = lista->c-1;
    printf("Elemento no final da lista removido com sucesso!\n");
    system("pause");
}

void limparLista(Lista *lista){//Remove todos os nós da Lista
    if(lista->c==-1){
        printf("Lista esta vazia!\n");
    }else{
        lista->c = - 1;
        printf("Lista limpa!\n");
    }
    system("pause");
}





/*
//Inserir no inicio da lista
void insereInicio(Lista *L, int valor){

    if(L->c == -1){ // se a lista esta vazia, inserir o valor na casa 0
        L->info[0] = valor;
        L->c = L->c + 1;
    }else if(L->c < 9) {
        // Ainda se a c > 9 ou seja, a lista não esteja cheia
        // percorrer toda a lista de trás para frente
        for(int i = L->c; i>=0; i--){
            L->info[i+1] = L->info[i];
            // puxar todos os valores para a direita
            // Se preenchi até a casa 3, então eu peço que
            // a casa 4 receba o valor da casa 3;
            // faço isso até a casa 0, nesse ponto
            // a casa 0 e a terão o mesmo valor
        }// em seguida coloco  meu novo calor na casa 0
        L->info[0] = valor;
        L->c = L->c + 1;
    }
}
*/