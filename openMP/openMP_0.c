#include <omp.h>
#include <stdio.h>

int main()
{
    printf("INI.\n");

#pragma omp parallel
    {
        printf("I have a passion for parallelism!\n");
    }

    printf("END.\n");
    return 0;
}
