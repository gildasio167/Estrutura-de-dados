#include <iostream>
#include <vector>

void merge(std::vector<int>& arr, int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    std::vector<int> leftArr(n1);
    std::vector<int> rightArr(n2);

    // Copia os elementos para os vetores temporários
    for (int i = 0; i < n1; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        rightArr[j] = arr[middle + 1 + j];
    }

    // Mescla os dois vetores temporários em arr
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copia os elementos restantes de leftArr, se houver
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Copia os elementos restantes de rightArr, se houver
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        // Ordena a metade esquerda
        mergeSort(arr, left, middle);

        // Ordena a metade direita
        mergeSort(arr, middle + 1, right);

        // Combina as metades ordenadas
        merge(arr, left, middle, right);
    }
}

int main() {
    std::vector<int> arr = {8, 2, 5, 3, 1, 6, 4, 7};

    mergeSort(arr, 0, arr.size() - 1);

    // Imprime o vetor ordenado
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
