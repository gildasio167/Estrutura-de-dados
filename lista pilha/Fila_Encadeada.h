#ifndef FILA_ENCADEADA
#define FILA_ENCADEADA

using namespace std;

struct NODE{
    int chave;
    struct NODE *prox;
};

typedef struct NODE NO;

struct FilaEncadeada{
    NO *cabeca;
    NO *ult;
    int card; //Quantidade de elementos na fila
};

typedef struct FilaEncadeada Fila_encadeada;

//Criar uma Fila
Fila_encadeada criarFilaEncadeada(){
    Fila_encadeada F;
    F.cabeca = NULL;
    F.ult = NULL;
    F.card = 0;
    return F;
}

//Inserir um elemento na Fila
Fila_encadeada inserir_na_fila_encadeada(Fila_encadeada F, int x){
    NO *novo = (NO *) malloc(sizeof(NO));
    novo->chave = x;
    novo->prox = NULL;
    if(F.cabeca == NULL){
        F.cabeca = novo;
        F.ult = novo;
    }else{
        F.ult->prox = novo;
        F.ult = novo;
    }
    F.card++;
    return F;
}

//Remover um elemento da Fila
Fila_encadeada remover_da_fila_encadeada(Fila_encadeada F, int x){
    NO *aux = F.cabeca;
    NO *ant = NULL;
    while(aux != NULL && aux->chave != x){
        ant = aux;
        aux = aux->prox;
    }
    if(aux == NULL){
        cout << "Elemento nao encontrado" << endl;
        return F;
    }
    if(ant == NULL){
        F.cabeca = aux->prox;
    }else{
        ant->prox = aux->prox;
    }
    if(aux == F.ult){
        F.ult = ant;
    }
    free(aux);
    F.card--;
    return F;
}

//Buscar um elemento na Fila
NO *buscar_na_fila_encadeada(Fila_encadeada F, int x){
    NO *aux = F.cabeca;
    while(aux != NULL && aux->chave != x){
        aux = aux->prox;
    }
    return aux;
}

//Imprimir a Fila
void imprimir_fila_encadeada(Fila_encadeada F){
    NO *aux = F.cabeca;
    while(aux != NULL){
        cout << aux->chave << " ";
        aux = aux->prox;
    }
    cout << endl;
}

#endif