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

void Ordenador::heapify(uint32_t *A, uint32_t n, uint32_t i) const {
    uint32_t largestIndex = i;
    uint32_t leftChild = 2 * i + 1;
    uint32_t rightChild = 2 * i + 2;

    if (leftChild < n) {
        if (A[leftChild] > A[largestIndex]) {
            largestIndex = leftChild;
        }
    }
    if (rightChild < n) {
        if (A[rightChild] > A[largestIndex]) {
            largestIndex = rightChild;
        }
    }

    if (largestIndex != i) {
        uint32_t temp = A[i];
        A[i] = A[largestIndex];
        A[largestIndex] = temp;

        heapify(A, n, largestIndex);
    }
}

void Ordenador::ordenamientoPorMonticulos(uint32_t *A, uint32_t n) const {
    if (n == 0) {
        return;
    }

    for (int buildIndex = static_cast<int>(n) / 2 - 1; buildIndex >= 0; buildIndex--) {
        heapify(A, n, static_cast<uint32_t>(buildIndex));
    }

    for (int endIndex = static_cast<int>(n) - 1; endIndex > 0; endIndex--) {
        uint32_t tmp = A[0];
        A[0] = A[endIndex];
        A[endIndex] = tmp;

        heapify(A, static_cast<uint32_t>(endIndex), 0u);
    }
}

uint32_t Ordenador::partition(uint32_t *A, uint32_t low, uint32_t high) const {
    uint32_t pivotValue = A[high];
    int iIndex = static_cast<int>(low) - 1;

    for (uint32_t jIndex = low; jIndex < high; jIndex++) {
        if (A[jIndex] < pivotValue) {
            iIndex++;
            uint32_t tmp = A[iIndex];
            A[iIndex] = A[jIndex];
            A[jIndex] = tmp;
        }
    }

    uint32_t tmp = A[iIndex + 1];
    A[iIndex + 1] = A[high];
    A[high] = tmp;

    return static_cast<uint32_t>(iIndex + 1);
}

void Ordenador::quickSortRec(uint32_t *A, uint32_t low, uint32_t high) const {
    if (low < high) {
        uint32_t pivotIndex = partition(A, low, high);

        if (pivotIndex > 0u) {
            quickSortRec(A, low, pivotIndex - 1u);
        }
        quickSortRec(A, pivotIndex + 1u, high);
    }
}


void Ordenador::ordenamientoRapido(uint32_t *A, uint32_t n) const {
    if (n <= 1) {
        return;
    }
    quickSortRec(A, 0u, n - 1u);
}

uint32_t Ordenador::getMax(uint32_t *A, uint32_t n) const {
    uint32_t maxValue = A[0];
    for (uint32_t idx = 1; idx < n; idx++) {
        if (A[idx] > maxValue) {
            maxValue = A[idx];
        }
    }
    return maxValue;
}