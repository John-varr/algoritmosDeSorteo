#include "Ordenador.hpp"

void Ordenador::ordenamientoPorSeleccion(uint32_t *A, uint32_t n) const {
    for (uint32_t currentIndex = 0; currentIndex + 1 < n; currentIndex++) {
        uint32_t minIndex = currentIndex;

        for (uint32_t scanIndex = currentIndex + 1; scanIndex < n; scanIndex++) {
            if (A[scanIndex] < A[minIndex]) {
                minIndex = scanIndex;
            }
        }

        if (minIndex != currentIndex) {
            uint32_t tempValue = A[currentIndex];
            A[currentIndex] = A[minIndex];
            A[minIndex] = tempValue;
        }
    }
}

void Ordenador::ordenamientoPorInserccion(uint32_t *A, uint32_t n) const {
    for (uint32_t passIndex = 1; passIndex < n; passIndex++) {
        uint32_t currentValue = A[passIndex];
        int scanIndex = static_cast<int>(passIndex) - 1;

        while (scanIndex >= 0 && A[scanIndex] > currentValue) {
            A[scanIndex + 1] = A[scanIndex];
            scanIndex = scanIndex - 1;
        }

        A[scanIndex + 1] = currentValue;
    }
}