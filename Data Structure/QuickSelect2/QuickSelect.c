#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int Partition(int *V, int intBegin, int intEnd);
int QuickSelect(int *V, int intBegin, int intEnd, int int_K);

int main(int argc, char *argv[])
{
    /* This is the second version of the QuickSelect program. It allows users to input a 
    list of numbers via keyboard, as the program uses a static array to store the input data.

    To use this program, you can run it in the command line and specify the value of K as 
    an argument. 
    
    For example, to find the K-th smallest element in a list, you can use 
    the command "./QuickSelect.exe -K < input.txt" where "K" is replaced by the desired 
    value of K, and "input.txt" is a file containing the list of numbers.

    Remember that the K-th element is counted starting from the number 1.*/

    /*initialize variables*/
    int tam = 0, Result; 

    /*converts a string to int number, i.e., the argument K in the command*/
    int K = atoi(argv[2]); 

    /*It builds the vector*/
    int V[1000];

    /*get input from user and add to array*/
    while(!feof(stdin)){
        int x;
        if(scanf("%d", &x) == 1){
            V[tam] = x;
            tam++;
        }
    }

    /*find Kth smallest element using QuickSelect algorithm*/
    Result = QuickSelect(V, 0, tam - 1, K);
    
    /*Its prints out the result*/
    printf("%d", Result);
    printf("\n\n");

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
int QuickSelect(int *V, int start, int end, int K)
{
    int pivot_position;

    /*It checks if the vector have just one number. If it has, it`ll return 
    the number in that position*/
    if(start == end)
    {
        return V[start];
    }
  
    pivot_position = Partition(V, start, end); /*returns the correct pivot`s position in the array*/

    if(pivot_position == K) 
    {
        return V[K];
    }
    
    if(K > pivot_position) /*vector RIGHT side*/
    {
        return QuickSelect(V, pivot_position + 1, end, K);
    }

    /*vector LEFT side */
    return QuickSelect(V, start, pivot_position - 1, K);

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

    /*It gets a random number between the vector`s begin and its end to be the pivot numbers
    position */
    srand(time(NULL));
    pivot_position = start + rand() % (end - start + 1);

    /*It puts the pivot number in the last position*/
    pivot_value = V[pivot_position];
    V[pivot_position] = V[end];
    V[end] = pivot_value;

    /*Imagine like a pointer to the first postion and penultimate position respectively*/
    i = start;
    j = end - 1;

    while(j >= i)
    {
        /*If the first position value is bigger than the pivot one and the last value is 
        smaller than the pivot one, we need to change the places between them */
        if((V[i]>= pivot_value) && (V[j] < pivot_value)){
            temp = V[j];
            V[j] = V[i];
            V[i] = temp;
        }

        if(V[i] < pivot_value){
            i++;
        }

        if(V[j] >= pivot_value){
            j--;
        }
    }

    /*in here, we put the pivot value in the correct position if the array was sorted*/
    temp = V[i];
    V[i] = V[end];
    V[end] = temp;

    return i; /*return the new position of the pivot*/
}

