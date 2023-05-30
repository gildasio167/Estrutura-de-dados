#include <iostream>

void mesclarListas(const int L1[], int tamanhoL1, const int L2[], int tamanhoL2, int novaLista[]) {
    int i = 0; // Índice para percorrer L1
    int j = 0; // Índice para percorrer L2
    int k = 0; // Índice para percorrer a nova lista

    // Percorre as listas L1 e L2 ao mesmo tempo
    while (i < tamanhoL1 && j < tamanhoL2) {
        if (L1[i] < L2[j]) {
            novaLista[k] = L1[i];
            i++;
        } else {
            novaLista[k] = L2[j];
            j++;
        }
        k++;
    }

    // Copia os elementos restantes de L1, se houver
    while (i < tamanhoL1) {
        novaLista[k] = L1[i];
        i++;
        k++;
    }

    // Copia os elementos restantes de L2, se houver
    while (j < tamanhoL2) {
        novaLista[k] = L2[j];
        j++;
        k++;
    }
}

void exibirLista(const int lista[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        std::cout << lista[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    // Exemplo de uso

    // Lista Sequencial 1
    int L1[] = {1, 3, 5, 7, 9};
    int tamanhoL1 = sizeof(L1) / sizeof(L1[0]);

    // Lista Sequencial 2
    int L2[] = {2, 4, 6, 8};
    int tamanhoL2 = sizeof(L2) / sizeof(L2[0]);

    // Nova lista (mescla das listas L1 e L2)
    int novaLista[tamanhoL1 + tamanhoL2];

    // Mescla as listas L1 e L2 na nova lista
    mesclarListas(L1, tamanhoL1, L2, tamanhoL2, novaLista);

    // Exibe a nova lista
    std::cout << "Nova lista: ";
    exibirLista(novaLista, tamanhoL1 + tamanhoL2);

    return 0;
}
