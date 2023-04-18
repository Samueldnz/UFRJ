#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int Partition(int *V, int intBegin, int intEnd);
int QuickSelect(int *V, int intBegin, int intEnd, int int_K);
int* DynamicVectorBuilder(char* pfileName, int* pTam);

int main(int argc, char *argv[])
{
    /*OK. Everything is working according to the plan. Enjoy! In order to call the program, 
    just use the following command: ./QuickSelect.exe K(a number of your desire) teste.txt*/

    /*The followings ones are variable, if they have the underscore, means they`re a 
    temporary variable*/
    int int_tam, intResult, i;  
    int int_K = atoi(argv[1]);

    /*It builds the dynamic vector from a file*/
    int* V = DynamicVectorBuilder(argv[2], &int_tam); 


    intResult = QuickSelect(V, 0, int_tam + 1, int_K);
    
    /*Its prints out the result*/
    printf("%d", intResult);
    printf("\n\n");

    /*Its prints out all the vector, totally desnecessary, so I`ll comment this part
    pretty soon*/
    for(i = 0; i < int_tam; i++)
    {
        printf("%4d ", V[i]);   
    }

    /*Realease the vector*/
    free(V);

    return 0;
}

int QuickSelect(int *V, int intBegin, int intEnd, int int_K)
{
    int intPospivot;

    if((intEnd - intBegin) <= 1)
    {
        return V[intBegin];
    }

    intPospivot = Partition(V, intBegin, intEnd);

    if(intPospivot == int_K)
    {
        return V[int_K];
    }
    if(int_K < intPospivot)
    {
        QuickSelect(V, intBegin, intPospivot, int_K);
    }
    else
    {
        QuickSelect(V, intPospivot + 1, intEnd, int_K);
    }
}

int Partition(int *V, int intBegin, int intEnd)
{
    int intPos, intPivot, int_i, int_j, int_temp;

    srand(time(NULL));
    intPos = intBegin + (rand() % (intEnd- 1));

    intPivot = V[intPos];
    V[intPos] = V[intBegin];
    V[intBegin] =  intPivot;

    int_i = intBegin + 1;
    int_j = intEnd - 1;

    while(int_i < int_j)
    {
        while(int_i < intEnd && V[int_i] < intPivot)
        {
            int_i++;
        }

        while(int_j > intBegin && V[int_j] >= intPivot)
        {
            int_j--;
        }

        if(int_i < int_j)
        {
            int_temp = V[int_i];
            V[int_i] = V[int_j];
            V[int_j] = int_temp;
        }
    }

    V[intBegin] = V[int_j];
    V[int_j] = intPivot;

    return int_j;
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
