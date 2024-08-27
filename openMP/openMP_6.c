#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

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
    double start, end;
    double cpu_time_used;

    // Set the number of threads to 8
    omp_set_num_threads(8);

    // Start timing
    start = omp_get_wtime();

    // Initialize OpenMP parallel region
#pragma omp parallel
    {
        int id = omp_get_thread_num();
        int num_threads = omp_get_num_threads();

        // First parallel region: Compute A[id]
#pragma omp for
        for (int i = 0; i < SIZE; ++i)
        {
            A[i] = funcao_complexa_1(i);
        }

        // Synchronize threads to ensure A is fully computed
#pragma omp barrier

        // Second parallel region: Compute B[id]
#pragma omp for
        for (int i = 0; i < SIZE; ++i)
        {
            B[i] = funcao_complexa_2(A, i);
        }
    }

    // End timing
    end = omp_get_wtime();
    cpu_time_used = end - start;

    // Print the results for verification
    for (int i = 0; i < SIZE; i++)
    {
        printf("A[%d] = %f, B[%d] = %f\n", i, A[i], i, B[i]);
    }

    // Print the execution time
    printf("OpenMP Execution Time: %f seconds\n", cpu_time_used);

    return 0;
}
