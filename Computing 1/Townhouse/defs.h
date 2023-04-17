#ifndef DEFS_H
#define DEFS_H

#define MAX_CHARS 41
#define MAX_ANDARES 163
#define MAX_APTS 20
#define MAX_ALPHA 26
#define LISTA_PATH "./savefile"

typedef struct _ENDERECO
{
    char rua[MAX_CHARS];
    int num;
} endereco;

typedef struct _BLOCO
{
    char letra;
    int qtd_andares;
    int qtd_apts;
    struct _BLOCO *prox;
}bloco;

typedef struct _CONDOMINIO
{
    char nome[MAX_CHARS];
    endereco endereco_condominio;
    bloco *lista_blocos;
    struct _CONDOMINIO *prox;
}condominio;

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "defs.h"
#include "helpers.h"
#include "utils.h"
#include "listas.h"

#endif

