#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define MAX_LENGTH 20
#define ZERO 0

typedef struct VERTEXNODE {
    int value;
    struct VERTEXNODE* next;
} vertexnode;

void add_to_list(int value, vertexnode** head);


int main() {

    char inputOfvertex[MAX_LENGTH];   /* Input string for the number of vertices */
    int numberOfvertex;               
    char vertexAsString[MAX_LENGTH];  /* Input string for each vertex */
    char ch;                          
    int j, i, destination;            /* Loop variables and destination vertex */
    int *degreeOfvertexes;            /* Array to store the degree of each vertex */
    vertexnode *vertex_list;          /* Pointer to the adjacency list of each vertex */
    vertexnode **vertextargets;       /* Array to store the adjacency list of each vertex */

   
    fgets(inputOfvertex, MAX_LENGTH, stdin);
    numberOfvertex = atoi(inputOfvertex);

    vertextargets = (vertexnode**) malloc((numberOfvertex+1) * sizeof(vertexnode*));
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

    printf("You are here! Congrats, It`s working!\n");

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
    
    vertexnode* new_node = (vertexnode*) malloc(sizeof(vertexnode));
    
    new_node->value = value;
    new_node->next = (*head);
    (*head) = new_node;
}


