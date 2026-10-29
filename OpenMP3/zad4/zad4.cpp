#include <cstdio>
#include <omp.h>
#include <clocale> 

int g;
#pragma omp threadprivate(g)

int main() {
    setlocale(LC_ALL, "Russian");
    int x = 42;
    g = 42;

    printf("До области: x = %d, g = %d\n", x, g);

#pragma omp parallel firstprivate(x) copyin(g) num_threads(4)
    {

        x += omp_get_thread_num();
        g += omp_get_thread_num();
        printf("нить %d: firstprivate x = %d, copyin g = %d\n", omp_get_thread_num(), x, g);
    }

    printf("После области: x = %d, g = %d\n", x, g);

    return 0;
}