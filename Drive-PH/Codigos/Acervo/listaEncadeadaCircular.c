



#include <stdio.h>
#include <stdlib.h>

struct NODE {
  int chave;
  struct NODE* prox;
};

typedef struct NODE NO;

struct ListaEncadeadaCircular {
  NO cabeca;
  int card;  // Quantidade de elementos na Lista
};
typedef struct ListaEncadeadaCircular ListaEncCircular;

ListaEncCircular criarLista() {
   ListaEncCircular L;
   L.card = 0;
   L.cabeca.prox = &(L.cabeca); 

   return L;
}

NO* buscar(ListaEncCircular L, int x) {
    NO* c = &(L.cabeca);
    NO* p = L.cabeca.prox;

    while(p!=c)
	if(p->chave == x) return p;

    return NULL;
}

int remover(ListaEncCircular L, int x) {
    NO* c = &(L.cabeca);
    NO* p = &(L.cabeca);

    while(p->prox != c)
	if(p->prox->chave == x) {
		NO* r = p->prox;
                p->prox = p->prox->prox;
                free(r);
                return 1;
	} 
        else p = p->prox;

    return 0;
}

ListaEncCircular incluir(ListaEncCircular L, int x) {
   NO* novo = NULL;
   
   novo = (NO*) malloc(sizeof(NO));
   novo->chave = x;
   novo->prox = L.cabeca.prox;
   L.cabeca.prox = novo;
   (L.card)++;
   return L;
}

int main() {
   ListaEncCircular L;

   L = criarLista();
   L = incluir(L,10);
   printf("%d\n", L.cabeca.prox->chave);

   return 0;
}


