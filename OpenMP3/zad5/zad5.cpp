#include <cstdio>
#include <omp.h>
#include <clocale> 

int t;
#pragma omp threadprivate(t)

int main() {
    setlocale(LC_ALL, "Russian");
    omp_set_dynamic(0); // важно для сохранения threadprivate-копий
    t = -1;

#pragma omp parallel num_threads(4)
    {
        t = omp_get_thread_num();

#pragma omp critical
        printf("первая область: нить %d установила t = %d\n",
            omp_get_thread_num(), t);
    }

    printf("После первой области в последовательной части: t = %d\n", t);

#pragma omp parallel num_threads(4)
    {
#pragma omp critical
        printf("вторая область: нить %d видит t = %d\n",
            omp_get_thread_num(), t);
    }

    return 0;
}