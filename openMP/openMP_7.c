#include <stdio.h>
#include <time.h>
#define TOTAL 200000 //100000 // 2048

int main()
{
    int A[TOTAL];
    clock_t start, end;
    double cpu_time_used;

    // Start timing
    start = clock();

    for (int i = 0; i < TOTAL; ++i)
    {
        A[i] = i * i;
        // Comment out printf to reduce I/O overhead
        // printf("%02d=%03d\n", i, A[i]);
    }

    // End timing
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Print the execution time
    printf("Non-OpenMP Execution Time: %f seconds\n", cpu_time_used);

    return 0;
}
