#ifndef PILHA_ENCADEADA
#define PILHA_ENCADEADA

using namespace std;

struct NODE{
    int chave;
    struct NODE *prox;
};

typedef struct NODE NO;

struct PilhaEncadeada{
    NO cabeca;
    int card; //Quantidade de elementos na pilha
};

typedef struct PilhaEncadeada pilha_encadeada;

//Criar uma Pilha
pilha_encadeada criarPilhaEncadeada(){
    pilha_encadeada P;
    P.cabeca.prox = NULL;
    P.card = 0;
    return P;
}

//Inserir um elemento na Pilha
pilha_encadeada inserir_na_pilha_encadeada(pilha_encadeada P, int x){
    NO *novo = (NO *) malloc(sizeof(NO));
    novo->chave = x;
    novo->prox = P.cabeca.prox;
    P.cabeca.prox = novo;
    P.card++;
    return P;
}

//Remover um elemento da Pilha
pilha_encadeada remover_da_pilha_encadeada(pilha_encadeada P, int x){
    NO *aux = P.cabeca.prox;
    NO *ant = &P.cabeca;
    while(aux != NULL && aux->chave != x){
        ant = aux;
        aux = aux->prox;
    }
    if(aux == NULL){
        cout << "Elemento nao encontrado" << endl;
        return P;
    }
    ant->prox = aux->prox;
    free(aux);
    P.card--;
    return P;
}

//Buscar um elemento na Pilha
NO *buscar_na_pilha_encadeada(pilha_encadeada P, int x){
    NO *aux = P.cabeca.prox;
    while(aux != NULL && aux->chave != x){
        aux = aux->prox;
    }
    if(aux == NULL){
        cout << "Elemento nao encontrado" << endl;
        return NULL;
    }
    return aux;
}

//Imprimir a Pilha
void imprime_pilha_encadeada(pilha_encadeada P){
    NO *aux = P.cabeca.prox;
    while(aux != NULL){
        cout << aux->chave << " ";
        aux = aux->prox;
    }
    cout << endl;
}


#endif