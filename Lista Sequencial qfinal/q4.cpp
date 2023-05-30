#include <iostream>

using namespace std;

void removeocorrencias(int L[], int& tam){
    for(int i = 0; i < tam; i++){
        for(int j = i+1; j < tam; j++){
            if(L[i] == L[j]){
                for(int k = j; k < tam; k++){
                    L[k] = L[k+1];
                }
                tam--;
                j--;
            }
        }
    }
}

int main(){
    int tam;
    cin >> tam;

    int L[tam];

    for(int i = 0; i < tam; i++){
        cin >> L[i];
    }
    removeocorrencias(L, tam);
    for(int i = 0; i < tam; i++){
        cout << L[i] << " ";
    }
    cout << endl;
    return 0;
    

}