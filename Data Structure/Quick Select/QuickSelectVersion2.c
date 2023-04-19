#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int Partition(int *V, int intBegin, int intEnd);
int QuickSelect(int *V, int intBegin, int intEnd, int int_K);

int main()
{
    /* Exemplo de uso do QuickSelect */
    int V[] = {4, 9, 1, 7, 2, 8, 10, 5, 3, 6};
    int int_tam = sizeof(V) / sizeof(int);
    int int_K = 5; // encontra o 5o menor elemento
    int i;

    int intResult = QuickSelect(V, 0, int_tam - 1, int_K);

    printf("%d", intResult); // Deve imprimir "5"
    printf("\n\n");

    for(i = 0; i < int_tam; i++){
        printf("%4d", V[i]);
    }

    return 0;
}

int QuickSelect(int *V, int intBegin, int intEnd, int int_K)
{
    int intPospivot;

    /* Verifica se o vetor possui apenas um elemento. Se possuir, retorna esse elemento. */
    if((intEnd - intBegin) == 0)
    {
        return V[intBegin];
    }

    intPospivot = Partition(V, intBegin, intEnd);

    if(intPospivot == int_K) 
    {
        return V[int_K];
    }
    else if(int_K < intPospivot) /* lado esquerdo do vetor */
    {
        return QuickSelect(V, intBegin, intPospivot - 1, int_K);
    }
    else /* lado direito do vetor */
    {
        return QuickSelect(V, intPospivot + 1, intEnd, int_K);
    }
}

int Partition(int *V, int intBegin, int intEnd)
{
    int intPos, intPivot, int_i, int_j, int_temp;

    /* Seleciona um elemento aleatório como pivô */
    srand(time(NULL));
    intPos = intBegin + (rand() % (intEnd - intBegin + 1));

    intPivot = V[intPos];
    V[intPos] = V[intBegin];
    V[intBegin] =  intPivot;

    int_i = intBegin + 1;
    int_j = intEnd - 1;

    while(int_i <= int_j)
    {
        while(int_i <= int_j && V[int_i] < intPivot)
        {
            int_i++;
        }

        while(int_j >= int_i && V[int_j] >= intPivot)
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
