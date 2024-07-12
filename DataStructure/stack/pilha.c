//FUNCOES
/* 
    PILHA
    O PRIMEIRO A ENTRAR EH O  ULTIMO A SAIR
    IMPLEMENTAÇÃO DE PILHA USANDO LISTA

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"


Pessoa get_data(){
    Pessoa p;

    printf("\n--- INSIRA OS DADOS PARA CADASTRO ----\n");
    printf ("Digite o nome completo: ");
    scanf(" %[^\n]%*c", p.nome);//scanf(" %[^\n]%*c",p->nome);//outra forma
    printf ("Digite a idade: ");
    scanf("%i",&p.idade);
    printf ("Digite a data de nascimento dd/mm/aaaa: ");
    scanf("%d/%d/%d",&p.data.dia,&p.data.mes,&p.data.ano);

    printf("\n\tInformacoes de Cadastro:\n");
    printf("Nome:%s\n", p.nome);
    printf("Idade:%d\n", p.idade);
    printf("Data de Nascimento:%d/%d/%d\n\n", p.data.dia, p.data.mes,p.data.ano);
   
    system("pause");
    return p;
}

void imprimirDado(Pessoa p){
    printf("\n\tInformacoes de Cadastro:\n");
    printf("Nome:%s\n", p.nome);
    printf("Idade:%d\n", p.idade);
    printf("Data de Nascimento:%d/%d/%d\n\n", p.data.dia, p.data.mes,p.data.ano);
}

//Funcao de criacao de Pilha
void criaPilha(Lista **topo){ //
  
    *topo = NULL; // ou 0
    printf("Lista criada!\n");

    system("pause");
    return ;

}

int pilhaVazia(Lista *topo){
    return (topo==NULL);
}

//FUNCAO PARA EMPILHAR (push)
Lista* empilhar(Lista *topo) { // quase igual cria nó da lista dupla
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    if (novo == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }else{
        novo->info = get_data();
        novo->proximo = topo;
    }
    return novo;
}

//FUNCAO PARA DESEMPILHAR (pop)
Lista* desempilhar(Lista **topo){
    if(*topo != NULL){
        Lista *remover = *topo;
        *topo = remover->proximo;
        free(remover);
        printf("\nElemento removido com sucesso\n");
        return remover;
    }else{
        printf("Pilha Vazia!\n");
        return NULL;
    }
    system("pause");
}

void limparLista(Lista **topo){
    Lista *remover; // cria uma copia para nao perder o endereço
    while(*topo){
        remover = *topo;
        *topo = remover->proximo;
        free(remover);
    }
    if(*topo == NULL){
        printf("\nPilha deletada com sucesso\n");
    }
    system("pause");
}

void mostra(Lista *topo){
    printf("\n------------- PILHA ------------------");
    while(topo){
        imprimirDado(topo->info);
        topo = topo->proximo;
    }
    printf("\n---------- FIM DA PILHA -------------\n");
    system("pause");
}

