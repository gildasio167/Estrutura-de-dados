



#include <stdio.h>
#include <stdlib.h>

struct Pilha {
  int *V;
  int tam;    // tamanho: tamanho máximo da lista
  int topo;   // índice do último elemento 
};

typedef struct Pilha Pilha;

Pilha criarPilha(int tam) {
   Pilha P;
   P.V = (int *) malloc(tam*sizeof(int));
   P.tam = tam;
   P.topo = -1;
   return P;
}

Pilha inserir(Pilha P, int x) {
   if(P.topo + 1 == P.tam) printf("A pilha está cheia!\n");
   else {
  	P.topo = P.topo + 1;
   	P.V[P.topo] = x;
   }
   return P;
}

Pilha remover(Pilha P) {
   if(P.topo == -1) printf("A pilha está vazia!\n"); 
   else P.topo = P.topo - 1;
   
   return P;
}

int main() {
   int tam=0, x=0;
   Pilha P;   

   printf("Digite o tamanho da lista: ");
   scanf("%d", &tam);
   P = criarPilha(tam);
   P = inserir(P,1);
   P = inserir(P,2);
   P = inserir(P,3);

   for(int i=0;i<3;i++) printf("%d,",P.V[i]);



   //for(int i=0;i<tam;i++) L = incluir(L,i+1);
   
   //printf("Digite o elemento a ser removido na lista: ");
   //scanf("%d", &x);

   return 0;
}


