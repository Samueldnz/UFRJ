#include<stdio.h>

typedef struct _TEMPO{

    int hora, minuto, segundo;
}TEMPO;

int comparaTEMPO (TEMPO t1, TEMPO t2);

int main(void){

    TEMPO t1, t2;

    printf("Insira o tempo 1 (somente números): hora, minuto e segundo \n");
    scanf("%d %d %d", &t1.hora, &t1.minuto, &t1.segundo);

    printf("Insita o tempo 2 (somente números): hora, minuto e segundo \n");
    scanf("%d %d %d", &t2.hora, &t2.minuto, &t2.segundo);

    printf("Tempo 1 é maior que Tempo 2 se valor > 1 \n");
    printf("Tempo 1 é igual a Tempo 2 se valor = 0 \n");
    printf("Tempo 1 é menor que Tempo 2 se valor < 0 \n");

    printf("Valor: %d\n", comparaTEMPO(t1, t2));
    
    
    return 0;
}

int comparaTEMPO (TEMPO t1, TEMPO t2){

    int t1_total, t2_total;

    t1_total = t1.hora * 3600 + t1.minuto * 60 + t1.segundo;
    t2_total = t2.hora * 3600 + t2.minuto * 60 + t2.segundo;

    if(t1_total < t2_total){

        return -1;

    }else if(t1_total == t2_total){

        return 0;

    }else{
        return 1;
    }

}