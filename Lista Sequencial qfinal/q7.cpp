#include <iostream>

using namespace std;

void remove(int L[], int& tam, int x){
    int i = 0;

    while(i < tam){
        if(L[i] == x){
            for(int j = i; j < tam; j++){
                L[j] = L[j+1];
            }
            tam--;
        }else{
            i++;
        }
    }
    
    
}

void removeduplicatas(int L[], int L2[], int& tam, int& tam2){
    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam2; j++){
            if(L2[i] == L[j]){
                remove(L, tam, L[j]);
            }
        }
    }
}

void removerepetidos(int L[], int& tam, const int L2[], int tam2){
    int i = 0;
    int j = 0;

    for(int k = 0; k < tam; k++){
        if(i >= tam){
            break;
        }

        if(L[i] < L2[j]){
            L[k] = L[i];
            i++;
        } else if(L[i] > L2[j]){
            j++;
        } else {
            i++;
            tam--;
        }
    }
}


int main(){
    int tam;
    cin >> tam;

    int L[tam];
    int tam2;
    cin >> tam2;

    int L2[tam2];
    int num = 1;
    for(int i = 0; i < tam; i++){
        L[i] = num;
        L[i+1] = num;
        num++;
        i++;
    }
    num = 1;
    for(int i = 0; i < tam2; i++){
        L2[i] = num;
        num++;
    }
    cout << "-" << endl;
    //removeduplicatas(L, L2, tam, tam2);
    removerepetidos(L, tam, L2, tam2);
    for(int i = 0; i < tam; i++){
        cout << L[i] << " ";
    }
    
    cout << endl;
    cout << "---------" << endl;

    for(int i = 0; i < tam2; i++){
        cout << L2[i] << " ";
    }
    cout << endl;
    return 0;

}