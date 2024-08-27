#include <stdio.h>
#include <omp.h>
#define TOTAL 2048

int main()
{
    int A[TOTAL];
#pragma omp parallel
    {
        int id = omp_get_thread_num();
        int nt = omp_get_num_threads();
        int tam = TOTAL / nt;
        int ini = id * tam;
        int fim = ini + tam - 1;
        int i;
        for (int i = ini; i < fim; i++)
        {
            A[i] = i * i;
            printf("Th[%d] : %02d = %03d\n", id, i, A[i]);
        }
    }
    return 0;
}