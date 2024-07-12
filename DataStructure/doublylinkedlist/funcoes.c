//FUNCOES
/* 
    A LISTA DUPLAMENTE ENCADEADA DINAMICA
    __________________________        ___________________________   ___________________________
    __amt_|__dados___|__prox__|----->__ant__|__dados___|__prox__|-->__ant_|__dados___|__prox__|

    OBSERVACAO: observe que sempre nas funcoes utilizo **ll
    Como na main, minha lista eh definida como Lista *lista, sempre entrara na funcao um endereco de memoria,
    *lista eh um endereco de memora. Se Na fucao estiver *ll entao eu estou pegando o valor de *lista e fazendo uma copia.
    Agora se eu faco **ll eu pego o endereco de listam e altero a lista, nao faco uma copia, altero a propria lista.
    As funcoes em que altero devem sempre ter como entrada **ll

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"



//Funcao de criacao de lista
void criaLista(Lista **ll){ // l que vai apontar para a Lista
  
    *ll = NULL; // ou 0
    printf("Lista criada!\n");

    system("pause");
    return ;

}

Lista* criarNo(int valor) {
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    if (novo == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    novo->info = valor;
    novo->anterior = NULL;// acrescento apenas essa linha em relacao a lista encadeada simples
    novo->proximo = NULL;
    return novo;
}

int listaVazia(Lista *ll){
    return (ll==NULL);
}

int insereInicio(Lista **ll, int valor){
    // nao muda nada desta funcao em relacao a lista encadeada simples
    Lista *nova = criarNo(valor);

    if (*ll == NULL) {
        *ll = nova;
    } else {
        nova->proximo = *ll;
        *ll = nova;
    }
    system("pause");
    return 1;
}

int insereOrdenado(Lista** ll, int valor){  // modificado em relacao a lista encadeada simples
    Lista* novo = criarNo(valor);
    Lista *aux;

    if(*ll == NULL){// Se vazia
        novo->proximo = NULL;
        novo->proximo = NULL;
        *ll = novo;
    }else if(valor < (*ll)->info){// se o valor for menor
        novo->proximo = *ll;
        (*ll)->anterior = novo;
        *ll = novo;
    }else{
        aux = *ll;
        while(aux->proximo && valor>aux->proximo->info){
            aux = aux->proximo;
        }
        novo->proximo = aux->proximo;
        if(aux->proximo){
            aux->proximo->anterior = novo;
        }
        novo->anterior = aux;
        aux->proximo = novo;
    }

     return 1;
}

int insereFim(Lista **ll, int valor){
    Lista *novo, *atual;
    novo = criarNo(valor);

    if(*ll == NULL){ 
        *ll = novo;
    }else{
        atual = *ll;
        while(atual->proximo !=NULL){
            atual = atual->proximo; 
        }
        atual->proximo = novo;
        novo->anterior = atual;// acrescento apenas essa linha em relacao a lista encadeada simples
    }
    system("pause");
    return 1;
}

//Ordenar Lista
void Ordenar(Lista **ll){// mudou bastante
    int troca;
    Lista *atual;
    Lista *anterior = NULL;
    Lista *aux;

    // Verifica se a lista está vazia ou possui apenas um elemento
    if (*ll == NULL || (*ll)->proximo == NULL) {
        printf("lista vazia ou apenas um elemento");
        return;
    }
   
    do {
        troca = 0;
        atual = *ll;

        while(atual->proximo != NULL){
            if(atual->info > atual->proximo->info){
                aux = atual->proximo;
                atual->proximo = aux->proximo;
                aux->anterior = atual->anterior;
                
                if(atual->proximo != NULL){
                    atual->proximo->anterior = atual;
                }
                if(atual->anterior != NULL){
                    atual->anterior->proximo = aux;
                }else{
                    *ll = aux;
                }
                aux->proximo = atual;
                atual->anterior = aux;
                troca = 1;
            }else{
                atual = atual->proximo;
            }
        }
    } while (troca);
}

void mostra(Lista *ll){
    Lista *aux; 
    aux = ll;
    if(listaVazia(ll)){
        printf("Lista Vazia!\n");
    }
    else{
        for(aux == ll; aux != NULL; aux=aux->proximo){
            printf("%d",aux->info);
            printf("->");
            //printf("%d\n",(*ll).info);// eh a mesma coisa
        }
        printf("NULL\n");
    }
    system("pause");
}


void limparLista(Lista **ll){// sem diferenca da lista encadeada simples
    Lista *aux; // cria uma copia para nao perder o endereço
    while(*ll){
        aux = *ll;
        *ll = (*ll)->proximo;
        free(aux);

    }
    system("pause");
}

void removerInicio(Lista** ll) {
    if (*ll == NULL) {
        printf("A lista está vazia.\n");
        return;
    }
    Lista* aux = *ll;
    *ll = (*ll)->proximo;
    if (*ll != NULL) { // incluo esse if em relacao a lista encadeada simples
        (*ll)->anterior = NULL;
    }
    free(aux);
}

// Função para remover o último elemento da lista
void removerFim(Lista** ll) {
    if (*ll == NULL) {
        printf("A lista está vazia.\n");
        return;
    }
    // modifico bastante essa parte em relacao a lista simples
    Lista* atual = *ll;
    while (atual->proximo != NULL) {
        atual = atual->proximo;
    }
    if (atual->anterior == NULL) {
        // Único elemento na lista
        *ll = NULL;
    } else {
        atual->anterior->proximo = NULL;
    }

    free(atual);
}


// Função para remover um elemento específico da lista
void removerElemento(Lista** ll, int valor) {
    if (*ll == NULL) {
        printf("A lista está vazia.\n");
        return;
    }

    Lista* atual = *ll;
    Lista* anterior = NULL;

    // Percorrer a lista até encontrar o elemento
    while (atual != NULL && atual->info != valor) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) {
        printf("Elemento não encontrado na lista.\n");
        return;
    }

    // Remover o nó contendo o elemento
    if (anterior == NULL) {
        *ll = (*ll)->proximo;
    } else {
        anterior->proximo = atual->proximo;
    }
    free(atual);
}

