void imprimir_condominio(condominio *cond);
condominio *criar_novo_condominio(
        char *nome,
        char *rua,
        int num_rua,
        int qtd_blocos,
        int *qtd_andares,
        int *qtd_apts);
bloco *criar_novo_bloco(char letra, int qtd_andares, int qtd_apts);
int *criar_vetor_andares(int num_blocos);
int *criar_vetor_apts(int num_blocos);
condominio *buscar_por_condominio(condominio *lista, char *condominio_a_procurar);
void renomear_blocos(bloco *lista);
int contar_blocos(bloco *lista);
bloco *buscar_bloco_por_letra(char c, bloco *lista);
condominio *buscar_cond_por_nome(condominio *lista);