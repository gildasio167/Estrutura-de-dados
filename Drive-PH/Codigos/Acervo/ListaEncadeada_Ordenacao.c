



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

void listar(ListaEnc L) {
   NO* p = L.cabeca.prox;
   while(p != NULL) {
	printf("%d ", p->chave);
        p = p->prox;
   }
   printf("\n");
}

void incluir(ListaEnc *L, int x) {
   NO* novo = NULL;
   
   novo = (NO*) malloc(sizeof(NO));
   novo->chave = x;
   novo->prox = L->cabeca.prox;
   L->cabeca.prox = novo;
   (L->card)++;
}

void incluirOrdenado(ListaEnc *L, int x) {
  NO* p = &(L->cabeca);
  while(p->prox != NULL && p->prox->chave < x) {
	p = p->prox;
  }
  NO* novo = (NO*) malloc(sizeof(NO));
  novo->chave = x;
  novo->prox = p->prox;
  p->prox = novo;
  (L->card)++;
}

ListaEnc copiaOrdenado(ListaEnc L1) {
   ListaEnc L2 = criarLista();

   NO* p = L1.cabeca.prox;
   while(p != NULL) {
	incluirOrdenado(&L2,p->chave);
        p = p->prox;
   }
   return L2;
}

int main() {
   ListaEnc L1, L2;

   L1 = criarLista();
   incluir(&L1,10);
   incluir(&L1,30);
   incluir(&L1,40);
   incluir(&L1,20);
   incluir(&L1,50);
   listar(L1);

   L2 = copiaOrdenado(L1);
   listar(L2);

   return 0;
}


