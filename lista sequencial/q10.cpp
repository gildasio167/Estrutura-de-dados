#include <iostream>
#include <vector>

using namespace std;

vector<int> uniaoListas(vector<int> lista1, vector<int> lista2) {
    vector<int> uniao;
    int p1 = 0; // ponteiro para percorrer a lista 1
    int p2 = 0; // ponteiro para percorrer a lista 2

    while (p1 < lista1.size() && p2 < lista2.size()) {
        if (lista1[p1] == lista2[p2]) {
            uniao.push_back(lista1[p1]);
            p1++;
            p2++;
        } else if (lista1[p1] < lista2[p2]) {
            uniao.push_back(lista1[p1]);
            p1++;
        } else {
            uniao.push_back(lista2[p2]);
            p2++;
        }
    }

    while (p1 < lista1.size()) {
        uniao.push_back(lista1[p1]);
        p1++;
    }

    while (p2 < lista2.size()) {
        uniao.push_back(lista2[p2]);
        p2++;
    }

    return uniao;
}

int main() {
    vector<int> lista1 = {1, 3, 5, 7, 9};
    vector<int> lista2 = {2, 4, 6, 8, 10};

    vector<int> uniao = uniaoListas(lista1, lista2);

    for (int i = 0; i < uniao.size(); i++) {
        cout << uniao[i] << " ";
    }

    return 0;
}
