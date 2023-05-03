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
void topologicalsorting(int startvertex, 
                        vertexnode** vertextargets, 
                        int** degreeOfvertexes, 
                        int** visitedvertex,
                        int** topologicalsort,
                        int* index);

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
        exit(TRUE); /* exit if memory allocation fails */
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

   /*Allocate memory for the topological sort and visited vertex arrays*/
    int *topologicalsort = (int*) malloc((numberOfvertex+1) * sizeof(int));
    if(topologicalsort == NULL) exit(TRUE);

    int *visitedvertex = (int*) malloc((numberOfvertex+1) * sizeof(int));
    if(visitedvertex == NULL) exit(TRUE);

    /*Initialize all vertices as unvisited*/
    for(i = 1; i <= numberOfvertex; i++){
        visitedvertex[i] = 0;
    }

    /*Find the vertex with in-degree 0 to start the topological sort*/
    i = 1;
    while(degreeOfvertexes[i] != 0){
        i++;
    }

    /*Perform the topological sort, starting from the vertex with in-degree 0*/
    topologicalsorting(i, &vertextargets, &degreeOfvertexes, &visitedvertex, &topologicalsort, 1);

    /*Print the topological sort*/
    for(i = 1; i <= numberOfvertex; i++){
        printf("%4d", topologicalsort[i]);
    } 


    /* Free allocated memory */
    free(vertextargets);
    free(degreeOfvertexes);
    free(topologicalsort);
    free(visitedvertex);

    return 0;
}

/**
    Adds a new vertex to the adjacency list.

    Parameters:
    - value: The value to be added to the new vertex.
    - head:The head of the vertex linked list.

    Returns: nothing
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

/**
    This function performs topological sorting on a graph represented as an adjacency list.

    Parameters:
    - startvertex: the index of the vertex to start the sorting from
    - vertex_list: a pointer to an array of vertexnodes representing the adjacency list of the graph
    - degreeOfvertexes: a pointer to an array of integers representing the in-degree of each vertex in the graph
    - visitedvertex: a pointer to an array of integers representing whether each vertex has been visited or not
    - topologicalsort: a pointer to an array of integers that will contain the sorted vertices
    - index: pointer to the index of the next empty slot in the topologicalsort array

    Returns: nothing
*/
void topologicalsorting(int startvertex, 
                        vertexnode** vertextargets, 
                        int** degreeOfvertexes, 
                        int** visitedvertex,
                        int** topologicalsort,
                        int* index)
{

    vertexnode* adjacentvertex;

    /*Mark the current vertex as visited*/
    (*visitedvertex)[startvertex] = 1;

    /*Add the current vertex to the topological sort*/
    (*topologicalsort)[(*index)++] = startvertex;

    /*Get the first adjacent vertex of the current vertex*/
    adjacentvertex = vertextargets[startvertex];

    /*Iterate over all adjacent vertices of the current vertex*/
    while(adjacentvertex != NULL){

        /*Decrease the in-degree of the adjacent vertex by 1*/
        int x = adjacentvertex->value;
        (*degreeOfvertexes)[x]--;

        /*If the in-degree of the adjacent vertex is 0 and it hasn't been visited, 
        call the topologicalsorting function recursively on it*/

        if((*degreeOfvertexes)[x] == 0 && (*visitedvertex)[x] == 0){
            topologicalsorting(x, vertextargets, degreeOfvertexes, visitedvertex, 
                                    topologicalsort, index);
        }

        /*Move to the next adjacent vertex*/
        adjacentvertex = adjacentvertex->next;
    }
}

