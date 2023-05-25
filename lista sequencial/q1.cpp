#include <iostream>
#include <vector>

using namespace std;

void removeValoresMenoresQueX(vector<int>& L, int x) {
    int n = L.size();
    int j = 0; // índice do último elemento que não é menor que x
    for (int i = 0; i < n; i++) {
        if (L[i] >= x) {
            L[j] = L[i];
            j++;
        }
    }
    L.resize(j); // redimensiona L para remover os elementos restantes que são menores que x
}

void remove(int vet[], int x, int tam){
    vet_aux = 
}

int main() {
    // exemplo de uso
    vector<int> L = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    int x = 5;
    int tam = x;
    removeValoresMenoresQueX(L, x);
    for (int i = 0; i < L.size(); i++) {
        cout << L[i] << " ";
    }
    cout << endl;
    return 0;
}
