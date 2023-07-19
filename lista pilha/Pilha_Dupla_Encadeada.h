#ifndef PILHA_DUPLA_ENCADEADA
#define PILHA_DUPLA_ENCADEADA

using namespace std;

struct NODE{
    int chave;
    struct NODE *prox;
    struct NODE *ant;
};

typedef struct NODE NO;

struct PilhaDuplaEncadeada{
    NO *cabeca;
    NO *cauda;
    int card; //Quantidade de elementos na pilha
};

typedef struct PilhaDuplaEncadeada Pilha_dupla_encadeada;

//Criar uma Pilha
Pilha_dupla_encadeada criarPilhaDuplaEncadeada(){
    Pilha_dupla_encadeada P;
    P.cabeca = NULL;
    P.cauda = NULL;
    P.card = 0;
    return P;
}

//Inserir um elemento na Pilha
Pilha_dupla_encadeada inserir_na_pilha_dupla_encadeada(Pilha_dupla_encadeada P, int x){
    NO *novo = (NO *) malloc(sizeof(NO));
    novo->chave = x;
    novo->prox = NULL;
    novo->ant = P.cauda;
    if(P.cabeca == NULL){
        P.cabeca = novo;
        P.cauda = novo;
    }else{
        P.cauda->prox = novo;
        P.cauda = novo;
    }
    P.card++;
    return P;
}

//Remover um elemento da Pilha
Pilha_dupla_encadeada remover_da_pilha_dupla_encadeada(Pilha_dupla_encadeada P, int x){
    NO *aux = P.cabeca;
    NO *ant = NULL;
    while(aux != NULL && aux->chave != x){
        ant = aux;
        aux = aux->prox;
    }
    if(aux == NULL){
        cout << "Elemento nao encontrado" << endl;
        return P;
    }
    if(ant == NULL){
        P.cabeca = aux->prox;
    }else{
        ant->prox = aux->prox;
    }
    if(aux->prox == NULL){
        P.cauda = aux->ant;
    }else{
        aux->prox->ant = aux->ant;
    }
    free(aux);
    P.card--;
    return P;
}

//Buscar um elemento na Pilha
NO *buscar_na_pilha_dupla_encadeada(Pilha_dupla_encadeada P, int x){
    NO *aux = P.cabeca;
    while(aux != NULL && aux->chave != x){
        aux = aux->prox;
    }
    return aux;
}

//Imprimir a Pilha
void imprimir_pilha_dupla_encadeada(Pilha_dupla_encadeada P){
    NO *aux = P.cabeca;
    while(aux != NULL){
        cout << aux->chave << " ";
        aux = aux->prox;
    }
    cout << endl;
}

#endif