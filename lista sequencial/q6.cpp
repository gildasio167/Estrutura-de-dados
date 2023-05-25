#include <iostream>
#include <vector>

using namespace std;

void insercaoOrdenada(vector<int>& L, int x) {
    int i = 0;
    while (i < L.size() && L[i] < x) {
        i++;
    }
    if (i < L.size() && L[i] == x) {
        cout << "Elemento já existe na lista." << endl;
    } else {
        L.insert(L.begin() + i, x);
    }
}

int main() {
    // exemplo de uso
    vector<int> L = {1, 3, 5, 7};
    cout << "Lista original: ";
    for (int i = 0; i < L.size(); i++) {
        cout << L[i] << " ";
    }
    cout << endl;
    insercaoOrdenada(L, 4);
    cout << "Lista após inserção: ";
    for (int i = 0; i < L.size(); i++) {
        cout << L[i] << " ";
    }
    cout << endl;
    insercaoOrdenada(L, 5);
    cout << "Lista após segunda inserção: ";
    for (int i = 0; i < L.size(); i++) {
        cout << L[i] << " ";
    }
    cout << endl;
    return 0;
}
