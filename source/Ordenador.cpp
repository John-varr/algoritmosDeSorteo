#include "Ordenador.hpp"
#include <vector>
using namespace std;

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

void Ordenador::merge(uint32_t *A, uint32_t left, uint32_t mid, uint32_t right) const {
    uint32_t leftSize = mid - left + 1;
    uint32_t rightSize = right - mid;

    vector<uint32_t> leftArray(leftSize);
    vector<uint32_t> rightArray(rightSize);

    for (uint32_t i = 0; i < leftSize; i++) {
        leftArray[i] = A[left + i];
    }
    for (uint32_t j = 0; j < rightSize; j++) {
        rightArray[j] = A[mid + 1 + j];
    }

    uint32_t i = 0;
    uint32_t j = 0;
    uint32_t k = left;

    while (i < leftSize && j < rightSize) {
        if (leftArray[i] <= rightArray[j]) {
            A[k] = leftArray[i];
            i++;
        } else {
            A[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < leftSize) {
        A[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < rightSize) {
        A[k] = rightArray[j];
        j++;
        k++;
    }
}

void Ordenador::mergeSortRec(uint32_t *A, uint32_t left, uint32_t right) const {
    if (left < right) {
        uint32_t mid = left + (right - left) / 2;
        mergeSortRec(A, left, mid);
        mergeSortRec(A, mid + 1, right);
        merge(A, left, mid, right);
    }
}

void Ordenador::ordenamientoPorMezcla(uint32_t *A, uint32_t n) const {
    if (n <= 1) {
        return;
    }
    mergeSortRec(A, 0u, n - 1u);
}