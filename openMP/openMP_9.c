#include <stdio.h>
#include <omp.h>

#define TOTAL 1000

// Example of complex function calculations
float funcao_complexa_1(int i)
{
    return (float)(i * 2.0); // Simple example function
}

float funcao_complexa_2(float B)
{
    return (float)(B + 2.0); // Simple example function
}

int main()
{
    float res = 0.0; // Shared variable to accumulate results

#pragma omp parallel
    {
        float B; // Private variable for each thread
        int i, id, nthreads;

        id = omp_get_thread_num();        // Get the thread ID
        nthreads = omp_get_num_threads(); // Get the number of threads

        // Divide the work among threads
        for (i = id; i < TOTAL; i += nthreads)
        {
            B = funcao_complexa_1(i); // Perform a complex computation

// Critical section: only one thread can execute this at a time
#pragma omp critical
            {
                res += funcao_complexa_2(B); // Update the shared variable
            }
        }
    }

    // Output the result after parallel computation
    printf("Result: %f\n", res);

    return 0;
}
