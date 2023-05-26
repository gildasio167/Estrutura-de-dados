



#include <stdio.h>
#include <stdlib.h>

struct NODE {
  int chave;
  struct NODE* prox;
  struct NODE* ant;
};

typedef struct NODE NO;

struct ListaDuplaEncadeada {
  NO cabeca;
  int card;  // Quantidade de elementos na Lista
};
typedef struct ListaDuplaEncadeada ListaDuplaEnc;

ListaDuplaEnc criarLista() {
   ListaDuplaEnc L;
   L.card = 0;
   L.cabeca.prox = NULL;  
   L.cabeca.ant = NULL;
   return L;
}

NO* buscar(ListaDuplaEnc L, int x) {
    NO* p = L.cabeca.prox;

    while(p!=NULL)
	if(p->chave == x) return p;

    return NULL;
}

int remover(ListaDuplaEnc L, int x) {
    NO* p = NULL;

    p = buscar(L,x);
    if(p == NULL) return 0;
    else {
	p->ant->prox = p->prox;
        p->prox->ant = p->ant;
        free(p);
        return 1;
    }

    return 0;
}

ListaDuplaEnc incluir(ListaDuplaEnc L, int x) {
   NO* novo = NULL;
   
   novo = (NO*) malloc(sizeof(NO));
   novo->chave = x;
   novo->prox = L.cabeca.prox;
   L.cabeca.prox = novo;
   (L.card)++;
   return L;
}

int main() {
   ListaDuplaEnc L;

   L = criarLista();
   L = incluir(L,10);
   printf("%d\n", L.cabeca.prox->chave);

   return 0;
}


