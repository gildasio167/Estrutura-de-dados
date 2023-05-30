#include <iostream>

using namespace std;

void inserirordenado(int L[], int& tam, int x){
    int i = 0;
    while(i < tam && L[i] < x){
        i++;
    }
    for(int j = tam; j > i; j--){
        L[j] = L[j-1];
    }
    L[i] = x;
    tam++;
}

int main(){
    int tam;
    cin >> tam;

    int L[tam];

    int num = 1;
    for(int i = 0; i < tam; i++){
        L[i] = num;
        num++;
    }
    int x;
    cin >> x;
    inserirordenado(L, tam, x);
    for(int i = 0; i < tam; i++){
        cout << L[i] << " ";
    }
    cout << endl;
    return 0;
}