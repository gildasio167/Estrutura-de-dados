#include <iostream>
#include <vector>

using namespace std;

void removeOcorrencias(vector<int>& L1, const vector<int>& L2) {
    int i = 0, j = 0;
    while (i < L1.size() && j < L2.size()) {
        if (L1[i] < L2[j]) {
            i++;
        } else if (L1[i] == L2[j]) {
            L1.erase(L1.begin() + i);
        } else {
            j++;
        }
    }
}

int main() {
    // exemplo de uso
    vector<int> L1 = {1, 3, 3, 4, 5, 6, 6, 7, 9};
    vector<int> L2 = {3, 6, 8};
    cout << "Lista 1 original: ";
    for (int i = 0; i < L1.size(); i++) {
        cout << L1[i] << " ";
    }
    cout << endl;
    cout << "Lista 2: ";
    for (int i = 0; i < L2.size(); i++) {
        cout << L2[i] << " ";
    }
    cout << endl;
    removeOcorrencias(L1, L2);
    cout << "Lista 1 após remoção: ";
    for (int i = 0; i < L1.size(); i++) {
        cout << L1[i] << " ";
    }
    cout << endl;
    return 0;
}
