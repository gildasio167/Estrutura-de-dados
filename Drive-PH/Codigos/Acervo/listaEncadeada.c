



#include <stdio.h>
#include <stdlib.h>

struct NODE {
  int chave;
  struct NODE* prox;
};

typedef struct NODE NO;

struct ListaEncadeada {
  NO cabeca;
  int card;  // Quantidade de elementos na Lista
};
typedef struct ListaEncadeada ListaEnc;

ListaEnc criarLista() {
   ListaEnc L;
   L.card = 0;
   L.cabeca.prox = NULL;  

   return L;
}

NO* buscar(ListaEnc L, int x) {
    NO* p = L.cabeca.prox;

    while(p!=NULL)
	if(p->chave == x) return p;

    return NULL;
}

int remover(ListaEnc L, int x) {
    NO* p = &(L.cabeca);

    while(p->prox != NULL)
	if(p->prox->chave == x) {
		NO* r = p->prox;
                p->prox = p->prox->prox;
                free(r);
                return 1;
	} 
        else p = p->prox;

    return 0;
}

ListaEnc incluir(ListaEnc L, int x) {
   NO* novo = NULL;
   
   novo = (NO*) malloc(sizeof(NO));
   novo->chave = x;
   novo->prox = L.cabeca.prox;
   L.cabeca.prox = novo;
   (L.card)++;
   return L;
}

int main() {
   ListaEnc L;

   L = criarLista();
   L = incluir(L,10);
   printf("%d\n", L.cabeca.prox->chave);

   return 0;
}


