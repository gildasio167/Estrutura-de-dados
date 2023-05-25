#include <iostream>
#include <vector>

using namespace std;

void SelectionSort(int vet[], int p, int r){
    int index;

    while(p<r){
        index = p;

        for(int i = p+1; i <= r-1; i++){
            if(vet[i] < vet[index]) {
                index = i;
            }
        }
        swap(vet[index], vet[p]);
        p++;
    }
    
}

void BoubbleSort(int vet[], int p, int r){
    int index;

    while(r > p){
        index = p;

        for(int i = p+1; i <= r-1; i++){
            if(vet[i] > vet[index]){
                index = i;
            }
        }

        swap(vet[index],vet[r-1]);
        r--;
    }
}

void InsertionSort(int vet[], int p, int r){
    int j;

    for(int i = p+1; i <= r-1; i++){
        int x = vet[i];
        j = i-1;
        while( j > p-1 && vet[j] > x) {
            vet[j+1] = vet[j];
            j--;
        }
        vet[j+1] = x;
    }

}

int main(){
    int tam = 0;
    cin >> tam;
    int vet[tam];
    for(int i = 0; i < tam; i++){
        int valor;
        cin >> valor;
        vet[i] = valor;
    }

    //SelectionSort(vet, 0, tam);
    //BoubbleSort(vet, 0, tam);
    //InsertionSort(vet, 0, tam);

    for(int i = 0; i< tam; i++){
        cout << vet[i];
    }
    cout << endl;
    
}
