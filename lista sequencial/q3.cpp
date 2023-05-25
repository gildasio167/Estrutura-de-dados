#include <iostream>
#include <vector>

using namespace std;

bool inserirSemDuplicata(vector<int>& L, int x) {
    for (int i = 0; i < L.size(); i++) {
        if (L[i] == x) { // verifica se o elemento já existe na lista
            return false; // falha na inserção se o elemento já existe
        }
    }
    L.push_back(x); // adiciona o elemento ao final da lista
    return true;
}

int main() {
    // exemplo de uso
    vector<int> L = {3, 1, 4, 1, 5};
    int x = 2;
    if (inserirSemDuplicata(L, x)) {
        cout << "Insercao bem sucedida. Lista resultante: ";
        for (int i = 0; i < L.size(); i++) {
            cout << L[i] << " ";
        }
        cout << endl;
    } else {
        cout << "Falha na insercao. Elemento duplicado." << endl;
    }
    return 0;
}
