#ifndef ARVORE
#define ARVORE

#include <iostream>

using namespace std;

struct NODE {
    int chave;
    struct NODE* pai;
    struct NODE* esq;
    struct NODE* dir;
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

NO* minimo(NO* arv) {
    if(arv == NULL) {
        return NULL;
    }
    if(arv->esq == NULL) {
        return arv;
    }
    else {
        return minimo(arv->esq);
    }
};

NO* maximo(NO* arv) {
    if(arv == NULL) {
        return NULL;
    }
    if(arv->dir == NULL) {
        return arv;
    }
    else {
        return maximo(arv->dir);
    }
};

NO* sucessor(NO* p) {
    if(p->dir != NULL) {
        return minimo(p->dir);
    }
    NO* pai = p->pai;
    while(pai!=NULL && pai->dir == p) {
        p = pai;
        pai = p->pai;
    }
    if(pai == NULL){
        return NULL;
    }
    else{
        return pai;
    }
};

NO* antecessor(NO* p) {
    if(p->esq != NULL) {
        return maximo(p->dir);
    }
    NO* pai = p->pai;
    while(pai!=NULL && pai->esq == p) {
        p = pai;
        pai = p->pai;
    }
    if(pai == NULL) {
        return NULL;
    }
    else {
        return pai;
    }
};


NO* remover(NO* arv, int x) {
    NO* p = buscar(arv, x);
    if(p == NULL) {
        return arv;
    }
    if(p->esq == NULL && p->dir == NULL) {
        if(p->pai == NULL) {
            free(p);
            return NULL;
        }
        if(p->pai->esq == p) {
            p->pai->esq = NULL;
        }
        else {
            p->pai->dir = NULL;
        }
        free(p);
        return arv;
    }
    if(p->esq == NULL || p->dir == NULL) {
        NO* filho;
        if(p->esq == NULL) {
            filho = p->dir;
        }
        else {
            filho = p->esq;
        }
        if(p->pai == NULL) {
            free(p);
            return filho;
        }
        if(p->pai->esq == p) {
            p->pai->esq = filho;
        }
        else {
            p->pai->dir = filho;
        }
        free(p);
        return arv;
    }
    NO* suc = sucessor(p);
    p->chave = suc->chave;
    if(suc->pai->esq == suc) {
        suc->pai->esq = suc->dir;
    }
    else {
        suc->pai->dir = suc->dir;
    }
    if(suc->dir != NULL) {
        suc->dir->pai = suc->pai;
    }
    free(suc);
    return arv;
};

//imprimir em forma de arvore
void imprimir(NO* arv) {
    if(arv == NULL) {
        return;
    }
    cout << arv->chave << endl;
    imprimir(arv->esq);
    imprimir(arv->dir);
};




#endif // ARVORE