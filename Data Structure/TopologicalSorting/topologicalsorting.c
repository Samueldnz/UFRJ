/*
## gcc topologicalsorting.c -o topologicalsorting.exe -Wall -ansi
## ./topologicalsorting.exe < input.txt > output.txt
*/

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define MAX_LENGTH 20

typedef struct VERTEXNODE {
    int value;
    struct VERTEXNODE* next;
} vertexnode;

void add_to_list(int value, vertexnode** head);
void topologicalsorting(vertexnode** graph, int numberOfvertex, int* degreeOfvertexes);


int main() {

    char inputOfvertex[MAX_LENGTH];   /* Input string for the number of vertices */
    int numberOfvertex;               
    char vertexAsString[MAX_LENGTH];  /* Input string for each vertex */
    char ch;                          
    int j, i, destination;            /* Loop variables and destination vertex */
    int *degreeOfvertexes;            /* Array to store the degree of each vertex */
    vertexnode *vertex_list;          /* Pointer to the adjacency list of each vertex */
   
    fgets(inputOfvertex, MAX_LENGTH, stdin);
    numberOfvertex = atoi(inputOfvertex);

    vertexnode** vertextargets = (vertexnode**) malloc((numberOfvertex+1) * sizeof(vertexnode*));
    if(vertextargets == NULL) exit(1); 

    for(i = 1; i <= numberOfvertex; i++){vertextargets[i] = NULL;}

    degreeOfvertexes = (int*) malloc((numberOfvertex+1) * sizeof(int));
    if(degreeOfvertexes == NULL) exit(1);
    
    for(i = 1; i <= numberOfvertex; i++){degreeOfvertexes[i] = 0;}

    for(i = 1; i <= numberOfvertex; i++){
        vertex_list = NULL; 
        j = 0;

        while(TRUE){
            
            while('0' <= (ch = getchar()) && ch <= '9'){ 
                vertexAsString[j] = ch;
                j++;
            }

            if(j > 0) {
           
                vertexAsString[j] = '\0';
                destination = atoi(vertexAsString);
                add_to_list(destination, &vertex_list); 
                degreeOfvertexes[destination]++; 
                j = 0; 
            }
            if(ch == EOF || ch == '\n'){
                break;
            }
        }
        vertextargets[i] = vertex_list;
    }

    topologicalsorting(vertextargets, numberOfvertex, degreeOfvertexes);

    for(i = 1; i <= numberOfvertex; i++){
        vertexnode* x = vertextargets[i];

        while(x != NULL){
            vertexnode* temporary = x;
            x = x->next;
            free(temporary);
        }
    }

    free(vertextargets);
    free(degreeOfvertexes);

    return 0;
}

/**
 * @brief Adds a new vertex to the adjacency list.
 * 
 * @param value The value to be added to the new vertex.
 * @param head The head of the vertex linked list.
 */
void add_to_list(int value, vertexnode** head) {
    
    vertexnode* new_node = (vertexnode*) malloc(sizeof(vertexnode));
    
    new_node->value = value;
    new_node->next = (*head);
    (*head) = new_node;
}

/**
 * @brief Implements the Kahn Algorithm to perfom a topological sorting on a graph represented by
 *  an adjacent Liked list
 * 
 * @param graph Pointer to an array of pointers to each adjancent liked list
 * @param numberOfvertex number of vertices in the graph
 * @param degreeOfvertexes an int array representing the in-degree of each vertex
 */
void topologicalsorting(vertexnode** graph, int numberOfvertex, int* degreeOfvertexes)
{
    int* line = (int*) malloc((numberOfvertex+1) * sizeof(int));
    if(line == NULL) exit(1);

    int* topologicalsort = (int*) malloc((numberOfvertex+1)*sizeof(int));
    if(topologicalsort == NULL) exit(1);

    int i, begin = 1, end = 1;

    for(i = 1; i <= numberOfvertex; i++){
        if(degreeOfvertexes[i] == 0){
            line[end] = i;
            end++;
        }
    }

    i = 1;
    while(begin != end){
        int index = line[begin];
        begin++;

        if (i <= numberOfvertex) {
            topologicalsort[i] = index;
            i++;
        }

        vertexnode* adjacent = graph[index];

        while(adjacent != NULL){
            int valueOfAdj = adjacent->value;
            degreeOfvertexes[valueOfAdj]--;
            if(degreeOfvertexes[valueOfAdj] == 0){
                line[end] = valueOfAdj;
                end++;
            }
            adjacent = adjacent->next;
        }
    }
    if(i != (numberOfvertex+1)){
        printf("The graph has a cycle!\n");
        return;
    }
    
    for(i = 1; i <= numberOfvertex; i++){
        printf("%4d", topologicalsort[i]);
    }
}

