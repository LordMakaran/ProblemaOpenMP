#include <iostream>
#include <vector>
#include <omp.h>
#include <clocale> 

int main()
{
    setlocale(LC_ALL, "Russian");
    const int n = 1000000;

    std::vector<double> a(n);
    std::vector<double> b(n);

    for (int i = 0; i < n; ++i) {
        a[i] = 1.0 + i * 0.5;
        b[i] = 2.0 - i * 0.25;
    }

    double dot = 0.0;

#pragma omp parallel for reduction(+:dot) schedule(static)
    for (int i = 0; i < n; ++i) {
        dot += a[i] * b[i];
    }

    std::cout << "n = " << n << "\n";
    std::cout << "dot = " << dot << "\n";

    return 0;
}