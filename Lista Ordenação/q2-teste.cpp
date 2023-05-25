#include <iostream>
#include <vector>

using namespace std;

void push_back(int* vet, int valor){
    vet.push_back(valor);
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

int* ConcatenarVetores(int* vet1,int** vet2[], int tam1, int tam2){
    int tam3 = tam1 + tam2;
    int vet3[tam3];
    for(int i = 0; i < tam1; i++){
        vet3.push_back(vet1[i]);
    }
    for(int i = 0; i < tam2; i++){
        vet3.push_back(vet2[i]);
    }
    return vet3;
}


int main(){
    int tam = 0;
    cin >> tam;
    int vet1[tam];
    for(int i = 0; i < tam; i++){
        int valor;
        cin >> valor;
        vet1[i] = valor;
    }
    BoubbleSort(vet1, 0, tam);
    
    int tam2 = 0;
    cin >> tam2;
    int vet2[tam2];
    for(int i = 0; i < tam2; i++){
        int valor;
        cin >> valor;
        vet2[i] = valor;
    }
    BoubbleSort(vet2, 0, tam2);
    int tam3 = tam + tam2;
    int vet3[tam3] = ConcatenarVetores(vet1, int* vet2, tam, tam2);
    
    BoubbleSort(vet3, 0, tam3);
    for(int i = 0; i < tam3; i++){
        cout << vet3[i] << " ";
    }
    cout << endl;
    return 0;
}