#include<stdio.h>
#include<stdlib.h>
#define MAX_VERTEX 10000
#define MAX_EDGE 10000

typedef struct _EDGE{
    int originVertex;
    int destinyVertex;
    int edgeWeight;
}Edge;

void readGraph(int* vertexAmount, int* edgeAmount, Edge* edgeList);

/*void imprimirGrafo(int vertices, int arestas, Edge *listaArestas) {
    printf("Número de vértices: %d\n", vertices);
    printf("Número de arestas: %d\n", arestas);

    int i;
    for (i = 0; i < arestas; i++) {
        printf("Aresta %d: %d -> %d (Peso: %d)\n", i + 1, listaArestas[i].originVertex, listaArestas[i].destinyVertex, listaArestas[i].edgeWeight);
    }
} It`s here just to test the input*/

int main(void){
    int vertexAmount, edgeAmount;
    Edge edgeList[MAX_EDGE];

    readGraph(&vertexAmount, &edgeAmount, edgeList);
    imprimirGrafo(vertexAmount, edgeAmount, edgeList);

    return 0;
}

void readGraph(int* vertexAmount, int* edgeAmount, Edge* edgeList)
{
    scanf("%d %d", vertexAmount, edgeAmount);

    int i;
    for(i = 0; i < (*vertexAmount); i++){
        scanf("%d %d %d", 
                &(edgeList[i].originVertex), 
                &(edgeList[i].destinyVertex), 
                &edgeList[i].edgeWeight);
    }
}