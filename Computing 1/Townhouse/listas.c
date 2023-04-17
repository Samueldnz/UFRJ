#include <stdio.h>
#include <stdlib.h>
#include "defs.h"
#include "listas.h"

int lista_enc_inserir_bloco(bloco *c, bloco **lista)
{
    bloco *tmp;

    if (c == NULL) return 0;

    tmp = *lista;
    *lista = c;
    c->prox = tmp;

    return 1;
}

bloco *lista_enc_remover_bloco(bloco **lista)
{
    bloco *tmp;

    tmp = *lista;

    if (*lista != NULL)
    {
        *lista = (*lista)->prox;
        tmp->prox = NULL;
    }

    return tmp;
}

void esvaziar_lista_blocos(bloco **lista_blocos)
{
    while (*lista_blocos != NULL)
        free(lista_enc_remover_bloco(lista_blocos));
}

int lista_enc_inserir_condominio(condominio *c, condominio **lista)
{
    condominio *tmp;

    if (c == NULL) return 0;

    tmp = *lista;
    *lista = c;
    c->prox = tmp;

    return 1;
}

condominio *lista_enc_remover_condominio(condominio **lista)
{
    condominio *tmp;

    tmp = *lista;

    if (*lista != NULL)
    {
        *lista = (*lista)->prox;
        tmp->prox = NULL;
    }

    return tmp;
}

void esvaziar_lista_cond(condominio **lista_cond)
{
    while (*lista_cond != NULL)
    {
        esvaziar_lista_blocos(&((*lista_cond)->lista_blocos));
        free(lista_enc_remover_condominio(lista_cond));
    }
}

int remover_cond_por_nome(char *nome, condominio **lista)
{
    condominio *atual, *anterior;

    atual = *lista;
    if (strcmp(nome, atual->nome) == 0)
    {
        *lista = atual->prox;
        esvaziar_lista_blocos(&(atual->lista_blocos));
        free(atual);
        return 1;
    }

    anterior = atual;
    atual = atual->prox;

    while (atual != NULL)
    {
        if (strcmp(nome, atual->nome) == 0)
        {
            anterior->prox = atual->prox;
            esvaziar_lista_blocos(&(atual->lista_blocos));
            free(atual);
            return 1;
        }

        anterior = atual;
        atual = atual->prox;
    }

    return 0;
}

int remover_bloco_por_letra(char c, bloco **lista)
{
    bloco *anterior, *atual;

    if (c == (*lista)->letra)
    {
        atual = *lista;
        *lista = (*lista)->prox;
        free(atual);
        return 1;
    }

    anterior = *lista;
    atual = (*lista)->prox;

    while (atual != NULL)
    {
        if (atual->letra == c)
        {
            anterior->prox = atual->prox;
            free(atual);
            return 1;
        }

        anterior = atual;
        atual = atual->prox;
    }

    return 0;
}
