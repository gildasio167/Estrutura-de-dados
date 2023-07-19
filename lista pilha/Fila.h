#ifdef FILA
#define FILA

using namespace std;

struct Fila{
    int *V;
    int tam;  // tamanho total da fila
    int card;
    int i;  // indice do primeiro elemento
    int f;  // indice do ultimo elemento
};

typedef struct Fila fila;

//Criar uma Fila
Fila criarFila(int tam){
    Fila F;
    F.V = (int *) malloc(tam * sizeof(int));
    F.tam = tam;
    F.card = 0;
    F.i = 0;
    F.f = -1;
    return F;
}

//Inserir um elemento na Fila
Fila inserir_na_fila(Fila F, int x){
    if(F.card == F.tam){
        cout << "Fila cheia" << endl;
        return F;
    }
    else{
        F.card++;
        F.f = (F.f + 1) % F.tam;
        F.V[F.f] = x;
    }
    return F;
}


Fila remover_fila(Fila F, int *x){
    if(F.card == 0){
        cout << "Fila vazia" << endl;
        return F;
    }
    else{
        *x = F.V[F.i];
        F.i = (F.i + 1) % F.tam;
        F.card--;
    }
    return F;
}

Fila RemoveRepetidos_fila(Fila F){
    Fila aux = criarFila(F.tam);
    int x;
    while(F.card != 0){
        x = F.V[F.i];
        F = remover_fila(F, &x);
        if(x != F.V[F.i]){
            aux = inserir_na_fila(aux, x);
        }
    }
    while(aux.card != 0){
        x = aux.V[aux.i];
        aux = remover_fila(aux, &x);
        F = inserir_na_fila(F, x);
    }
    return F;
}


#endif