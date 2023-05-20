#include<stdio.h>
#include<stdlib.h>

typedef struct _JOGADOR {

    int pontos;
    char nome[42];
}JOGADOR;

void bubblesearch(JOGADOR **player, int qntd);

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

    bubblesearch(&player, qntd);

    printf("Pontos ordenados: \n");

    for(i = 0; i < qntd; i++){

        printf("A quantidade de pontos foi: %d do jogador ", player[i].pontos);
        puts(player[i].nome);

    }
    free(player);
    return 0;
}

void bubblesearch(JOGADOR **player, int qntd){

    int i, j;
    JOGADOR *bubble_pontos;
   
    bubble_pontos = (JOGADOR *) malloc( qntd * sizeof(JOGADOR));

    for(i = 0; i < qntd - 1; i++){
        for( j =0; j < qntd - 1 - i; j++){

            if((*player[j]).pontos < (*player)[j + 1].pontos){

                bubble_pontos[i] = (*player)[j];
                (*player)[j] = (*player)[j + 1];
                (*player)[j + 1] = bubble_pontos[i];
                
            }
        }
    }

    free(bubble_pontos);
}
