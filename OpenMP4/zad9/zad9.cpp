#include <iostream>
#include <omp.h>
#include <clocale> 

void work(int i) {
#pragma omp critical
    std::cout << "Работа " << i << " выполнена нитью "
        << omp_get_thread_num() << "\n";
}

int main() {
    setlocale(LC_ALL, "Russian");
    const int N = 10;
    int next = 0;

#pragma omp parallel
    {
        while (true) {
            int i;

#pragma omp critical
            {
                i = next;
                if (i < N) {
                    ++next;
                }
            }

            if (i >= N) {
                break;
            }

            work(i);
        }
    }

    return 0;
}