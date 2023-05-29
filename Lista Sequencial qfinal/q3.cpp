#include <iostream>

using namespace std;

void inserir(int L[], int& tam, int x){
    for(int i = 0; i < tam; i++){
        if(L[i] == x){
        return;
        }  
    }
    tam++;
    L[tam-1] = x;
    
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

    inserir(L, tam, x);
    for(int i = 0; i < tam; i++){
        cout << L[i] << " ";
    }
    cout << endl;
    return 0;


}