#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int Partition(int *V, int intBegin, int intEnd);
int QuickSelect(int *V, int intBegin, int intEnd, int int_K);
int* DynamicVectorBuilder(char* pfileName, int* pTam);

int main(int argc, char *argv[])
{
    /*OK. Everything is working according to the plan. Enjoy! To call the program, just
    use the following command: ./QuickSelect.exe K(a number of your desire) teste.txt*/

   
    int int_tam, intResult, i;
    int int_K = atoi(argv[1]);

    int* V = DynamicVectorBuilder(argv[2], &int_tam);

    intResult = QuickSelect(V, 0, int_tam + 1, int_K);
    
    printf("%d", intResult);
    printf("\n\n");

    for(i = 0; i < int_tam; i++)
    {
        printf("%4d ", V[i]);   
    }

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
    FILE* file = fopen(pfileName, "r");

    if(file == NULL) exit(1);

    int intFileNumber, int_n = 0, i;

    while(fscanf(file, "%d", &intFileNumber) == 1)
    {
        int_n++;
    }

    int *V = (int*) malloc(int_n * sizeof(int));
    if(V == NULL) exit(1);

    rewind(file);

    for(i = 0; i < int_n; i++){
        fscanf(file, "%d", &V[i]);
    }

    fclose(file);
    *pTam = int_n;

    return V;
}
