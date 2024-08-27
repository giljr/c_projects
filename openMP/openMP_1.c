#include <omp.h>
#include <stdio.h>

int main()
{
#pragma omp parallel num_threads(4)
    {
        int id = omp_get_thread_num();
        printf("I am thread number %d.\n", id);
    }
    return 0;
}