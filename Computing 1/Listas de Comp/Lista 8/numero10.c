#include<stdio.h>
#include<stdlib.h>

typedef struct _JOGADOR {

    int pontos;
    char nome[42];
}JOGADOR;

int main(void){

    JOGADOR *player;
    int qntd, i;

    printf("Digite a quantidade de jogadores: ");
    scanf("%d", &qntd);
    getchar();

    player = (JOGADOR *) malloc(qntd * sizeof(JOGADOR));

    for(i = 0; i < qntd; i++){

        printf("\nInsira a quantidade de pontos e o nome do jogador %d: \n", i + 1);
        scanf("%d", &player[i].pontos);
        getchar();
        fgets(player[i].nome, 42, stdin);
         
    }

    for(i = 0; i < qntd; i++){

        printf("A quantidade de pontos foi: %d do jogador ", player[i].pontos);
        puts(player[i].nome);
    }

    free(player);
    return 0;
}