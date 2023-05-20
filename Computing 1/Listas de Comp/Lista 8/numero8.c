#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct _TEMPO{

    int hora, minuto, segundo;
}TEMPO;

void LeVetor(TEMPO **vetor_temp, int tam);
int* comparaTEMPO (TEMPO *vetor_temp, int tam);
void bubblesort(int **vetor_temp_total, int tam);
TEMPO* converter_tempo(int *vetor_temp_total, int tam);
void output_tempoOrdenado(TEMPO *tempo_ordenado, int tam);

int main(void){

    TEMPO *vetor_temp;
    int tam, i;

    printf("Digite a quantidade de tempos que irá inserir: ");
    scanf("%d", &tam);

    vetor_temp = (TEMPO *) malloc(tam * sizeof(TEMPO));
    if (!vetor_temp) {
        printf("Erro de alocação de memória\n");
        return 1;
    }

    for(i = 0; i < tam; i++){

        printf("\nInsira os valores de tempo %d: hora, minuto e segundo\n", i + 1);
        scanf("%d %d %d", &vetor_temp[i].hora, &vetor_temp[i].minuto, &vetor_temp[i].segundo);
    }
 
    int* vetor_temp_total = comparaTEMPO (vetor_temp, tam);

    bubblesort(&vetor_temp_total, tam);

    TEMPO *tempo_ordenado = converter_tempo(vetor_temp_total, tam);

    printf("Tempos ordenados: \n");
    for(i = 0; i < tam; i++){

        printf("%dh %dmin %dseg \n", tempo_ordenado[i].hora, 
                                    tempo_ordenado[i].minuto, 
                                    tempo_ordenado[i].segundo);

    }

    free(vetor_temp);
    free(vetor_temp_total);
    free(tempo_ordenado);

    return 0;
}

int* comparaTEMPO (TEMPO *vetor_temp, int tam){

    int *vetor_temp_total, i;

    vetor_temp_total = (int *) malloc(tam * sizeof(int));

    for(i = 0; i < tam; i++){

        vetor_temp_total[i] = vetor_temp[i].hora*3600 + 
                                vetor_temp[i].minuto*60 + 
                                vetor_temp[i].segundo;

    }

    return vetor_temp_total;
}

void bubblesort(int **vetor_temp_total, int tam){

    int i, j, bubble;

    for(i = 0; i < tam - 1; i++){
        for( j =0; j < tam - 1 - i; j++){

            if((*vetor_temp_total)[j] > (*vetor_temp_total)[j + 1]){

                bubble = (*vetor_temp_total)[j];
                (*vetor_temp_total)[j] = (*vetor_temp_total)[j + 1];
                (*vetor_temp_total)[j + 1] = bubble;

            }
        }
    }
}

TEMPO* converter_tempo(int *vetor_temp_total, int tam){

    int i;
    TEMPO *tempo_ordenado;

    tempo_ordenado = (TEMPO *) malloc(tam * sizeof(TEMPO));
    if (!tempo_ordenado) {
        printf("Erro de alocação de memória\n");
        exit(1);
    }

    for(i = 0; i < tam; i++){

        tempo_ordenado[i].hora = vetor_temp_total[i]/3600;
        tempo_ordenado[i].minuto = fmod(vetor_temp_total[i],3600)/60;
        tempo_ordenado[i].segundo = fmod(fmod(vetor_temp_total[i], 3600), 60);

    }
    return tempo_ordenado;
}




