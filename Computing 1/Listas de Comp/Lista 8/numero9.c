#include<stdio.h>
#include<math.h>

typedef struct _PONTO{

    float x, y;
}PONTO;

typedef struct _CIRCUNFERENCIA{
    float raio;
    PONTO centro;
}CIRCUNFERENCIA;

void relacao_circ(CIRCUNFERENCIA c1, CIRCUNFERENCIA c2);


int main(void){

    CIRCUNFERENCIA c1, c2;

    printf("Entre com o raio do círculo c1. \n");
    scanf("%f", &c1.raio);

    printf("Entre com as coordenadas do centro do círculo c1. \n");
    scanf("%f %f", &c1.centro.x, &c1.centro.y);

    printf("Dados lidos: \n");
    printf("Círculo c1: raio = %f, x = %f, y = %f\n", c1.raio, c1.centro.x, c1.centro.y);

    printf("Entre com o raio do círculo c2. \n");
    scanf("%f", &c2.raio);

    printf("Entre com as coordenadas do centro do círculo c2. \n");
    scanf("%f %f", &c2.centro.x, &c2.centro.y);

    printf("Dados lidos: \n");
    printf("Círculo c2: raio = %f, x = %f, y = %f\n", c2.raio, c2.centro.x, c2.centro.y);

    relacao_circ(c1, c2);
   

    return 0;

}

void relacao_circ(CIRCUNFERENCIA c1, CIRCUNFERENCIA c2){

    int distancia_x, distancia_y, distancia_centro;

    distancia_x = c2.centro.x - c1.centro.x;
    distancia_y = c2.centro.y - c1.centro.y;

    distancia_centro = sqrt(pow(distancia_x,2) + pow(distancia_y,2));

    
    
    if (distancia_centro == (c1.raio + c2.raio)){
        printf("As circunferências são tangentes externamente. \n");

    }else if(distancia_centro > (c1.raio + c2.raio)){
        printf("Uma circunferência é externa a outra \n");

    }else if(distancia_centro < (c1.raio + c2.raio)){
        printf("As circunferências são secantes \n");

    }else if(distancia_centro < (c1.raio - c2.raio)){
        printf("Uma circunferência é interna a outra \n");
    }
    
}


