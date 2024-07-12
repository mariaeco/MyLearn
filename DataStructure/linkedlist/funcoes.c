//FUNCOES
/* 
    A LISTA ENCADEADA SIMPLES
    Cresce a medida que insiro elementos, com alocação dinamica
    A memoria eh o limite de armazanemaneto, continuo tendo limite, mas a memoria eh o limite
    Na lista simples ela eh unidirecional
    _____________________        _____________________   _____________________
    |__dados___|__prox__|----->  |__dados___|__prox__|-->|__dados___|__prox__|

    prox = ponteiro para o proximo
    O marco inicial Da lita eh uma variavel estatico - vamos chama-la de L;
    Nunca perder a marcação inicial 

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "funcoes.h"
#include "menu.h"



//Funcao de criacao de lista
void criaLista(Lista **ll){ // l que vai apontar para a Lista
    int count = 0;
    *ll = NULL;
    printf("Lista criada!\n");
    system("pause");
    return ;
}

int listaVazia(Lista *ll){
    return (ll==NULL);// retorna true se a lista estiver vazia
}

int is_list_created(Lista* ll) {// nao estou usando, preciso verificar melhor essa funcao
    return (ll != NULL); 
    // Retorna true foi criada,
    // caso contrário retorna false, nao foi criada
}

_Bool verificalista(Lista *ll){
    int tam = 0;
    
    if(listaVazia(ll)){
        printf("Lista Vazia!\n");
        system("pause");
        return true;
    } 
    else{
        //caso queira verificar o tamanho da lista 
        while (ll != NULL) {
           ll = ll->proximo;
           tam++;
        }
        printf("tamanho da lista %d\n", tam);
        system("pause");
        return false;
    }
}

void get_data(Pessoa *pessoa, Lista *ll){ // obtem os dados do usuario
//fgets(pessoa.nome, MAX_LIMIT, stdin);
    printf ("Digite o nome: ");
    //fgets(pessoa->nome, sizeof(pessoa->nome), stdin);//nao ta funcionando
    scanf(" %[^\n]%*c",pessoa->nome);
    printf ("Digite a idade: ");
    scanf("%i",&pessoa->idade);
    printf ("Digite a altura: ");
    scanf("%f",&pessoa->altura);
    pessoa->Ncadastro = consultaUltimoCadastro(ll)+1;
    getchar();
}

// Função para trocar os valores de dois nós
void trocar(Lista *a, Lista* b) {
    Pessoa aux;
    aux = a->info;
    a->info = b->info;
    b->info = aux;
}

//Ordenar Lista
void Ordenar(Lista **ll){
    int troca;
    Lista *no_atual;
    Lista *no_anterior = NULL;

    // Verifica se a lista está vazia ou possui apenas um elemento
    if ((*ll) == NULL || (*ll)->proximo == NULL) {
        return;
    }
    
    do {
        troca = 0;
        no_atual = *ll;

        // Percorre a lista encadeada comparando elementos adjacentes e trocando-os se estiverem fora de ordem
        while (no_atual->proximo != no_anterior) {
            if (no_atual->info.Ncadastro > no_atual->proximo->info.Ncadastro) {
                trocar(no_atual, no_atual->proximo);
                troca = 1;
            }
            no_atual = no_atual->proximo;
        }
        no_anterior = no_atual;

    } while (troca);

    //printf("Lista ordenada com sucesso\n");
    //system("pause");
}


int consultaUltimoCadastro(Lista *ll){
    int ultimo = ll->info.Ncadastro;
    Ordenar(&ll);

    if(verificalista(ll)){
    }
    else{
        while (ll != NULL) {
            if (ll->info.Ncadastro > ultimo) {
            ultimo = ll->info.Ncadastro;
            //printf("Cadastro: %d\n", ultimo);
            }
        ll = ll->proximo;
        }
    } 
    return ultimo;
    //system("pause");  
}


int insereInicio(Lista **ll, Pessoa pessoa){
    Lista *novo;

    novo = (Lista *)malloc(sizeof(Lista));
    if(!novo){
        return 0;
    }
    novo->info = pessoa;
    novo->proximo = *ll;
    *ll = novo;     

    return 1;
}

int insereFim(Lista **ll, Pessoa pessoa){
    Lista *novo, *aux;

    novo = (Lista *)malloc(sizeof(Lista));
    
    if(novo){// se novo existe, lista novo recebe o valor e aponta para null 
        novo->info= pessoa;
        novo->proximo = NULL; 
        if(*ll == NULL){ // se nossa lista ainda não tem elementos, vamos receber o valor da lista novo.
            *ll = novo;
         }else{// nao eh o primeiro no
            aux = *ll;
            while(aux->proximo){//enquanto existir um proximo ponto
                aux = aux->proximo; // caminha ate o final
            }
            aux->proximo = novo;// chegou ao final, cria um próximo no.
        }
    }else{
        printf("Erro na alocacao!\n");
        return 0;
    }
    return 1;
}

int alteraCadastro(Lista **ll, const char* nome_arquivo) {
    int encontrado = 0;
    int choice = 0;
    char nomeAntigo[MAX_LIMIT];
    Pessoa pnova;
    int linha = 1;
    char linhaLIDA[TAM_MAX_LINHA];
    Lista *aux, *(aux2);

    aux = *ll;//MINHA LISTA AUXILIAR
    aux2 = *ll;
    if(verificalista(aux)){
    }
    else{
        printf ("Digite o nome do cadastro que deseja alterar: ");
        scanf(" %[^\n]%*c",nomeAntigo);
        while (aux != NULL) {
            printf("\n\nNUMERO da LINHA: %i\n",linha);
            if (strcmp(aux->info.nome, nomeAntigo) == 0) {
                printf("---------- Cadastro encontrado:---------- \n");
                // 1)imprimir cadastro
                printf("Numero de Cadastro: %d\nNome: %s\nIdade: %d\nAltura: %.2f\n\n",
                aux->info.Ncadastro,aux->info.nome, aux->info.idade, aux->info.altura);
                sprintf(linhaLIDA, "%s,%d,%.2f,%d", aux->info.nome, aux->info.idade, aux->info.altura, aux->info.Ncadastro);
                // 2) Escolher qual informaçao do cadastro deseja alterar E altero na lista dentro mesmo da funcao menu
                pnova = menu_02(choice, aux); // dentro do arquivo menu.c chamado pelo menu.h
                pnova.Ncadastro = aux->info.Ncadastro;
                // 3) Alterar no arquivo
                // 4) imprimir cadastro alterado
                encontrado = 1;
                break; // Encerra o loop após achar o nome e alterar
                system("pause");
            }
            aux = aux->proximo;
            //aux2 = aux2->proximo;
            linha++;
        }
    }
    if (encontrado==1){
       // alteraArquivo(linhaLIDA, nome_arquivo,  pnova);
       deletarLinhaCSV(nome_arquivo, linha, &pnova);
    }
    
    if (!encontrado) {
        printf("Cadastro NAO encontrado.\n");
        system("pause");
    }
}

void deletarLinhaCSV(const char* nomeArquivo, int linha, const Pessoa *alterada) {
    //Nao acho essa funcao tao eficiente pois faz uma copia, em arquivos grandes demais, talvez torne demorado
    //em SQL posso fazer isso de forma independente sem precisar de copia
    // Abrir o arquivo em modo de leitura
    FILE* arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    // Criar um arquivo temporário para escrever os dados sem a linha deletada
    FILE* arquivoTemp = fopen("temp.csv", "w");
    if (arquivoTemp == NULL) {
        printf("Erro ao criar arquivo temporário.\n");
        fclose(arquivo);
        return;
    }

    char linhaAtual[1000]; // Tamanho máximo da linha do CSV
    int contador = 1;

    // Copiar as linhas do arquivo original para o arquivo temporário, exceto a linha a ser deletada
    while (fgets(linhaAtual, sizeof(linhaAtual), arquivo) != NULL) {
        if (contador != linha) { // AQUI EU PEGO TODAS AS LINHAS EXCETO A LINHA QUE DESEJO DELETAR E COLOCO NO ARQUIVO TEMP
            fputs(linhaAtual, arquivoTemp);
        }
        else{//escrever novo cadastro  na linha desejadaz
            fprintf(arquivoTemp,"%s,%d,%.2f,%d\n", 
            alterada->nome, alterada->idade, alterada->altura,alterada->Ncadastro);
        }
        contador++;
    }
    //agora abro o arquivo no modo apend.
    //escrever_arquivo(nomeArquivo, alterada);

    // Fechar os arquivos
    fclose(arquivo);
    fclose(arquivoTemp);

    // Remover o arquivo original
    remove(nomeArquivo);
    // Renomear o arquivo temporário para o nome original
    if (rename("temp.csv", nomeArquivo) != 0) {
        printf("Erro ao renomear arquivo temporário.\n");
    } else {
        printf("Linha %d deletada com sucesso.\n", linha);
    }

}


int ler_csv(const char* nome_arquivo) {
    FILE* arquivo = fopen(nome_arquivo, "r");
    char linha[TAM_MAX_LINHA];

    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo %s\n", nome_arquivo);
        return 0;
    }
    
    while (fgets(linha, TAM_MAX_LINHA, arquivo) != NULL) {
        // Extrai os dados da linha do arquivo CSV
        int cadastro = atoi(strtok(NULL, ","));
        char* nome = strtok(linha, ",");
        int idade = atoi(strtok(NULL, ","));
        float altura = atof(strtok(NULL, ","));

        // Cria uma nova estrutura Pessoa com os dados lidos
        Pessoa pessoa;
        strcpy(pessoa.nome, nome);
        pessoa.idade = idade;
        pessoa.altura = altura;
        pessoa.Ncadastro = cadastro;

        printf("Cadastro: %d\nNome: %s\nIdade: %d\nAltura: %.2f\n\n",
        pessoa.Ncadastro,pessoa.nome, pessoa.idade, pessoa.altura);
    }
    system("pause");
    fclose(arquivo);
    return 1;
}



int inserir_csv_Lista(const char* nome_arquivo, Lista **lista) {
        FILE* arquivo = fopen(nome_arquivo, "r");
        char linha[TAM_MAX_LINHA];

        if (arquivo == NULL) {
            printf("Erro ao abrir arquivo %s\n", nome_arquivo);
            system("pause");
            return 0;
        }
        
        while (fgets(linha, TAM_MAX_LINHA, arquivo) != NULL) {
            // Extrai os dados da linha do arquivo CSV
            char* nome = strtok(linha, ",");
            int idade = atoi(strtok(NULL, ","));
            float altura = atof(strtok(NULL, ","));
            int cadastro = atoi(strtok(NULL, ","));

            // Cria uma nova estrutura Pessoa com os dados lidos
            Pessoa pessoa;
            strcpy(pessoa.nome, nome);
            pessoa.idade = idade;
            pessoa.altura = altura;
            pessoa.Ncadastro = cadastro;

            // Insere a nova pessoa na lista encadeada
            insereFim(lista, pessoa);
        }

    fclose(arquivo);
    return 1;
}


int escrever_arquivo(const char* nome_arquivo, const Pessoa* pessoa){
        FILE * arq=  fopen(nome_arquivo, "a"); // r+ e w+ nao adicionam no final, sobrescrevem
        // abre o arquivo para escrita no modo append (adiciona ao final)
        if(arq != NULL){
            fprintf(arq, "%s,%d,%.2f,%d\n", pessoa->nome, pessoa->idade, pessoa->altura,pessoa->Ncadastro);
            fclose(arq); // fecha o arquivo
        }
        else{
            printf("\nErro ao abrir o arquivo para leitura!\n");
            system("pause");
            exit(1); // aborta o programa
        }
    return 1;
}

void mostra(Lista *ll){
    if(listaVazia(ll)){
    }
    else{
        while (ll != NULL) {
            printf("Cadastro: %d\nNome: %s\nIdade: %d\nAltura: %.2f\n\n",
            ll->info.Ncadastro,ll->info.nome, ll->info.idade, ll->info.altura);
            ll = ll->proximo;
        }
        system("pause");
    }
}


void limparLista(Lista **ll){
    if(listaVazia(*ll)){
    }
    else{
        Lista *aux; // cria uma copia para nao perder o endereço
        while(*ll){
            aux = *ll;
            *ll = (*ll)->proximo;
            free(aux);
        }
        //printf("Lista Esvaziada\n");
        //system("pause");
    }
}
