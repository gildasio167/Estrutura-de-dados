#include <iostream>

const int MAX_SIZE = 100; // Tamanho máximo do array

void RemoveTodos(int L[], int& size, int x) {
    int newSize = 0; // Tamanho atualizado da lista
    
    // Percorre a lista L e remove os elementos com valor igual a x
    for (int i = 0; i < size; i++) {
        if (L[i] != x) {
            L[newSize] = L[i]; // Move o elemento para a nova posição
            newSize++; // Incrementa o tamanho atualizado
        }
    }
    
    size = newSize; // Atualiza o tamanho da lista
}

int main() {
    int lista[MAX_SIZE] = {2, 3, 5, 3, 7, 5, 3, 8};
    int size = 8; // Tamanho atual da lista
    int valor = 3;
    
    std::cout << "Lista original: ";
    for (int i = 0; i < size; i++) {
        std::cout << lista[i] << " ";
    }
    std::cout << std::endl;
    
    RemoveTodos(lista, size, valor);
    
    std::cout << "Lista após remover todos os elementos com valor " << valor << ": ";
    for (int i = 0; i < size; i++) {
        std::cout << lista[i] << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
