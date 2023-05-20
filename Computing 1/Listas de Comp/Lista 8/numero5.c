#include<stdio.h>

typedef struct _TEMPO{

    int hora, minuto, segundo;
}TEMPO;

int main(void){

    TEMPO t1, t2;
    int t1_total, t2_total;

    printf("Insira o tempo 1 (somente números): hora, minuto e segundo \n");
    scanf("%d %d %d", &t1.hora, &t1.minuto, &t1.segundo);

    printf("Insita o tempo 2 (somente números): hora, minuto e segundo \n");
    scanf("%d %d %d", &t2.hora, &t2.minuto, &t2.segundo);

    t1_total = t1.hora * 3600 + t1.minuto * 60 + t1.segundo;
    t2_total = t2.hora * 3600 + t2.minuto * 60 + t2.segundo;

    if(t1_total < t2_total){

        printf("Tempo 2 é maior. \n");

    }else if(t1_total == t2_total){

        printf("Os tempos são iguais. \n");

    }else{
        printf("Tempo 1 é maior. \n");
    }
    
    return 0;
}