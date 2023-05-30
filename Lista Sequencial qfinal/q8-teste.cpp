#include <iostream>

void removerElementos(int L1[], int& tamanhoL1, const int L2[], int tamanhoL2) {
    int i = 0; // Índice para percorrer L1
    int j = 0; // Índice para percorrer L2
    int k = 0; // Índice para percorrer L1 (modificado)

    while (i < tamanhoL1) {
        if (L1[i] < L2[j]) {
            L1[k] = L1[i];
            i++;
            k++;
        } else if (L1[i] > L2[j]) {
            j++;
        } else {
            i++;
            tamanhoL1--;
        }
    }
}

int main() {
    // Exemplo de entrada
    int L1[] = {1, 2, 3, 4, 5, 6, 7};
    int tamanhoL1 = sizeof(L1) / sizeof(L1[0]);

    int L2[] = {2, 4, 6};
    int tamanhoL2 = sizeof(L2) / sizeof(L2[0]);

    // Chamada da função para remover elementos de L2 em L1
    removerElementos(L1, tamanhoL1, L2, tamanhoL2);

    // Exibição do resultado
    for (int i = 0; i < tamanhoL1; i++) {
        std::cout << L1[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
