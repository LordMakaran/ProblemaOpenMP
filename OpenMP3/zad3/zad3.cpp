#include <cstdio>
#include <omp.h>
#include <clocale> 

int main() {
    setlocale(LC_ALL, "Russian");
    // Настоящая private-переменная: у каждой нити своя копия
    int local = 0;

#pragma omp parallel private(local) num_threads(4)
    {
        local = omp_get_thread_num();

#pragma omp critical
        printf("private local: нить %d, local = %d\n",
            omp_get_thread_num(), local);
    }

    // Указатель на общую память: фактически нити работают с одной переменной
    int sharedValue = 0;
    int* p = &sharedValue;

#pragma omp parallel num_threads(4)
    {
#pragma omp critical
        {
            *p += omp_get_thread_num();
        }
    }

    printf("sharedValue через указатель = %d\n", sharedValue);

    return 0;
}