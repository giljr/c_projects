#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000

double A[SIZE], B[SIZE];

double funcao_complexa_1(int id)
{
    return id * 2.0;
}

double funcao_complexa_2(double *arr, int id)
{
    return arr[id] + 2.0;
}

int main()
{
    clock_t start, end;
    double cpu_time_used;

    // Start timing
    start = clock();

    // Compute A[i]
    for (int i = 0; i < SIZE; ++i)
    {
        A[i] = funcao_complexa_1(i);
    }

    // Compute B[i]
    for (int i = 0; i < SIZE; ++i)
    {
        B[i] = funcao_complexa_2(A, i);
    }

    // End timing
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Print the results for verification
    for (int i = 0; i < SIZE; i++)
    {
        printf("A[%d] = %f, B[%d] = %f\n", i, A[i], i, B[i]);
    }

    // Print the execution time
    printf("Non-OpenMP Execution Time: %f seconds\n", cpu_time_used);

    return 0;
}
