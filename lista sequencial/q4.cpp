#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void removeOcorrenciasRepetidas(vector<int>& L) {
    unordered_set<int> elementosUnicos; // conjunto para armazenar elementos únicos
    vector<int> elementosRepetidos; // vetor para armazenar elementos repetidos

    for (int i = 0; i < L.size(); i++) {
        int elementoAtual = L[i];
        if (elementosUnicos.count(elementoAtual)) { // elemento repetido
            elementosRepetidos.push_back(elementoAtual);
        } else { // elemento único
            elementosUnicos.insert(elementoAtual);
        }
    }

    // remove as ocorrências repetidas
    for (int i = 0; i < elementosRepetidos.size(); i++) {
        L.erase(remove(L.begin(), L.end(), elementosRepetidos[i]), L.end());
    }
}

int main() {
    // exemplo de uso
    vector<int> L = {3, 1, 4, 1, 5, 4, 6, 7, 7, 3};
    cout << "Lista original: ";
    for (int i = 0; i < L.size(); i++) {
        cout << L[i] << " ";
    }
    cout << endl;
    removeOcorrenciasRepetidas(L);
    cout << "Lista resultante: ";
    for (int i = 0; i < L.size(); i++) {
        cout << L[i] << " ";
    }
    cout << endl;
    return 0;
}
