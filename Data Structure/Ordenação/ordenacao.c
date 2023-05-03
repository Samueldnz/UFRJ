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

   
    fgets(inputOfvertex, MAX_LENGTH, stdin);
    numberOfvertex = atoi(inputOfvertex);

    vertextargets = (vertexnode**) malloc((numberOfvertex+1) * sizeof(vertexnode*));
    if(vertextargets == NULL) {
        exit(TRUE); 
    }
    for(i = 1; i <= numberOfvertex; i++){
        vertextargets[i] = NULL;
    }

    degreeOfvertexes = (int*) malloc((numberOfvertex+1) * sizeof(int));
    if(degreeOfvertexes == NULL) {
        exit(EXIT_FAILURE);
    }
    for(i = 1; i <= numberOfvertex; i++){
        degreeOfvertexes[i] = 0;
    }

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

    // TEST BEGINS
    // printf("It's here, now we are gonna print out \n");

    // for(i = 1; i <= numberOfvertex; i++){
    //     printf("i: %d\n", i);
    //     printf("%d\n", vertextargets[i]->value);
    // }

    // for(i = 0; i <= numberOfvertex; i++){
    //     printf("Degree of index %d = %d\n", i, degreeOfvertexes[i]);
    // } 
    //THE END
    
    

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


