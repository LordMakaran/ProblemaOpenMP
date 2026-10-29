#include <iostream>
#include <omp.h>
#include <clocale> 

int main() {
    setlocale(LC_ALL, "Russian");
    const int N = 20;

    std::cout << "guided:\n";
#pragma omp parallel for schedule(guided)
    for (int i = 0; i < N; ++i) {
#pragma omp critical
        std::cout << i << ":" << omp_get_thread_num() << " ";
    }

    std::cout << "\n\nguided,4:\n";
#pragma omp parallel for schedule(guided, 4)
    for (int i = 0; i < N; ++i) {
#pragma omp critical
        std::cout << i << ":" << omp_get_thread_num() << " ";
    }

    std::cout << "\n";
    return 0;
}