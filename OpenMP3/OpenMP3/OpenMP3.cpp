#include <cstdio>
#include <omp.h>
#include <clocale> 

int main() {
    setlocale(LC_ALL, "Russian");
    int x = 100;

    printf("Последовательная область: x = %d\n", x);

    // x — общая переменная
#pragma omp parallel shared(x) num_threads(4)
    {
#pragma omp critical
        printf("shared: нить %d видит x = %d\n",
            omp_get_thread_num(), x);
    }

    // x — локальная переменная для каждой нити
#pragma omp parallel private(x) num_threads(4)
    {
        x = omp_get_thread_num() + 1;

#pragma omp critical
        printf("private: нить %d имеет x = %d\n",
            omp_get_thread_num(), x);
    }

    printf("После параллельных областей: x = %d\n", x);

    return 0;
}