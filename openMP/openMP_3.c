#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#define TOTAL 2048
int main()
{
    int A[TOTAL];
#pragma omp parallel for
    for (int i = 0; i < TOTAL; ++i)
    {
        A[i] = i * i;
        printf("Th[%d]: %02d=%03d\n", omp_get_thread_num(), i, A[i]);
    }
    system("pause");
    return 0;
}