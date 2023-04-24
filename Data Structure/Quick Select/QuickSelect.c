#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int Partition(int *V, int intBegin, int intEnd);
int QuickSelect(int *V, int intBegin, int intEnd, int int_K);
int* DynamicVectorBuilder(char* pfileName, int* pTam);

int main(int argc, char *argv[])
{
    /*IT'S ALIVE! MY CODE IS ALIVE! Now, it's working correctly. In this version, the first one,
    you need to enter with file (.txt) containing all the numbers.
    
    You can test by yourself if you want. 
    Just need to use the following command: ./QuickSelect.exe K(a number of your desire) Test.txt*/

    /*The followings ones are variables*/
    
    int tam, Result; /*i; in case you wanna print the vector*/

    int K = atoi(argv[1]); /*converts a string to int number, i.e., the argument K in the command*/

    /*It builds the dynamic vector using the numbers from the file*/
    int* V = DynamicVectorBuilder(argv[2], &tam); 

    Result = QuickSelect(V, 0, tam - 1, K);
    
    /*Its prints out the result*/
    printf("%d", Result);
    printf("\n\n");

    /*
    for(i = 0; i < tam; i++)
    {
        printf("%4d ", V[i]);  Its prints out all the vector, totaly desnecessary, but you can use
    }*/

    /*Realease the vector*/
    free(V);

    return 0;
}

/* *V is a pointer to an array of numbers, start is the begin of this array, 
    end is self-explanatory and follows the same logic as the start variable, and
    K is the position of the array that you want*/
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

int Partition(int *V, int start, int end)
{
    int pivot_position, pivot_value, i, j, temp;

    /*It gets a random number between the vector`s begin and its end to be the pivot number`s
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

int* DynamicVectorBuilder(char* pfileName, int* pTam)
{
    /*Open the file and verify if they were truly open without any problems*/
    FILE* file = fopen(pfileName, "r");
    if(file == NULL) exit(1);


    int intFileNumber, int_n = 0, i;

    /*It reads all the number inside the file ir order to know how many are in there consequently
    the vector size*/
    while(fscanf(file, "%d", &intFileNumber) == 1)
    {
        int_n++;
    }


    int *V = (int*) malloc(int_n * sizeof(int));
    if(V == NULL) exit(1);

    rewind(file); /*Is used to read the file twice: first, to count how many numbers are in 
    the file, and second, to store the numbers in the dynamic vector. As the first read loops 
    through the file from start to finish, the rewind() function is used to reposition the 
    file position indicator back to the beginning before the second read.*/

    for(i = 0; i < int_n; i++){
        fscanf(file, "%d", &V[i]);
    }

    fclose(file);
    *pTam = int_n;

    return V;
}

