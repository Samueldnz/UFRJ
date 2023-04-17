#include "defs.h"

void imprimir_condominio(condominio *cond)
{
    bloco *ptr_bloco;

    printf("\nDados sobre condomínio %s:\n\n", cond->nome);
    printf("\t*Endereço: %s, %d\n",
            cond->endereco_condominio.rua,
            cond->endereco_condominio.num);

    ptr_bloco = cond->lista_blocos;
    while (ptr_bloco != NULL)
    {
        printf("\t*Bloco %c:\n", ptr_bloco->letra);
        printf("\t *%d andares\n", ptr_bloco->qtd_andares);
        printf("\t *%d apartamentos por andar\n\n", ptr_bloco->qtd_apts);
        ptr_bloco = ptr_bloco->prox;
    }

    printf("\n");
}

condominio *criar_novo_condominio(
        char *nome,
        char *rua,
        int num_rua,
        int qtd_blocos,
        int *qtd_andares,
        int *qtd_apts)
{
    int i;
    char c;

    bloco *nova_lista_blocos, *novo_bloco;
    condominio *novo_cond;

    novo_cond = (condominio *) malloc(sizeof(condominio));
    if (novo_cond == NULL) return NULL;

    nova_lista_blocos = NULL;
    for (i = 0, c = 'A'; i < qtd_blocos; i++)
    {
        novo_bloco = criar_novo_bloco((char) c + i, qtd_andares[i], qtd_apts[i]);

        if (!(lista_enc_inserir_bloco(novo_bloco, &nova_lista_blocos))) 
        {
            esvaziar_lista_blocos(&nova_lista_blocos);
            free(novo_cond);
            return NULL;
        }
    }

    novo_cond->lista_blocos = nova_lista_blocos;

    strcpy(novo_cond->nome, nome);
    strcpy(novo_cond->endereco_condominio.rua, rua);
    novo_cond->endereco_condominio.num = num_rua;
    novo_cond->prox = NULL;

    return novo_cond;
}

bloco *criar_novo_bloco(char letra, int qtd_andares, int qtd_apts)
{
    bloco *novo_bloco;
    novo_bloco = (bloco *) malloc(sizeof(bloco));
    if (novo_bloco == NULL) return NULL;

    novo_bloco->letra = letra;
    novo_bloco->qtd_andares = qtd_andares;
    novo_bloco->qtd_apts = qtd_apts;
    novo_bloco->prox = NULL;

    return novo_bloco;
}

int *criar_vetor_andares(int num_blocos)
{
    int *vetor_andares, i;
    vetor_andares = (int *)malloc(sizeof(int) * num_blocos);

    for (i = 0; i < num_blocos; i++)
    {
        printf("Bloco %d:\n", i + 1);
        vetor_andares[i] = get_int(1, MAX_ANDARES, "Numero de andares: ");
    }
    
    return vetor_andares;
}

int *criar_vetor_apts(int num_blocos)
{
    int *vetor_apts, i;
    vetor_apts = (int *)malloc(sizeof(int) * num_blocos);

    for (i = 0; i < num_blocos; i++)
    {
        printf("Bloco %d:\n", i + 1);
        vetor_apts[i] = get_int(1, MAX_APTS, "Numero de apartamentos por andar: ");
    }
    
    return vetor_apts;
}

condominio *buscar_por_condominio(condominio *lista, char *condominio_a_procurar)
{

    while (lista != NULL){

        if (strcmp(lista->nome, condominio_a_procurar) != 0)
        {
            lista = lista->prox;
            
        }else return lista;
    }

    return NULL;
}

void renomear_blocos(bloco *lista)
{
    char c = 'A';

    while (lista != NULL)
    {
        lista->letra = c;
        c++;
        lista = lista->prox;
    }
}

int contar_blocos(bloco *lista)
{
    int i = 0;

    while (lista != NULL)
    {
        i++;
        lista = lista->prox;
    }

    return i;
}

bloco *buscar_bloco_por_letra(char c, bloco *lista)
{
    while (lista != NULL)
    {
        if (lista->letra == c) return lista;
        lista = lista->prox;
    }

    return NULL;
}

condominio *buscar_cond_por_nome(condominio *lista)
{
    condominio *cond;
    char *c = get_string(MAX_CHARS, "Inserir nome do condomínio: ");

    cond = buscar_por_condominio(lista, c);

    if (cond == NULL)
    {
        return NULL;

    }else {
        return cond;
    }
}