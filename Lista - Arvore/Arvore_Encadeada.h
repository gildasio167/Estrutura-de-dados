#ifndef ARVORE_ENCADEADA
#define ARVORE_ENCADEADA


#include <iostream>

using namespace std;

struct NODE {
    int chave;
    struct NODE* pai;
    struct NODE* esq;
    struct NODE* dir;
    int altura;
};

typedef struct NODE NO;

NO* criarBST(){
    return NULL;
};

NO* buscar(NO* arv, int x) {
    if (arv == NULL) {
        return NULL;
    }
    if (arv->chave == x) {
        return arv;
    }
    if (x < arv->chave) {
        return buscar(arv->esq, x);
    }
    else {
        return buscar(arv->dir, x);
    }
};

int Altura(NO* arv){
    if(arv == NULL){
        return 0;
    }
    return arv->altura;
}

void alterarAltura(NO* arv){
    int esqAltura = Altura(arv->esq);
    int dirAltura = Altura(arv->dir);
    arv->altura = 1 + max(esqAltura, dirAltura);
}

NO* inserir_com_altura(NO* arv, int x){
    if (arv == NULL) {
        NO* novo = (NO*) malloc(sizeof(NO));
        novo->chave = x;
        novo->esq = NULL;
        novo->dir = NULL;
        novo->pai = NULL;
        novo->altura = 1;
        return novo;
    }

    if (x < arv->chave){
        arv->esq = inserir_com_altura(arv->esq, x);
        arv->esq->pai = arv;
    }
    else if (x > arv->chave){
        arv->dir = inserir_com_altura(arv->dir, x);
        arv->dir->pai = arv;
    }
    else {
        return arv;
    }

    alterarAltura(arv);

    return arv;
};


NO* inserir(NO* arv, int x){
    NO* r = arv;
    NO* novo = (NO*) malloc(sizeof(NO));
    novo->chave = x;
    novo->esq = NULL;
    novo->dir = NULL;
    novo->pai = NULL;

    if (arv == NULL) {
        return novo;
    }

    NO* pai = arv;
    if(x <= pai->chave) {
        arv = pai->esq;
    }
    else {
        arv = pai->dir;
    }
    while(arv != NULL) {
        pai = arv;
        if(x <= pai->chave) {
            arv = pai->esq;
        }
        else {
            arv = pai->dir;
        }
    }
    novo->pai = pai;
    if(x <= pai->chave) {
        pai->esq = novo;
    }
    else {
        pai->dir = novo;
    }
    return r;
};

int ContarFolhas(NO* arv){
    if(arv == NULL) {
        return 0;
    }
    if(arv->esq == NULL && arv->dir == NULL) {
        return 1;
    }
    return ContarFolhas(arv->esq) + ContarFolhas(arv->dir);
};


//contar nos da arvore que tem pelo menos uma sub arvore vazia
int ContarNos_SubArvoreVazia(NO* arv){
    if(arv == NULL) {
        return 0;
    }

    int result = 0;

    if(arv->esq == NULL || arv->dir == NULL) {
        result = 1;
    }

    result += ContarNos_SubArvoreVazia(arv->esq);
    result += ContarNos_SubArvoreVazia(arv->dir);

    return result;

};

void RemoveTodos(NO* arv, int x){
    NO* no = buscar(arv, x);
    if(no == NULL) {
        return;
    }
    if(no->esq == NULL && no->dir == NULL) {
        if(no->pai == NULL) {
            free(no);
            return;
        }
        if(no->pai->esq == no) {
            no->pai->esq = NULL;
        }
        else {
            no->pai->dir = NULL;
        }
        free(no);
        return;
    }
    if(no->esq == NULL) {
        if(no->pai == NULL) {
            arv = no->dir;
            free(no);
            return;
        }
        if(no->pai->esq == no) {
            no->pai->esq = no->dir;
        }
        else {
            no->pai->dir = no->dir;
        }
        free(no);
        return;
    }
    if(no->dir == NULL) {
        if(no->pai == NULL) {
            arv = no->esq;
            free(no);
            return;
        }
        if(no->pai->esq == no) {
            no->pai->esq = no->esq;
        }
        else {
            no->pai->dir = no->esq;
        }
        free(no);
        return;
    }
    NO* aux = no->esq;
    while(aux->dir != NULL) {
        aux = aux->dir;
    }
    no->chave = aux->chave;
    if(aux->pai->esq == aux) {
        aux->pai->esq = aux->esq;
    }
    else {
        aux->pai->dir = aux->esq;
    }
    free(aux);
    return;
};

NO* minimo(NO* arv){
    if(arv == NULL) {
        return NULL;
    }
    while(arv->esq != NULL) {
        arv = arv->esq;
    }
    return arv;
};

NO* maximo(NO* arv){
    if(arv == NULL) {
        return NULL;
    }
    while(arv->dir != NULL) {
        arv = arv->dir;
    }
    return arv;
};

NO* sucessor(NO* arv){
    if(arv == NULL) {
        return NULL;
    }
    if(arv->dir != NULL) {
        return minimo(arv->dir);
    }
    NO* y = arv->pai;
    while(y != NULL && arv == y->dir) {
        arv = y;
        y = y->pai;
    }
    return y;
};

NO* antecessor(NO* arv){
    if(arv == NULL) {
        return NULL;
    }
    if(arv->esq != NULL) {
        return maximo(arv->esq);
    }
    NO* y = arv->pai;
    while(y != NULL && arv == y->esq) {
        arv = y;
        y = y->pai;
    }
    return y;
};



void imprimir(NO* arv){
    if(arv == NULL) {
        return;
    }
    cout << arv->chave << endl;
    imprimir(arv->esq);
    imprimir(arv->dir);
};

void imprimir_com_altura(NO* arv){
    if(arv == NULL) {
        return;
    }
    cout << arv->chave << " " << arv->altura << endl;
    imprimir_com_altura(arv->esq);
    imprimir_com_altura(arv->dir);
};


void imprimir_interativo(NO* arv){
    NO* aux = minimo(arv);
    while(aux != NULL) {
        cout << aux->chave << endl;
        aux = sucessor(aux);
    }
}


#endif