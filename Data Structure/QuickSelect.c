#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int Partition(int *V, int intBegin, int intEnd);
int QuickSelect(int *V, int intBegin, int intEnd, int int_K);

int main(void)
{
    printf("Something will exist here! See U soon!\n");
}

int QuickSelect(int *V, int intBegin, int intEnd, int int_K)
{
    int intPospivot;

    if((intEnd - intBegin) == 1)
    {
        return V[intBegin];
    }

    intPospivot = Partition(V, intBegin, intEnd);

    if(intPospivot == int_K)
    {
        return V[int_K];
    }
    else if(int_K < intPospivot)
    {
        QuickSelect(V, intBegin, intPospivot, int_K);
    }
    else
    {
        QuickSelect(V, intPospivot, intEnd, int_K);
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