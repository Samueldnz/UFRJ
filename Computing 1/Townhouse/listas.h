int lista_enc_inserir_bloco(bloco *c, bloco **lista);
bloco *lista_enc_remover_bloco(bloco **lista);
void esvaziar_lista_blocos(bloco **lista_blocos);
int lista_enc_inserir_condominio(condominio *c, condominio **lista);
condominio *lista_enc_remover_condominio(condominio **lista);
void esvaziar_lista_cond(condominio **lista_cond);
int remover_cond_por_nome(char *nome, condominio **lista);
int remover_bloco_por_letra(char c, bloco **lista);
