/*
MENUS
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"
#include "menu.h"

int menuPrincipal(int choice, Lista *lista, Pessoa pessoa){
    int count = 0;
    do{
        printf ("MEU MENU\n");
        printf("1 - Cria Lista\n");
        printf("2 - Verifica Lista\n");
        printf("3 - Insere no inicio da Lista\n");
        printf("4 - Insere no fim da Lista\n");
        printf("5 - Mostrar Lista\n");
        printf("6 - Alterar cadastro\n");
        printf("7 - Limpar Lista\n");
        printf("8 - Inserir em arquivo\n");
        printf("9 - Ler arquivo\n");
        printf("10 - Ordenar Lista\n");  
        printf("0 - Sair\n");

        scanf("%d", &choice);
        system("cls||clear");

        switch(choice){
            case 1: //CriarLista             
                if(count == 0){
                    criaLista(&lista);
                    inserir_csv_Lista("cadastroEmpresa.csv", &lista);
                    count++;
                }else{
                    printf("Lista já criada e Dados ja inseridos!\n");
                    system("pause");
                }
                system("cls");
                break;
            case 2://VerificaLista
                verificalista(lista);
                system("cls");
                break;
            case 3: //addInicio
                if(listaVazia(lista)){
                    printf("A lista esta vazia\n");
                }else{
                    printf("lista nao vazia\n");
                }            
                get_data(&pessoa, lista);
                insereInicio(&lista, pessoa);
                escrever_arquivo("cadastroEmpresa.csv", &pessoa);
                system("cls");
                break;
            case 4: //addFim         
                get_data(&pessoa, lista);
                insereFim(&lista,pessoa);
                escrever_arquivo("cadastroEmpresa.csv", &pessoa);
                system("cls");
                break;
            case 5: //mostraLista
                mostra(lista);
                system("cls");
                break;
            case 6: //Alterar Cadastro
                alteraCadastro(&lista,"cadastroEmpresa.csv");
                system("cls");
                break;
            case 7: //esvaziarLista
                limparLista(&lista);
                system("cls");
                break;
            case 8: //Escrever no arquivo
                get_data(&pessoa, lista);
                escrever_arquivo("cadastroEmpresa.csv", &pessoa);
                insereFim(&lista,pessoa);
                system("cls");
                break;
            case 9: //ler o arquivo
                ler_csv("cadastroEmpresa.csv");
                system("cls");
                break;
            case 10: //Ordenar
                Ordenar(&lista);
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
    return 1;
}

Pessoa menu_02(int choice,  Lista *ll){
    Pessoa pnova;
    Lista aux = *ll;
    do{
                    printf ("--------- Qual informacao deseja alterar: ----------\n");
                    printf("1 - Nome\n");
                    printf("2 - Idade\n");
                    printf("3 - Altura\n");
                    printf("0 - Retornar ao menu Inicial\n");
                    
                    scanf("%d", &choice);
                    system("cls||clear");

                    switch(choice){
                        case 1: //Altera nome
                            printf("Digite o nome correto:\n");
                            scanf(" %[^\n]%*c",pnova.nome);
                            strcpy(ll->info.nome, pnova.nome);// substituindo o nome na lista por um novo nome
                            pnova.idade = ll->info.idade;// Se eu quiser alterar apenas o nome, eu preciso salvar as outras idades,pq perde
                            pnova.altura = ll->info.altura;
                            printf("Nome alterado com sucesso\n");
                            system("pause");
                            system("cls");
                            break;
                        case 2://Altera idade
                            printf("Digite a idade correta:\n");
                            scanf("%d",&pnova.idade);
                            ll->info.idade = pnova.idade;// substituindo a idade na lista por uma nova idade
                            strcpy(pnova.nome, ll->info.nome);// Se eu quiser alterar apenas a idade, eu preciso salvar o nome Antigo, pq ele perde
                            strcpy(ll->info.nome, pnova.nome);// em seguida, colocar o nome Antigo no pnova.nome
                            pnova.altura = ll->info.altura;
                            printf("Idade com sucesso\n");
                            system("pause");
                            system("cls");
                            break;
                        case 3://Altera altura
                            printf("Digite a altura correta:\n");
                            scanf("%f",&pnova.altura);
                            ll->info.altura = pnova.altura;// substituindo a altura na lista por uma nova altura
                            strcpy(pnova.nome, ll->info.nome);
                            strcpy(ll->info.nome, pnova.nome);
                            pnova.idade = ll->info.idade;
                            printf("Altura alterada com sucesso\n");
                            system("pause");
                            system("cls");
                            break;
                        default:
                            if(choice==0){
                        }
                        printf("Digite uma opcao valida!\n");
                        break;
                    }
                }while(choice!= 0);
    return pnova;
}