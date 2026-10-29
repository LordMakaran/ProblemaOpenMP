#include <iostream>
#include <omp.h>
#include <clocale> 

int main() {
    setlocale(LC_ALL, "Russian");
#pragma omp parallel
    {
        int id = omp_get_thread_num();
        int T = omp_get_num_threads();
#pragma omp critical
        std::cout << "Область 1: id=" << id << ", всего нитей=" << T << "\n";
    }

#pragma omp parallel
    {
        int id = omp_get_thread_num();
        int T = omp_get_num_threads();
#pragma omp critical
        std::cout << "Область 2: id=" << id << ", всего нитей=" << T << "\n";
    }

    return 0;
}