#include<stdio.h>
#include<math.h>

typedef struct _PONTO{

    float x, y;
}PONTO;

typedef struct _CIRCUNFERENCIA{
    float raio;
    PONTO centro;
}CIRCUNFERENCIA;

float distancia_xy (PONTO p1, CIRCUNFERENCIA c1);

int main(void){

    PONTO p1;
    CIRCUNFERENCIA c1;

    printf("Entre com o raio do círculo c1. \n");
    scanf("%f", &c1.raio);

    printf("Entre com as coordenadas do centro do círculo c1. \n");
    scanf("%f %f", &c1.centro.x, &c1.centro.y);

    printf("Insira as coordenadas x e y do ponto p1. \n");
    scanf("%f %f", &p1.x, &p1.y);

    if (distancia_xy(p1, c1) <= c1.raio){

        printf("O ponto p1 está contido dentro da circunferência c1 \n");

    }else {
        printf("O ponto p1 não está contido dentro da circuferência c1 \n");
    }

    return 0;

}

float distancia_xy (PONTO p1, CIRCUNFERENCIA c1){

    return sqrt(pow(c1.centro.x - p1.x, 2) + pow(c1.centro.y - p1.y,2));
}

