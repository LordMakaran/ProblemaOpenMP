#include <iostream>
#include <omp.h>
#include <clocale> 

int main() {
    setlocale(LC_ALL, "Russian");
    const int N = 12;

    for (int run = 0; run < 3; ++run) {
        std::cout << "Запуск " << run << "\n";

#pragma omp parallel for schedule(dynamic, 1)
        for (int i = 0; i < N; ++i) {
#pragma omp critical
            std::cout << "i=" << i
                << " -> нить " << omp_get_thread_num() << "\n";
        }
    }

    return 0;
}