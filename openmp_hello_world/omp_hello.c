// Original code from
// https://computing.llnl.gov/tutorials/openMP/samples/C/omp_hello.c

#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
    int nthreads, tid;

    #pragma omp parallel private(nthreads, tid)
    {
        tid = omp_get_thread_num();
        printf("Hello World from thread = %d\n", tid);

        if (tid==0)
        {
            nthreads = omp_get_num_threads();
            printf("Number of threads = %d\n", nthreads);
        }
    }
    // out of the parallel region
    if (tid==0)
    {
        nthreads = omp_get_num_threads();
        printf("Number of threads ouside of parallel = %d\n", nthreads);
    }
}
