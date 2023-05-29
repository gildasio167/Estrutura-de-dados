#include <iostream>

using namespace std;

void remove(int L[], int& tam, int x){
    int i = 0;
    int tam2 = tam;
    while(i < tam2){
        if(L[i] == x){
            for(int j = i; j < tam2; j++){
                L[j] = L[j+1];
            }
            tam2--;
        }else{
            i++;
        }
    }
    
    
}

void removemenores(int L[], int& tam, int& x){
    for(int i = 0; i <= tam; i++){
        if(L[i] < x){
            remove(L, tam, L[i]);
            tam--;
        }
    }
    if(L[0] < x){
        removemenores(L, tam, x);
    }
}

int main(){
    int tam;
    cin >> tam;
    int L[tam];
    int num =1;

    for(int i = 0; i < tam; i++){
        L[i] = num;
        num++;
    }
    int x;
    cin >> x;

    removemenores(L, tam, x);
    cout << tam << endl;
    for(int i = 0; i < tam; i++){
        cout << L[i] << " ";
    }
    cout << endl;
    return 0;
}