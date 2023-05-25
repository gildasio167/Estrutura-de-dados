#include <iostream>
#include <vector>

using namespace std;

void removeOcorrenciasRepetidasOrdenado(vector<int>& L) {
    int i = 0;
    while (i < L.size()) {
        int j = i + 1;
        while (j < L.size() && L[i] == L[j]) {
            j++;
        }
        if (j > i + 1) { // elementos repetidos
            L.erase(L.begin() + i + 1, L.begin() + j);
        }
        i = j;
    }
}

int main() {
    // exemplo de uso
    vector<int> L = {1, 1, 3, 4, 4, 4, 5, 6, 7, 7, 7};
    cout << "Lista original: ";
    for (int i = 0; i < L.size(); i++) {
        cout << L[i] << " ";
    }
    cout << endl;
    removeOcorrenciasRepetidasOrdenado(L);
    cout << "Lista resultante: ";
    for (int i = 0; i < L.size(); i++) {
        cout << L[i] << " ";
    }
    cout << endl;
    return 0;
}
