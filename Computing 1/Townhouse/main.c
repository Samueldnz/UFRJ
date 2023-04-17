#include "defs.h"
#include "mainfuncs.h"

int main(void)
{
    condominio *lista_condominios;
    FILE *arquivo_lista;

    system("clear");

    arquivo_lista = fopen(LISTA_PATH, "r");
    if (arquivo_lista)
    {
        lista_condominios = ler_arquivo_salvo(arquivo_lista);
        fclose(arquivo_lista);
    }
    else
    {
        printf("Nenhum arquivo salvo encontrado, criando novo arquivo...\n");

        arquivo_lista = fopen(LISTA_PATH, "w");
        if (arquivo_lista == NULL)
        {
            printf("Não foi possível criar arquivo, encerrando programa.\n");
            return 1;
        }

        fclose(arquivo_lista);
        lista_condominios = NULL;
    }

    printf("\n\nBem-vindo ao Sistema de Controle da Imobiliária Tabajara\n\n");
    printf("(versão beta 0.5)\n\n");

    while(1)
    {
        switch (menu_principal())
        {
            case 1: /*inseir condomínio*/
                inserir_condominio(&lista_condominios);
                break;

            case 2: /*remover condomínio*/
                remover_condominio(&lista_condominios);
                break;

            case 3: /*inserir bloco*/
                inserir_bloco(lista_condominios);
                break;

            case 4: /*remover bloco*/
                remover_bloco(lista_condominios);
                break;

            case 5: /*editar bloco*/
                editar_bloco(lista_condominios);
                break;

            case 6: /*consultar condomio*/
                consultar_por_condominio(lista_condominios);
                break;

            case 7: /*listar condominio*/
                imprimir_lista_condominial(lista_condominios);
                break;

            case 8: /*salvar e sair*/
                arquivo_lista = fopen(LISTA_PATH, "w");
                salvar_lista(lista_condominios, arquivo_lista);
                fclose(arquivo_lista);
                return 0;
        }

        printf("Aperte Enter para voltar ao menu inicial\n");
        input_flush();

        system("clear");
    }
}

