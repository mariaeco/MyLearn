/*
    IMPLEMENTACAO DE LISTA SIMPLES - sem encadeamento

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "funcoes.h"

#define MAX  5

typedef struct _lista{
    int info[MAX];
    int c; //minha variavel de controle
}Lista;


//Funcao de criacao de lista
void criaLista(Lista *lista){
    if(lista->c > -1 && lista->c <= MAX-1){
        printf("Lista ja criada\n");
    }
    else{
        lista->c = -1;
        printf("Tamanho da lista: %d",lista->c);
        printf("\n\nLista criada com sucesso!\n\n");
    }

    system("pause");

}

// SEMPRE VERIFICAR SE A LISTA ESTA VAZIA OU CHEIA
bool list_is_empty(const Lista *list) {
    return list && list->c == -1; // se lista existe e eh igual a -1
}

bool list_is_full(const Lista *list) {
    return list && list->c == MAX; // se lista existe e eh igual ao limite
}

//Inserir no inicio da lista
int insereInicio(Lista *L, int valor){
    // se a lista não tiver cheia
    // percorrer a lista até o fim
    if(L->c == MAX-1){
        printf("Lista Cheia, remova um valor\n");
        return 0;
    }else if(L->c == -1){
        L->info[0] = valor;
        L->c = L->c + 1;
        printf("Elemento inserido com sucesso\n");
        return 1;
    }else if(L->c < MAX-1) {
        for(int i = L->c; i>=0; i--){// vou percorrer toda a lista de traz para frente
            L->info[i+1] = L->info[i];
        }
        L->info[0] = valor;
        L->c = L->c+1;
        printf("Elemento inserido com sucesso\n");
        return 1;
    }
   
}


//Insere elemento no final da lista
bool insereFinal(Lista *lista, int valor){
 
    //para o tamanho atual do meu vetor
    int arraySize = sizeof(lista->info);
    int intSize = sizeof(lista->info[0]);
    int length = arraySize/intSize;// tamanho do meu vetor info

    if (lista->c == MAX-1){// se minha lista esta cheia
        printf("size: %i\n",length);
        printf("Lista cheia\n");
        system("pause");
        return false;
    }else{// caso nao esteja cheia, quero que insira na ultima posicao vazia
        lista->info[lista->c+1] = valor;
        lista->c = lista->c+1;

        return true;
    }
            
    system("pause");

}

//Insere elemento no meio
void insereMeio(Lista *L, int valor, int pos){

    if (L->c == MAX-1){// se minha lista esta cheia
        printf("Lista cheia, remova um elemento!\n");

    }// caso nao esteja cheia, quero que insira na posicao determinada
    else if(L->c == -1){
        L->info[0] = valor;
        L->c + 1;
    }else {
        for(int i = L->c; i>=pos; i--){// vou percorrer toda a lista de traz para frente
            L->info[i+1] = L->info[i];
        }
        L->info[pos] = valor;
        L->c++;
        printf("elemento inserido com sucesso|\n");
    }
    system("pause");
}

int comparar(const void *p, const void *q) {
    int x = *(const int *)p;
    int y = *(const int *)q;
    return x - y;
}

//Ordenar Lista
void Ordenar(Lista *L){
    int aux;
    int i, j;

    for(i = 0; i <= L->c; i++){
        for(j = 0; j <= L->c; j++){

            if(L->info[j]>L->info[i] ){
                aux = L->info[j];
                L->info[j] = L->info[i];
                L->info[i] = aux;
    
                // assim eh na ordem decrescente
                //if(L->info[i]>L->info[j] ){
                //aux = L->info[i];
                //L->info[i] = L->info[j];
                //L->info[j] = aux;

                // USANDO A FUNÇAO QSORT E COMPARAR
                //if(L->info[i+1]>L->info[i] ){
                //int n = sizeof(L->info) / sizeof(L->info[0]);
                //qsort(L->info, n, sizeof(int), comparar);
                //printf("%d\n",n);
                //break;
            }
        }
    }

    printf("Lista ordenada com sucesso\n");
    system("pause");
}

//Insere elemento Ordenado
void inserirOrdenado(Lista *L, int valor){
  int pos = 0;

    while(pos < L->c && L->info[pos] < valor) {
        pos++;
    } 

    if (L->c == MAX-1){// se minha lista esta cheia
        printf("Lista cheia, remova um elemento!\n");

    }// caso nao esteja cheia, quero que insira na posicao determinada
    else if(L->c == -1){
        L->info[0] = valor;
        L->c + 1;
    }else {
        for(int i = L->c; i>=pos; i--){// vou percorrer toda a lista de traz para frente
            L->info[i+1] = L->info[i];
        }
        L->info[pos] = valor;
        L->c++;
        printf("elemento inserido com sucesso|\n");
    }
    system("pause");
}


void imprimeLista(Lista *L){ //Lista *L

    if (L->c ==-1){
        printf("Lista Vazia!\n");
    }else{
        printf("Lista->");
        for(int i=0; i <= L->c ; i++){
            printf("%d",L->info[i]);
            printf("->");
        }
        printf("NULL\n");
    }
    system("pause");
}

void removeInicio(Lista *L){
    if(L->c == -1){
        printf("Lista Vazia\n");
        printf("Nao eh possivel remover\n");
    }else{
        for(int i = 0; i <= L->c -1; i++){
            L->info[i] = L->info[i+1];
        }
        L->c = L->c - 1;
        printf("elemento removido com sucesso\n");
    }
    system("pause");
}

void removeFim(Lista *lista){
    lista->c = lista->c-1;
    printf("Elemento no final da lista removido com sucesso!\n");
    system("pause");
}

void alteraElem(Lista *L, int valor, int new_valor){
    int count = 0;

    for(int i = 0; i <= L->c; i++){
        if(L->info[i] ==  valor){
            printf("Registro Encontrado na posicao: %i\n",i + 1);
            L->info[i] =  new_valor;
            count += 1;
        }
    }
    if(count==0){
        printf("Registro Nao Encontrado!\n");
        printf("Tente novamente!\n");
    }
    system("pause");
}


void removeElem(Lista *L, int valor){
    int count = 0;
    int pos;

    for(int j = 0; j <= L->c; j++){
        if(L->info[j] ==  valor){
            printf("Registro Encontrado na posicao: %i e removido\n",j + 1);
            pos = j+1;
            for(int i = 0; i <= L->c; i++){
                if(i < j){

                }else{
                    L->info[i] = L->info[i+1];
                }
            }
            count += 1;
            break;
        }    
    }
    L->c = L->c - 1;
    if(count==0){
        printf("Registro Nao Encontrado!\n");
        printf("Tente novamente!\n");
    }
    system("pause");
}



void limparLista(Lista *lista){//Remove todos os nós da Lista
    ConsultaVazia(lista);

    if(lista->c==-1){
        printf("Lista esta vazia!\n");
    }else{
        lista->c = - 1;
        printf("Lista limpa!\n");
    }
    system("pause");
}

void ConsultaVazia(Lista *L){
    if (L->c ==-1){
        printf("Lista criada, mas Vazia!\n");
    }else if(L->c < -1||L->c >MAX){
        printf("Lista NAO criada. Crie uma lista!\n");
    }else{
        printf("Lista iniciada!\n");
        printf("A lista possue %i elementos\n",L->c + 1);
    }
    system("pause");
}


int soma_todos(Lista *L){
    int soma = 0;

    for (int i=0; i<= L->c; i++){
        soma = soma+L->info[i];
    }

    printf("A soma de todos os elementos da lista eh: %d \n", soma);
    system("pause");
    return soma;
    

}