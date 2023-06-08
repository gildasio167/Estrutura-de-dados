#include <iostream>

using namespace std;

struct Pilha{
    int *V;
    int tam;
    int topo;
};

typedef struct Pilha pilha;

Pilha criarPilha(int tam){
    Pilha P;
    P.V = (int *) malloc(tam * sizeof(int));
    P.tam = tam;
    P.topo = -1;
    return P;
}

Pilha inserir(Pilha P, int x){
    if(P.topo == P.tam){
        cout << "Pilha cheia" << endl;
        return P;
    }
    else{
        P.topo++;
        P.V[P.topo] = x;
    }
    return P;
}

Pilha remover(Pilha P){
    if(P.topo == -1){
        cout << "Pilha vazia" << endl;
        return P;
    }
    else{
        P.topo--;
    }
    return P;
}

Pilha imprime(Pilha P){
    for(int i = 0; i <= P.topo; i++){
        cout << P.V[i] << " ";
    }
    cout << endl;
    return P;
}

int main(){
    int tam;
    tam = 5;
    Pilha P = criarPilha(tam);


    P = inserir(P, 1);
    P = inserir(P, 2);
    P = inserir(P, 3);
    P = inserir(P, 4);

    imprime(P);


}

