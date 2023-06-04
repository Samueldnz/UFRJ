/**
Usage: Change the value of SIZE in the define statement to set the number
of vertices in the output graph.
By default, the output is saved in a file named "input.txt", but if you
want to choose a different name, call the program with -f [filename]

This generator code isn`t mine, but I translated into english.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define SIZE 50

int main (int argc, char *argv[])
{
    int topologicalsorting[SIZE + 1];
    int position[SIZE + 1];
    int lineOfAdjacents[SIZE];
    int i, j, k;
    int pos;
    int numNeighbor;
    int standard = 1;
    FILE *out;

    for (i = 1; i < argc - 1; i++) {
		if (!strcmp("-f", argv[i])) {
			out = fopen(argv[i + 1], "w");
            standard = 0;
		}
    }
    if (standard)
        out = fopen("input.txt", "w");

    srand(time(NULL));
    for (i = 1; i <= SIZE; i++)
        topologicalsorting[i] = 0;

    i = 1;
    /* Generates a random topological sort, with all numbers from 1 to SIZE shuffled */
    while (i <= SIZE) {
        pos = rand() % SIZE + 1;
        if (topologicalsorting[pos] == 0) {
            topologicalsorting[pos] = i;
            position[i++] = pos; 
            /* We'll need the position of i in this ordering later */
        }
    }

    fprintf(out, "%d\n", SIZE); /* The input starts with the number of vertices */

    /* Assigns the neighbors of each vertex in order, as in the input */
    for (i = 1; i <= SIZE; i++) {
        numNeighbor = SIZE - position[i]; /* i can only have neighbors ahead of it in the 
        ordering, to ensure it's a topological sort */

        if (numNeighbor != 0) 
            numNeighbor = rand() % numNeighbor; 
            /* Otherwise, i would always have all possible neighbors... 
            just to vary the number */

        for (j = 0; j < numNeighbor; j++) {
            lineOfAdjacents[j] = topologicalsorting[position[i] + (rand() % numNeighbor) + 1];
            for (k = 0; k < j; k++) {
                if (lineOfAdjacents[k] == lineOfAdjacents[j]) { 
                    /* Cancels repeated neighbors */
                    j--;
                    break;
                }
            }
        }

        for (j = 0; j < numNeighbor; j++) /* All neighbors of i */ {
            fprintf(out, "%d ", lineOfAdjacents[j]);
        }
        fprintf(out, "\n"); /* It's a line, as the variable name suggests :O */
    }
    fclose(out);

    return 0; 
}