#include <iostream>
#include <omp.h>
#include <clocale> 

int main() {
    setlocale(LC_ALL, "Russian");
    const int N = 4;
    const int M = 5;

#pragma omp parallel for schedule(static)
    for (int idx = 0; idx < N * M; ++idx) {
        int i = idx / M;
        int j = idx % M;

#pragma omp critical
        std::cout << "Нить " << omp_get_thread_num()
            << " выполнила (" << i << "," << j << ")\n";
    }

    return 0;
}