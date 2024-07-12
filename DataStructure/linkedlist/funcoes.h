#ifndef FUNCOES_H
#define FUNCOES_H

#define MAX_LIMIT 100
#define TAM_MAX_LINHA 100

typedef struct {
    char nome[MAX_LIMIT];
    int Ncadastro; //numero de cadastro na empresa
    int idade;
    float altura;
} Pessoa;         

typedef struct no{
    Pessoa info;
    struct no* proximo; // na propria estrutura eu aponto para alguem do mesmo tipo dela
} Lista;

/*
typedef struct no Lista; posso usar assim caso eu não faça com typedef
*/

void criaLista(Lista **ll);
_Bool verificalista(Lista *ll);
int listaVazia(Lista *ll);
int is_list_created(Lista *ll);
void get_data(Pessoa *pessoa, Lista *ll);
int insereInicio(Lista **ll, Pessoa pessoa);
int insereFim(Lista **ll, Pessoa pessoa);
int alteraCadastro(Lista **ll, const char* nome_arquivo);
void mostra(Lista *ll);
void limparLista(Lista **ll);
int ler_csv(const char* nome_arquivo);
int escrever_arquivo(const char* nome_arquivo,const Pessoa* pessoa);
int inserir_csv_Lista(const char* nome_arquivo, Lista **lista);
void trocar(Lista *a, Lista* b) ;
void Ordenar(Lista **ll);
int consultaUltimoCadastro(Lista *ll);
int alteraArquivo(char linha[TAM_MAX_LINHA], const char* nome_arquivo, Pessoa pnova);
void deletarLinhaCSV(const char* nomeArquivo, int linha, const Pessoa * pessoa);
#endif // FUNCOES_H