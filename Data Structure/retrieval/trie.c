#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TRUE 1
#define FALSE 0
#define N_ALFABETO 26

typedef int bool;
typedef bool TIPORET;

typedef struct NODE{
    struct Node* filhos[N_ALFABETO];
    TIPORET fim;
}Node;

typedef Node* PONT;

PONT criaNo(void){
    PONT p = NULL;

    p = (PONT)malloc(sizeof(Node));

    /*cria o nó "cabeça", diz que não é fim de uma chave e cada filho ficará apontado para NULL*/
    if(p){
        p->fim = FALSE;
        int i;
        for(i = 0; i < N_ALFABETO; i++)
            p->filhos[i] = NULL;
    }

    return p;
}

PONT inicializa(void){
    return criaNo();
}

int mapearIndice(char c){
    return ((int)c - (int)'a');
}

int main(void){
    PONT r = inicializa();
    return 0;
}