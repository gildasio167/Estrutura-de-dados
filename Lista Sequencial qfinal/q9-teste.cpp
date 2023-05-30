#include <iostream>

// Função para calcular a união entre duas listas sequenciais
int* uniaoListas(const int L1[], int tamanhoL1, const int L2[], int tamanhoL2, int& tamanhoUniao) {
    int* uniao = new int[tamanhoL1 + tamanhoL2]; // Array para armazenar a união
    int i = 0; // Índice para percorrer L1
    int j = 0; // Índice para percorrer L2
    int k = 0; // Índice para percorrer a união

    // Percorre L1 e L2 ao mesmo tempo, adicionando os elementos na união
    while (i < tamanhoL1 && j < tamanhoL2) {
        if (L1[i] < L2[j]) {
            uniao[k] = L1[i];
            i++;
            k++;
        } else if (L1[i] > L2[j]) {
            uniao[k] = L2[j];
            j++;
            k++;
        } else {
            uniao[k] = L1[i];
            i++;
            j++;
            k++;
        }
    }

    // Copia os elementos restantes de L1, se houver
    while (i < tamanhoL1) {
        uniao[k] = L1[i];
        i++;
        k++;
    }

    // Copia os elementos restantes de L2, se houver
    while (j < tamanhoL2) {
        uniao[k] = L2[j];
        j++;
        k++;
    }

    tamanhoUniao = k; // Define o tamanho da união

    return uniao;
}

// Função para calcular a interseção entre duas listas sequenciais
int* intersecaoListas(const int L1[], int tamanhoL1, const int L2[], int tamanhoL2, int& tamanhoIntersecao) {
    int* intersecao = new int[tamanhoL1]; // Array para armazenar a interseção
    int i = 0; // Índice para percorrer L1
    int j = 0; // Índice para percorrer L2
    int k = 0; // Índice para percorrer a interseção

    // Percorre L1 e L2 ao mesmo tempo, adicionando os elementos na interseção
    while (i < tamanhoL1 && j < tamanhoL2) {
        if (L1[i] < L2[j]) {
            i++;
        } else if (L1[i] > L2[j]) {
            j++;
        } else {
            intersecao[k] = L1[i];
            i++;
            j++;
            k++;
        }
    }

    tamanhoIntersecao = k; // Define o tamanho da interseção

    return intersecao;
}

// Função para exibir os elementos de um array
void exibirArray(const int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    // Exemplo de uso

    // Lista Sequencial 1
    int L1[] = {1, 2, 3, 4, 5};
    int tamanhoL1 = sizeof(L1) / sizeof(L1[0]);

    // Lista Sequencial 2
    int L2[] = {3, 4, 5, 6, 7};
    int tamanhoL2 = sizeof(L2) / sizeof(L2[0]);

    // Variáveis para armazenar os resultados
    int tamanhoUniao, tamanhoIntersecao;

    // Calcula a união das listas L1 e L2
    int* uniao = uniaoListas(L1, tamanhoL1, L2, tamanhoL2, tamanhoUniao);

    // Exibe a união
    std::cout << "Uniao: ";
    exibirArray(uniao, tamanhoUniao);

    // Calcula a interseção das listas L1 e L2
    int* intersecao = intersecaoListas(L1, tamanhoL1, L2, tamanhoL2, tamanhoIntersecao);

    // Exibe a interseção
    std::cout << "Intersecao: ";
    exibirArray(intersecao, tamanhoIntersecao);

    // Libera a memória alocada para os arrays
    delete[] uniao;
    delete[] intersecao;

    return 0;
}
