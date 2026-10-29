#include <cstdio>
#include <omp.h>
#include <clocale> 

int main() {
    setlocale(LC_ALL, "Russian");
    const int N = 1000000;

    int raceCounter = 0;
    int safeCounter = 0;

    // Гонка данных: результат непредсказуем
#pragma omp parallel for
    for (int i = 0; i < N; ++i) {
        raceCounter++;
    }

    // Безопасный вариант с atomic
#pragma omp parallel for
    for (int i = 0; i < N; ++i) {
#pragma omp atomic
        safeCounter++;
    }

    printf("raceCounter = %d (может быть меньше %d)\n", raceCounter, N);
    printf("safeCounter = %d (должно быть %d)\n", safeCounter, N);

    return 0;
}