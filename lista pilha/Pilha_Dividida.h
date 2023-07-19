#ifndef PILHA_DIVIDIDA
#define PILHA_DIVIDIDA

using namespace std;

struct Pilha_Dividida{
    int *V;
    int tam;
    int topo1;
    int topo2;
};

typedef struct Pilha_Dividida Pilha_dividida;

//Criar uma Pilha
Pilha_dividida criarPilhaDividida(int tam){
    Pilha_dividida P;
    P.V = (int *) malloc(tam * sizeof(int));
    P.tam = tam;
    P.topo1 = -1;
    P.topo2 = tam;
    return P;
}

//Inserir um elemento na Pilha
Pilha_dividida inserir_na_pilha_dividida(Pilha_dividida P, int x, int pilha){
    if(P.topo1 == P.topo2){
        cout << "Pilha cheia" << endl;
        return P;
    }
    else{
        if(pilha == 1){
            P.topo1++;
            P.V[P.topo1] = x;
        }
        else{
            P.topo2--;
            P.V[P.topo2] = x;
        }
    }
    return P;
}

//Remover um elemento da Pilha
Pilha_dividida remover_da_pilha_dividida(Pilha_dividida P, int x, int pilha){
    if(pilha == 1){
        if(P.topo1 == -1){
            cout << "Pilha vazia" << endl;
            return P;
        }
        else{
            x = P.V[P.topo1];
            P.topo1--;
        }
    }
    else{
        if(P.topo2 == P.tam){
            cout << "Pilha vazia" << endl;
            return P;
        }
        else{
            x = P.V[P.topo2];
            P.topo2++;
        }
    }
    return P;
}

//Busca um elemento na Pilha
int busca_na_pilha_dividida(Pilha_dividida P, int x){
    int i;
    for(i = 0; i <= P.topo1; i++){
        if(P.V[i] == x){
            return i;
        }
    }
    for(i = P.tam - 1; i >= P.topo2; i--){
        if(P.V[i] == x){
            return i;
        }
    }
    return -1;
}

//impimir pilha
void imprimir_pilha_dividida(Pilha_dividida P){
    int i;
    cout << "Pilha 1: ";
    for(i = 0; i <= P.topo1; i++){
        cout << P.V[i] << " ";
    }
    cout << endl;
    cout << "Pilha 2: ";
    for(i = P.tam - 1; i >= P.topo2; i--){
        cout << P.V[i] << " ";
    }
    cout << endl;
}


#endif