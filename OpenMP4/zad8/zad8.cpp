#include <iostream>
#include <omp.h>
#include <clocale>

int main() {
    setlocale(LC_ALL, "Russian");
    int n = 0; // Общая переменная

#pragma omp parallel shared(n)
    {
#pragma omp single
        {
            n = 3; 
        }

#pragma omp critical
        std::cout << "Нить " << omp_get_thread_num()
            << " видит n=" << n << "\n";
    }
    return 0;
}