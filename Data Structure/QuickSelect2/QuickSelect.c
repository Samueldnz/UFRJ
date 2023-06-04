#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int Partition(int *V, int intBegin, int intEnd);
int QuickSelect(int *V, int intBegin, int intEnd, int int_K);

int main(int argc, char *argv[])
{
    int tam = 0, Result; 
    int K = atoi(argv[2]); 
    int V[1000];

    while(!feof(stdin)){
        int x;
        if(scanf("%d", &x) == 1){
            V[tam] = x;
            tam++;
        }
    }

    Result = QuickSelect(V, 0, tam - 1, K);
    
    printf("%d", Result);
    printf("\n\n");

    return 0;
}

/**
 * @brief QuickSelect algorithm to find the Kth smallest element in an array.
 * 
 * @param V pointer to an array of integers
 * @param start starting index of the array
 * @param end ending index of the array
 * @param K position of the element to find
 * @return int the Kth smallest element
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
  
    pivot_position = Partition(V, start, end); 
    if(pivot_position == K) 
    {return V[K];}
    
    if(K > pivot_position) /*vector RIGHT side*/
    {return QuickSelect(V, pivot_position + 1, end, K);}

    /*vector LEFT side */
    return QuickSelect(V, start, pivot_position - 1, K);
}

/**
 * @brief find the correct position of the pivot element in the array.
 * 
 * @param V pointer to an array of integers
 * @param start  starting index of the array
 * @param end ending index of the array
 * @return int the new position of pivot
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

        if(V[i] < pivot_value){i++;}

        if(V[j] >= pivot_value){j--;}
    }

    /*in here, we put the pivot value in the correct position if the array was sorted*/
    temp = V[i];
    V[i] = V[end];
    V[end] = temp;

    return i;
}

