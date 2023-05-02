#include <stdio.h>
#include <stdlib.h>

/* Constants */
#define TRUE 1
#define MAX_LENGTH 20
#define ZERO 0

/* Structures */
typedef struct VERTEXNODE {
    int value;
    struct VERTEXNODE* next;
} vertexnode;

/* Function prototypes */
void add_to_list(int value, vertexnode** head);

/* Main function */
int main() {
     /* Variable declarations */
    char inputOfvertex[MAX_LENGTH];   /* Input string for the number of vertices */
    int numberOfvertex;               /* Number of vertices */
    char vertexAsString[MAX_LENGTH];  /* Input string for each vertex */
    char ch;                          /* Temporary character */
    int j, i, destination;            /* Loop variables and destination vertex */
    int *degreeOfvertexes;            /* Array to store the degree of each vertex */
    vertexnode *vertex_list;          /* Pointer to the adjacency list of each vertex */
    vertexnode **vertextargets;       /* Array to store the adjacency list of each vertex */

    /* Read number of vertices from input */
    fgets(inputOfvertex, MAX_LENGTH, stdin);
    numberOfvertex = atoi(inputOfvertex);

    /* Allocate memory for an array of pointers to adjacency lists and initialize to NULL */
    vertextargets = (vertexnode**) malloc((numberOfvertex+1) * sizeof(vertexnode*));
    if(vertextargets == NULL) {
        exit(EXIT_FAILURE); /* exit if memory allocation fails */
    }
    for(i = 1; i <= numberOfvertex; i++){
        vertextargets[i] = NULL;
    }

    /* Allocate memory for an array to store the degree of each vertex and initialize to zero */
    degreeOfvertexes = (int*) malloc((numberOfvertex+1) * sizeof(int));
    if(degreeOfvertexes == NULL) {
        exit(EXIT_FAILURE); /* exit if memory allocation fails */
    }
    for(i = 1; i <= numberOfvertex; i++){
        degreeOfvertexes[i] = 0;
    }

    /* Read vertices and their edges from input */
    for(i = 1; i <= numberOfvertex; i++){
        vertex_list = NULL; /* initialize the adjacency list for the current vertex */
        j = 0;

        while(TRUE){
            /* Read the vertices until reaching a non-digit character */
            while('0' <= (ch = getchar()) && ch <= '9'){ 
                vertexAsString[j] = ch;
                j++;
            }

            if(j > 0) {
                /* Convert the vertex to an integer and add to the adjacency list */
                vertexAsString[j] = '\0';
                destination = atoi(vertexAsString);
                add_to_list(destination, &vertex_list); /* add the vertex to the adjacency list */
                degreeOfvertexes[i]++; /* increment the degree of the current vertex */
                j = 0; /* reset the string index */
            }

            /* Break the loop when reaching the end of the line or end of file */
            if(ch == EOF || ch == '\n'){
                break;
            }
        }
        /* Store the adjacency list for the current vertex */
        vertextargets[i] = vertex_list;
    }

    int *topologicalsort = malloc(numberOfvertex * sizeof(int));
    if(topologicalsort == NULL) exit(TRUE);

    int *visitedvertex = malloc(numberOfvertex * sizeof(int));
    if(visitedvertex == NULL) exit(TRUE);

    for(i = 1; i <= numberOfvertex; i++){
        visitedvertex[i] = 0;
    }

    /* Free allocated memory */
    free(vertextargets);
    free(degreeOfvertexes);

    return 0;
}

/**
Adds a new vertex to the adjacency list.
@param value - The value to be added to the new vertex.
@param head - The head of the vertex linked list.
@return void
*/
void add_to_list(int value, vertexnode** head) {
    /*Allocates memory for the new node*/
    vertexnode* new_node = (vertexnode*) malloc(sizeof(vertexnode));
    /*Sets the value of the new node to the input value*/
    new_node->value = value;
    /*Sets the next pointer of the new node to the current head*/
    new_node->next = (*head);
    /*Updates the head pointer to point to the new node*/
    (*head) = new_node;
}

void topologicalsorting(int startvertex, 
                        vertexnode** vertex_list, 
                        int** degreeOfvertexes, 
                        int** visitedvertex,
                        int** topologicalsort)
{

    vertexnode* adjacentvertex;

    visitedvertex[startvertex] = 1;

    int index = ZERO;
    topologicalsort[index] = startvertex;

    adjacentvertex = vertex_list[index];

    while(adjacentvertex != NULL){
        int x = adjacentvertex->value;
        (*degreeOfvertexes)[x]--;
        
        if((*degreeOfvertexes)[x] == 0 && visitedvertex[x] == 0){
            topologicalsorting(x, vertex_list,degreeOfvertexes,); /*it`s still missing something*/
        }
        adjacentvertex = adjacentvertex->next;
    }
}