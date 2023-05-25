#include <iostream>
#include <stdio.h>
#include <stdlib.h>


using namespace std;

typedef struct{
    int *v;
    int f; //índice do último elemento
    int tam; // tamanho: tamanho máximo da lista
} ListaSeq;

ListaSeq criarLista(int tam){
    ListaSeq L;
    L.v = (int*) malloc(tam*sizeof(int));
    L.f = -1;
    L.tam = tam;
    return L;
}

int buscar(ListaSeq L, int x){
    for(int i=0; i<(L.f+1); i++){
        if(L.v[i] == x){
            return i;
        }
    }
}

int remover(ListaSeq *L, int x){
    int ind = buscar(*L, x);
    if(ind == -1){
        return 0;
    }
    else{
        L->v[ind] = L->v[L->f];
        (L->f)--;
        return 1;
    }
}

void Merge

int main(){
    int tam;
    cin >> tam;
    

    int x;
    cin >> x;

    
}