#ifndef PILHA
#define PILHA

using namespace std;

struct Pilha{
    int *V;
    int tam;
    int topo;
};

typedef struct Pilha pilha;

//Criar uma Pilha
Pilha criarPilha(int tam){
    Pilha P;
    P.V = (int *) malloc(tam * sizeof(int));
    P.tam = tam;
    P.topo = -1;
    return P;
}

//Inserir um elemento na Pilha
Pilha inserir_na_pilha(Pilha P, int x){
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

//Remover um elemento da Pilha
Pilha remover_da_pilha(Pilha P, int x){
    if(P.topo == -1){
        cout << "Pilha vazia" << endl;
        return P;
    }
    else{
        x = P.V[P.topo];
        P.topo--;
    }

    return P;
}    

//Busca um elemento na Pilha
int busca_na_pilha(Pilha P, int x){
    for(int i = 0; i <= P.topo; i++){
        if(P.V[i] == x){
            return i;
        }
    }
    return;
}

//Remove elementos repetidos na Pilha
Pilha RemoveRepetidos_pilha(Pilha P){
    Pilha aux = criarPilha(P.tam);
    int x;
    while(P.topo != -1){
        x = P.V[P.topo];
        P = remover_da_pilha(P, x);
        if(x != P.V[P.topo]){
            aux = inserir_na_pilha(aux, x);
        }
    }
    while(aux.topo != -1){
        x = aux.V[aux.topo];
        aux = remover_da_pilha(aux, x);
        P = inserir_na_pilha(P, x);
    }
    return P;
}

//Imprime a Pilha
Pilha imprime_pilha(Pilha P){
    for(int i = 0; i <= P.topo; i++){
        cout << P.V[i] << " ";
    }
    cout << endl;
    return P;
}


#endif