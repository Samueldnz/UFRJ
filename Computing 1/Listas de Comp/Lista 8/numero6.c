#include<stdio.h>

typedef struct _TEMPO{

    int hora, minuto, segundo;
}TEMPO;

int main(void){

    TEMPO t1, t2, t3;

    printf("Insira o tempo 1 (somente números): hora, minuto e segundo \n");
    scanf("%d %d %d", &t1.hora, &t1.minuto, &t1.segundo);

    printf("Insita o tempo 2 (somente números): hora, minuto e segundo \n");
    scanf("%d %d %d", &t2.hora, &t2.minuto, &t2.segundo);

    t3.segundo = t1.segundo + t2.segundo;
    t3.minuto = t1.minuto + t2.minuto;
    t3.hora = t1.hora + t2.hora;

    if(t3.segundo >= 60){
        t3.minuto++;
        t3.segundo -= 60;
    }

    if(t3.minuto >= 60){
        t3.hora++;
        t3.minuto -= 60;
    }

    printf("A soma dos tempos é: %dh %dmin %dseg \n", t3.hora, t3.minuto, t3.segundo);

    return 0;
}
