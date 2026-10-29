#include <iostream>
#include <omp.h>
#include <clocale> 

int main() {
    setlocale(LC_ALL, "Russian");
    const int N = 20;

#pragma omp parallel
    {
        int t = omp_get_thread_num();
        int T = omp_get_num_threads();

        for (int i = t; i < N; i += T) {
#pragma omp critical
            std::cout << "Нить " << t << " выполнила i=" << i << "\n";
        }
    }

    return 0;
}