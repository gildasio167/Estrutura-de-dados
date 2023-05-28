#include <iostream>

using namespace std;

void remove(int L[], int tam, int x){
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


void removermenores(int L[], int& tam, int x){
    int tam2 = tam;
    int L2[tam2];
    int j = 0;
    for(int i = 0; i < tam; i++){
        if(L[i] >= x){
            L2[j] = L[i];
            j++;
        }
    }
    for(int j = 0; j < tam2; j++){
        if(L2[j] < x){
            remove(L2, tam2, L2[j]);
            tam2--;
        }
    }
    for(int i = 0; i < tam; i++){
        remove(L, tam, L[i]);
    }
    tam2 = j;
    for(int i = 0; i < tam2; i++){
        L[i] = L2[i];
    }
    tam = tam2;
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

    removermenores(L, tam, x);

    for(int i = 0; i < tam; i++){
        cout << L[i] << " ";
    }

    return 0;

}