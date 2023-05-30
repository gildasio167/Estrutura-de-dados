#include <iostream>

void removerElementos(int L[], int& tamanhoL, const int L2[], int tamanhoL2) {
    int i = 0; // Índice para percorrer L
    int j = 0; // Índice para percorrer L2

    for (int k = 0; k < tamanhoL; k++) {
        if (i >= tamanhoL) {
            break;
        }

        if (L[i] < L2[j]) {
            L[k] = L[i];
            i++;
        } else if (L[i] > L2[j]) {
            j++;
        } else {
            i++;
            tamanhoL--;
        }
    }
}

int main() {
    // Exemplo de entrada
    int L[] = {1, 2, 3, 4};
    int tamanhoL = sizeof(L) / sizeof(L[0]);

    int L2[] = {2, 4, 6};
    int tamanhoL2 = sizeof(L2) / sizeof(L2[0]);

    // Chamada da função para remover elementos de L2 em L
    removerElementos(L, tamanhoL, L2, tamanhoL2);

    // Exibição do resultado
    for (int i = 0; i < tamanhoL; i++) {
        std::cout << L[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
