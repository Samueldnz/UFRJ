#include<stdio.h>
#include<math.h>

typedef struct _PONTO{

    float x, y;
}PONTO;

int main(void){

    PONTO p1, p2;

    float distancia_x, distancia_y, distancia_xy;

    printf("Insira as coordenadas x e y do ponto p1. \n");
    scanf("%f %f", &p1.x, &p1.y);

    printf("Insira as coordenadas x e y do ponto p2. \n");
    scanf("%f %f", &p2.x, &p2.y);

    distancia_x = p2.x - p1.x;
    distancia_y = p2.y - p1.y;

    distancia_xy = sqrt(pow(distancia_x,2) + pow(distancia_y,2));
    
    printf("A distância entre os pontos p1 e p2 é: %f\n", distancia_xy);

    return 0;
}