#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/* Function prototypes */
int Partition(int *V, int intBegin, int intEnd);
int QuickSelect(int *V, int intBegin, int intEnd, int int_K);
int* DynamicVectorBuilder(char* pfileName, int* pSizeOfArray);

int main(int argc, char *argv[])
{
    /* This version of the QuickSelect program reads a file containing a list of numbers.
    To run the program, enter the desired position K followed by the name of the file to be read.
    For example, to find the 5th smallest number in the file "test.txt", run the command
    "./QuickSelect.exe 5 test.txt".
    
    Remember that the K-th element is counted starting from the number 1. */

    /* Verify that the correct number of arguments are provided */
    if (argc < 3) {
        printf("Usage: %s K filename.txt\n", argv[0]);
        return 1;
    }

    /* Declare variables */
    int tam, Result;
    int K = atoi(argv[1]); /* Convert the second argument to an integer */

    /* Build the dynamic vector using numbers from the specified file */
    int* V = DynamicVectorBuilder(argv[2], &tam);

    /* Find the Kth smallest element in the vector */
    Result = QuickSelect(V, 0, tam - 1, K);

    /* Print the result */
    printf("%d", Result);
    printf("\n\n");

    /* Free the dynamically allocated memory */
    free(V);

    return 0;
}

/*
QuickSelect algorithm to find the Kth smallest element in an array.

Arguments:
- V: pointer to an array of integers
- intBegin: starting index of the array
- intEnd: ending index of the array
- int_K: position of the element to find

Return: the Kth smallest element
*/
int QuickSelect(int *V, int intBegin, int intEnd, int int_K)
{
    int pivot_position;

    /*if array has only one element, return that element*/
    if(intBegin == intEnd)
    {
        return V[intBegin];
    }
  
    /*get pivot position using Partition function*/
    pivot_position = Partition(V, intBegin, intEnd); 

    /*if pivot is at position K, we found the Kth smallest element*/
    if(pivot_position == int_K) 
    {
        return V[int_K];
    }
    
    /*if pivot is to the right of position K, search in the left subarray*/
    if(int_K > pivot_position) 
    {
        return QuickSelect(V, pivot_position + 1, intEnd, int_K);
    }

    /*if pivot is to the left of position K, search in the right subarray*/
    return QuickSelect(V, intBegin, pivot_position - 1, int_K);
}

/*
Partition - find the correct position of the pivot element in the array.

Arguments:
- V: pointer to an array of integers
- intBegin: starting index of the array
- intEnd: ending index of the array

Return: an int, the new position of pivot
*/
int Partition(int *V, int start, int end)
{
    int pivot_position, pivot_value, i, j, temp;

    /* Selecting a pivot element */
    srand(time(NULL)); /* seed random number generator */
    pivot_position = start + rand() % (end - start + 1); /* random position between start and end */
    
    /* Move pivot to the end */
    pivot_value = V[pivot_position];
    V[pivot_position] = V[end];
    V[end] = pivot_value;

    /* Initializing two pointers to divide subarray into two parts */
    i = start;
    j = end - 1;

    /* Rearranging elements around the pivot */
    while(j >= i)
    {
        /* Swap elements if they are on the wrong side of pivot */
        if((V[i] >= pivot_value) && (V[j] < pivot_value)){
            temp = V[j];
            V[j] = V[i];
            V[i] = temp;
        }

        /* Move i and j until they point to an element on the wrong side */
        if(V[i] < pivot_value){
            i++;
        }

        if(V[j] >= pivot_value){
            j--;
        }
    }

    /* Putting pivot in its correct position */
    temp = V[i];
    V[i] = V[end];
    V[end] = temp;

    /* Returning the new position of the pivot */
    return i; 
}


/*
 * Builds a dynamic integer vector from a file.
 
 Parameters:
 - pfileName: a pointer to the name of the file to be read.
 - pSizeOfArray: a pointer to the variable that will hold the size of the array.
 
 Returns:
 - A pointer to the dynamic integer vector created from the file.
 
 Notes:
 - The file must contain only int separated by "\n".
 - The file must not contain any non-numeric characters.
 - The memory allocated for the dynamic int vector must be freed by the caller.

 */
int* DynamicVectorBuilder(char* pfileName, int* pSizeOfArray)
{
    /*Open the file and verify that it was opened without any problems.*/
    FILE* file = fopen(pfileName, "r");
    if(file == NULL) {
        exit(1); /*Error: file could not be opened.*/
    }

    int intFileNumber, numberOfElements = 0, i;

    /*Count the number of integers in the file to determine the size of the dynamic vector.*/
    while(fscanf(file, "%d", &intFileNumber) == 1) {
        numberOfElements++;
    }

    /*Allocate memory for the dynamic vector.*/
    int *V = (int*) malloc(numberOfElements * sizeof(int));
    if(V == NULL) {
        exit(1); /*Error: memory could not be allocated.*/
    }

    /*Read the integers from the file into the dynamic vector.*/
    rewind(file); /*Reposition the file position indicator to the beginning of the file.*/
    for(i = 0; i < numberOfElements; i++) {
        fscanf(file, "%d", &V[i]);
    }

    fclose(file); /*Close the file.*/
    *pSizeOfArray = numberOfElements;

    return V; /*Return a pointer to the dynamic vector.*/
}



