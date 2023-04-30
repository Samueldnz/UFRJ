#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/*function prototypes*/
int Partition(int *V, int intBegin, int intEnd);
int QuickSelect(int *V, int intBegin, int intEnd, int int_K);
void arrayoverflow(int** V, int* size);
void insert(int** V, int* size, int elements, int x);

int main(int argc, char *argv[])
{
    /*
    This version is pretty similar to the last one, but instead of using a static array, 
    we use a dynamic one. You can test by yourself if you want. In order to use a file, 
    you just need to enter the following command: 
    ./QuickSelect.exe -K (a number of your desire) < Test.txt

    Remember that the K-th element is counted starting from the number 1.
    */

    /*initialize variables*/
    int element = 0, Result;
    int size = 10;

    /*converts a string to int number, i.e., the argument K in the command*/
    int K = atoi(argv[2]); 

    /*allocate memory for dynamic array*/
    int *V = malloc(10 * sizeof(int));
    if(V == NULL) exit(1); 

    /*get input from user and add to dynamic array*/
    while(!feof(stdin)){
        int x;
        if(scanf("%d", &x) == 1){
            insert(&V, &size, element, x);
            element++;
        }
    }

    /*find Kth smallest element using QuickSelect algorithm*/
    Result = QuickSelect(V, 0, element - 1, K);
    
    /*print out the result*/
    printf("%d", Result);
    printf("\n\n");

    /*free allocated memory*/
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
 * arrayoverflow - doubles the size of the array pointed to by V, reallocating memory as necessary

 Arguments:
  - V: a pointer to a pointer to an array of integers
  - size: a pointer to an integer representing the current size of the array pointed to by V
 
 * Return value: none.
 */
void arrayoverflow(int** V, int* size) {

    /* Double the size of the array */
    (*size) *= 2;

    /* Reallocate memory for the array with the new size */
    (*V) = (int *) realloc((*V), (*size) * sizeof(int));
    
    /* Check if reallocation failed */
    if ((*V) == NULL) {
        exit(1); 
    }
}

/* This function inserts an element into the dynamic array V, and if the number
of elements is equal to the size of the array, the function calls the arrayoverflow
function to resize the array.

Arguments:
- V: a pointer to the dynamic array.
- size: a pointer to the variable that stores the size of the array.
- elements: the number of elements currently stored in the array.
- x: the element to be inserted.

Return value: none.
*/
void insert(int** V, int* size, int elements, int x){
    /*If the number of elements is equal to the size of the array, the array needs to be resized*/
    if(elements == (*size)){
        arrayoverflow(V, size);
    }
    
    /*Double-check the size of the array*/
    if(elements == (*size)){
        exit(1);
    }

    /*Insert the new element into the array*/
    (*V)[elements] = x; 
} 


