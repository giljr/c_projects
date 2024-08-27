#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#define TOTAL 200000 // 100000 // 2048

int main()
{
    int A[TOTAL];
    double start, end;
    double cpu_time_used;

    // Set the number of threads
    omp_set_num_threads(4);

    // Start timing
    start = omp_get_wtime();

#pragma omp parallel for
    for (int i = 0; i < TOTAL; ++i)
    {
        A[i] = i * i;
        // Comment out printf to reduce I/O overhead
        // printf("Th[%d]: %02d=%03d\n", omp_get_thread_num(), i, A[i]);
    }

    // End timing
    end = omp_get_wtime();
    cpu_time_used = end - start;

    // Print the execution time
    printf("OpenMP Execution Time: %f seconds\n", cpu_time_used);

    return 0;
}
