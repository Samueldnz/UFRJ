#include<stdio.h>

typedef struct _PONTO{

    float x, y;
}PONTO;

typedef struct _CIRCUNFERENCIA{
    float raio;
    PONTO centro;
}CIRCUNFERENCIA;

int main(void){

    CIRCUNFERENCIA c1;

    printf("Entre com o raio do círculo c1. \n");
    scanf("%f", &c1.raio);

    printf("Entre com as coordenadas do centro do círculo c1. \n");
    scanf("%f %f", &c1.centro.x, &c1.centro.y);

    printf("Dados lidos: \n");
    printf("Círculo c1: raio = %f, Coordenados do Centro: x = %f, y = %f\n", 
                                            c1.raio, c1.centro.x, c1.centro.y);

    return 0;  
}