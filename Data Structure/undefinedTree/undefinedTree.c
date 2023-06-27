#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0

typedef int bool;

typedef struct _NODE{
    int chave;
    struct Node* primFilho;
    struct Node* proxIrmao;
}Node;

typedef Node* PONT;


PONT criaNovoNode(int ch){
    PONT novo = (PONT)malloc(sizeof(PONT));
    novo->chave = ch;
    novo->primFilho = NULL;
    novo->proxIrmao = NULL;
    return novo;
}

PONT inicializa(int ch){
    return criaNovoNode(ch);
}

bool insere(PONT raiz, int novaChave, int chavePai){
    PONT pai = buscaChave(chavePai, raiz);
    if(!pai) return FALSE;
    PONT filho = criaNovoNode(novaChave);
    PONT p = pai->primFilho;
    if(!p) pai->primFilho = filho;
    else{
        while(p->proxIrmao)
            p = p->proxIrmao;
        p->proxIrmao = filho;
    }

    return TRUE;
}

void exibirArvore(PONT raiz){
    if (raiz == NULL) return;
    printf("%d(", raiz->chave);
    PONT p = raiz->primFilho;
    while(p){
        exibirArvore(p);
        p = p->proxIrmao;
    }

    printf(")");
}

PONT buscaChave(int ch, PONT raiz){
    if (raiz == NULL) return NULL;
    if (raiz->chave == ch) return raiz;

    PONT p = raiz->primFilho;

    while(p){
        PONT resp = buscaChave(ch, p);
        if(resp) return resp;
        p = p->proxIrmao;
    }

    return NULL;
}

int main(void){
    PONT r = inicializa(8);
    return 0;
}