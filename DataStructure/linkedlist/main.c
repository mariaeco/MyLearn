/*
PROGRAMA: LISTA ENCADEADA
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
#include "funcoes.h"
#include "menu.h"

int main(int argc, char const *argv[]){

    int choice = 0;
    Lista *lista;
    Pessoa pessoa;

    // MEU MENU PRINCIPAL-------------------------------------------------
    menuPrincipal(choice, lista, pessoa);

    return 0;
}
