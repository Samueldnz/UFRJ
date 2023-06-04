#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/* Function prototypes */
int Partition(int *V, int intBegin, int intEnd);
int QuickSelect(int *V, int intBegin, int intEnd, int int_K);
int* DynamicVectorBuilder(char* pfileName, int* pSizeOfArray);

int main(int argc, char *argv[])
{
    /* Verify that the correct number of arguments are provided */
    if (argc < 3) {
        printf("Usage: %s K filename.txt\n", argv[0]);
        return 1;
    }

    int tam, Result;
    int K = atoi(argv[1]); 

    int* V = DynamicVectorBuilder(argv[2], &tam);
    Result = QuickSelect(V, 0, tam - 1, K);

    printf("%d", Result);
    printf("\n\n");

    free(V);

    return 0;
}

/**
 * @brief QuickSelect algorithm to find the Kth smallest element in an array.
 * 
 * @param V pointer to an array of integers
 * @param intBegin starting index of the array
 * @param intEnd ending index of the array
 * @param int_K position of the element to find
 * @return int the Kth smallest element
 */
int QuickSelect(int *V, int intBegin, int intEnd, int int_K)
{
    int pivot_position;

    /*if array has only one element, return that element*/
    if(intBegin == intEnd)
    {
        return V[intBegin];
    }
  
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

/**
 * @brief find the correct position of the pivot element in the array.
 * 
 * @param V pointer to an array of integers
 * @param start starting index of the array
 * @param end ending index of the array
 * @return int the new position of pivot
 */
int Partition(int *V, int start, int end)
{
    int pivot_position, pivot_value, i, j, temp;

    srand(time(NULL)); 
    pivot_position = start + rand() % (end - start + 1); /* random position between start and end */
    
    /* Move pivot to the end */
    pivot_value = V[pivot_position];
    V[pivot_position] = V[end];
    V[end] = pivot_value;

    /* Initializing two pointers to divide subarray into two parts */
    i = start;
    j = end - 1;

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

    return i; 
}

/**
 * @brief Builds a dynamic integer vector from a file.
 * 
 * @param pfileName a pointer to the name of the file to be read.
 * @param pSizeOfArray a pointer to the variable that will hold the size of the array.
 * @return int* A pointer to the dynamic integer vector created from the file.
 */
int* DynamicVectorBuilder(char* pfileName, int* pSizeOfArray)
{
    FILE* file = fopen(pfileName, "r");
    if(file == NULL) {
        exit(1); /*Error: file could not be opened.*/
    }

    int intFileNumber, numberOfElements = 0, i;

    while(fscanf(file, "%d", &intFileNumber) == 1) {
        numberOfElements++;
    }

    int *V = (int*) malloc(numberOfElements * sizeof(int));
    if(V == NULL) {
        exit(1); /*Error: memory could not be allocated.*/
    }

    rewind(file); /*Reposition the file position indicator to the beginning of the file.*/
    for(i = 0; i < numberOfElements; i++) {
        fscanf(file, "%d", &V[i]);
    }

    fclose(file);
    *pSizeOfArray = numberOfElements;

    return V; 
}



