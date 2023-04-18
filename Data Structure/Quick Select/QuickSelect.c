#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int Partition(int *V, int intBegin, int intEnd);
int QuickSelect(int *V, int intBegin, int intEnd, int int_K);

int main(int argc, char *argv[])
{
    /*It works and doesn`t work at the same time, Why? Idk. If I test with small and
    close number, the algorithmic works just in the right side (Why? Idk yet) and if 
    I test with bigger and distant numbers, It doesn`t work at all*/

    int *V;
    int int_tam, intResult, i;
    int int_K = atoi(argv[1]);

    printf("Put the vector length: ");
    scanf("%d", &int_tam);

    V = (int *) malloc(int_tam * sizeof(int));

    if(V == NULL) return 0;

    for(i = 0; i < int_tam; i++)
    {
        scanf("%d", &V[i]);
    }

    intResult = QuickSelect(V, 0, int_tam + 1, int_K);
    
    printf("Result: %d\n", intResult);

    for(i = 0; i < int_tam; i++)
    {
        printf("%4d ", V[i]);   
    }

    free(V);
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