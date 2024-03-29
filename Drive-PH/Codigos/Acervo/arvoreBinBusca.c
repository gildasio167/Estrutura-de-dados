



#include <stdio.h>
#include <stdlib.h>

struct NODE {
  int chave;
  struct NODE* pai;
  struct NODE* esq;
  struct NODE* dir;
};
typedef struct NODE NO;

NO* criarBST() {
   return NULL;
}

NO* buscar(NO* arv, int x) {
    if(arv == NULL) return NULL;
    if(arv->chave == x) return arv;
    if(x <= arv->chave) return buscar(arv->esq,x);
    else return buscar(arv->dir,x); 
}

NO* incluir(NO* arv, int x) {
    NO* r = arv;
    NO* novo = (NO*) malloc(sizeof(NO));
    novo->chave = x;
    novo->esq = NULL;
    novo->dir = NULL;
    novo->pai = NULL;
    if(arv == NULL) return novo;   // Árvore estava vazia
    
    NO* pai = arv;
    if(x <= pai->chave) arv = pai->esq;
    else arv = pai->dir;
    while(arv != NULL) {
	pai = arv;
	if(x <= arv->chave) arv = pai->esq;
        else arv = pai->dir;
    }
    novo->pai = pai;
    if(x <= pai->chave) pai->esq = novo;
    else pai->dir = novo;
    return r;
}

NO* minimo(NO* arv) {
	if(arv == NULL) return NULL;
	if(arv->esq == NULL) return arv;
	else minimo(arv->esq); 
}

NO* maximo(NO* arv) {
	if(arv == NULL) return NULL;
	if(arv->dir == NULL) return arv;
	else maximo(arv->dir); 
}

NO* sucessor(NO* p) {
	if(p->dir != NULL) return minimo(p->dir);
	NO* pai = p->pai;
	while(pai!=NULL && pai->dir == p) {
		p = pai;
		pai = p->pai;		
	}
	if(pai == NULL) return NULL;
	else return pai;
}

NO* antecessor(NO* p) {
	if(p->esq != NULL) return maximo(p->dir);
	NO* pai = p->pai;
	while(pai!=NULL && pai->esq == p) {
		p = pai;
		pai = p->pai;		
	}
	if(pai == NULL) return NULL;
	else return pai;
}

int main() {
   NO* arv;

   arv = criarBST();
   arv = incluir(arv,10);
   printf("%d\n",arv->chave);

   return 0;
}


