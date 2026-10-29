#include <iostream>
#include <omp.h>
#include <clocale> 

void section0() {
#pragma omp critical
    std::cout << "section0, нить " << omp_get_thread_num() << "\n";
}

void section1() {
#pragma omp critical
    std::cout << "section1, нить " << omp_get_thread_num() << "\n";
}

void section2() {
#pragma omp critical
    std::cout << "section2, нить " << omp_get_thread_num() << "\n";
}

int main() {
    setlocale(LC_ALL, "Russian");
#pragma omp parallel
    {
        int t = omp_get_thread_num();

        if (t == 0) {
            section0();
        }
        else if (t == 1) {
            section1();
        }
        else if (t == 2) {
            section2();
        }
    }

    return 0;
}