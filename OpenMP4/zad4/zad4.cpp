#include <iostream>
#include <vector>
#include <omp.h>
#include <clocale> 

int main() {
    setlocale(LC_ALL, "Russian");
    const int N = 19;
    int Tmax = omp_get_max_threads();

    std::vector<int> count(Tmax, 0);

#pragma omp parallel
    {
        int t = omp_get_thread_num();

#pragma omp for schedule(static)
        for (int i = 0; i < N; ++i) {
            count[t]++;
        }
    }

    for (int t = 0; t < Tmax; ++t) {
        if (count[t] > 0) {
            std::cout << "Нить " << t << " получила " << count[t] << " итераций\n";
        }
    }

    return 0;
}