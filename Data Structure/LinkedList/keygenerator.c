#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_VALUE 0
#define MAX_VALUE 150
#define NUM_NUMBERS 150

/*To run the code use the following command "./keygenerator.exe > "in.txt""*/
int main() {
    int i;
    int random_number;

    /*Seed the random number generator*/
    srand(time(NULL));


    for (i = 0; i < NUM_NUMBERS; i++) {
        /*Generate a random number between MIN_VALUE and MAX_VALUE*/
        random_number = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
        printf("%d ", random_number);
    }

    printf("\n");

    return 0;
}