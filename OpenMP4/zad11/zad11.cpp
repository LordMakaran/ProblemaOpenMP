#include <iostream>
#include <vector>
#include <limits>
#include <omp.h>
#include <clocale> 

int main()
{
    setlocale(LC_ALL, "Russian");
    const int n = 1000000;

    std::vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        v[i] = (i * 37 % 100000) - 50000;
    }

    int maxv = std::numeric_limits<int>::min();

#pragma omp parallel
    {
        int local_max = std::numeric_limits<int>::min();

#pragma omp for schedule(static)
        for (int i = 0; i < n; ++i) {
            if (v[i] > local_max) {
                local_max = v[i];
            }
        }

#pragma omp critical
        {
            if (local_max > maxv) {
                maxv = local_max;
            }
        }
    }

    std::cout << "n = " << n << "\n";
    std::cout << "max = " << maxv << "\n";

    return 0;
}