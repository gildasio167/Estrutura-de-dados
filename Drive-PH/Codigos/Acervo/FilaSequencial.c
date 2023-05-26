



#include <stdio.h>
#include <stdlib.h>

struct Fila {
  int *V;
  int tam;    // tamanho: tamanho máximo da Fila
  int card;
  int i;    // índice do primeiro elemento
  int f;   // índice do último elemento 
};

typedef struct Fila Fila;

Fila criarFila(int tam) {
   Fila F;
   F.V = (int *) malloc(tam*sizeof(int));
   F.card = 0;
   F.tam = tam;
   F.i = 0;
   F.f = -1;
   return F;
}

Fila inserir(Fila F, int x) {
   if(F.card == F.tam) printf("Fila CHEIA!\n");
   else {
	F.f = (F.f+1) % F.tam;
        F.V[F.f] = x;
        F.card = F.card+1;
   }
   return F;
}

int buscar(Fila F, int x) {
    if(F.card == 0) printf("Fila VAZIA!\n");
    else {
	for(int j=F.i; j!=F.f; j=(j+1)%F.tam) {
		if(F.V[j]==x) return j;
	}
        if(F.V[F.f]==x) return F.f;
    }
    return -1;
}

Fila remover(Fila F, int *x) {
    if(F.card == 0) printf("Fila VAZIA!\n");
    else {
         *x = F.V[F.i];
         F.i = (F.i+1) % F.tam;
         F.card = F.card - 1;
         return F;
    }
    return F;
}

int main() {
   int tam=0, x=0;
   Fila F;   

   printf("Digite o tamanho da lista: ");
   scanf("%d", &tam);
   F = criarFila(tam);
   F = inserir(P,1);
   F = inserir(P,2);
   F = inserir(P,3);
   F = remover(F,&x);
   printf("Elemento removido = %d\n",x);

   for(int i=0;i<3;i++) printf("%d,",F.V[i]);



   //for(int i=0;i<tam;i++) L = incluir(L,i+1);
   
   //printf("Digite o elemento a ser removido na lista: ");
   //scanf("%d", &x);

   return 0;
}


