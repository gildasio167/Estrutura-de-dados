#ifndef FILA_DUPLA_ENCADEADA
#define FILA_DUPLA_ENCADEADA

using namespace std;

struct NODE{
    int chave;
    struct NODE *prox;
    struct NODE *ant;
};

typedef struct NODE NO;

struct FilaDuplaEncadeada{
    NO *cabeca;
    NO *cauda;
    int card; //Quantidade de elementos na fila
};

typedef struct FilaDuplaEncadeada Fila_dupla_encadeada;

//Criar uma Fila
Fila_dupla_encadeada criarFilaDuplaEncadeada(){
    Fila_dupla_encadeada F;
    F.cabeca = NULL;
    F.cauda = NULL;
    F.card = 0;
    return F;
}

//Inserir um elemento na Fila
Fila_dupla_encadeada inserir_na_fila_dupla_encadeada(Fila_dupla_encadeada F, int x){
    NO *novo = (NO *) malloc(sizeof(NO));
    novo->chave = x;
    novo->prox = NULL;
    novo->ant = F.cauda;
    if(F.cabeca == NULL){
        F.cabeca = novo;
        F.cauda = novo;
    }else{
        F.cauda->prox = novo;
        F.cauda = novo;
    }
    F.card++;
    return F;
}

//Remover um elemento da Fila
Fila_dupla_encadeada remover_da_fila_dupla_encadeada(Fila_dupla_encadeada F, int x){
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
    if(aux->prox == NULL){
        F.cauda = ant;
    }
    free(aux);
    F.card--;
    return F;
}

//Buscar um elemento na Fila
NO *buscar_na_fila_dupla_encadeada(Fila_dupla_encadeada F, int x){
    NO *aux = F.cabeca;
    while(aux != NULL && aux->chave != x){
        aux = aux->prox;
    }
    if(aux == NULL){
        cout << "Elemento nao encontrado" << endl;
        return NULL;
    }
    return aux;
}

//Imprimir a Fila
void imprimir_fila_dupla_encadeada(Fila_dupla_encadeada F){
    NO *aux = F.cabeca;
    while(aux != NULL){
        cout << aux->chave << " ";
        aux = aux->prox;
    }
    cout << endl;
}


#endif