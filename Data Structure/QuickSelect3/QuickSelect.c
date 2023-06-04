#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int Partition(int *V, int intBegin, int intEnd);
int QuickSelect(int *V, int intBegin, int intEnd, int int_K);
void arrayoverflow(int** V, int* size);
void insert(int** V, int* size, int elements, int x);

int main(int argc, char *argv[])
{
    int element = 0, Result;
    int size = 10;
    int K = atoi(argv[2]); 

    int *V = malloc(10 * sizeof(int));
    if(V == NULL) exit(1); 

    while(!feof(stdin)){
        int x;
        if(scanf("%d", &x) == 1){
            insert(&V, &size, element, x);
            element++;
        }
    }

    Result = QuickSelect(V, 0, element - 1, K);
    
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
    {return V[intBegin];}

    pivot_position = Partition(V, intBegin, intEnd); 

    /*if pivot is at position K, we found the Kth smallest element*/
    if(pivot_position == int_K) 
    {return V[int_K];}
    
    /*if pivot is to the right of position K, search in the left subarray*/
    if(int_K > pivot_position) 
    {return QuickSelect(V, pivot_position + 1, intEnd, int_K);}

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
    pivot_position = start + rand() % (end - start + 1); 
    
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
        if(V[i] < pivot_value){i++;}
        if(V[j] >= pivot_value){j--;}
    }

    /* Putting pivot in its correct position */
    temp = V[i];
    V[i] = V[end];
    V[end] = temp;

    return i; 
}

/**
 * @brief doubles the size of the array pointed to by V, reallocating memory as necessary
 * 
 * @param V a pointer to a pointer to an array of integers
 * @param size a pointer to an integer representing the current size of the array pointed to by V
 */
void arrayoverflow(int** V, int* size) {
    (*size) *= 2;
    (*V) = (int *) realloc((*V), (*size) * sizeof(int));
    if ((*V) == NULL) {
        exit(1); 
    }
}

/**
 * @brief This function inserts an element into the dynamic array V, and if the number
of elements is equal to the size of the array, the function calls the arrayoverflow
function to resize the array.

 * 
 * @param V a pointer to the dynamic array.
 * @param size a pointer to the variable that stores the size of the array.
 * @param elements  the number of elements currently stored in the array.
 * @param x the element to be inserted.
 */
void insert(int** V, int* size, int elements, int x){

    if(elements == (*size)){arrayoverflow(V, size);}
    
    if(elements == (*size)){exit(1);}

    (*V)[elements] = x; 
} 
