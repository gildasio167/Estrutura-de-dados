#include <iostream>
#include <vector>

using namespace std;

void removeDuplicates(vector<int>& l1, vector<int>& l2) {
    vector<int> result;
    int i = 0, j = 0;

    while (i < l1.size() && j < l2.size()) {
        if (l1[i] < l2[j]) {
            result.push_back(l1[i]);
            i++;
        }
        else if (l1[i] > l2[j]) {
            j++;
        }
        else {
            i++;
            j++;
        }
    }

    while (i < l1.size()) {
        result.push_back(l1[i]);
        i++;
    }

    l1 = result;
}

int main() {
    vector<int> l1 = {1, 2, 3, 4, 5};
    vector<int> l2 = {2, 4};

    removeDuplicates(l1, l2);

    for (int x : l1) {
        cout << x << " ";
    }

    return 0;
}
