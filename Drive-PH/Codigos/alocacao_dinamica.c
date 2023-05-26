#include <stdio.h>
#include <stdlib.h>

int main() {
   int n=10;
   // int V[n]; (isto não é muito seguro)
   int* V = (int *) malloc(n*sizeof(int)); // malloc = reserva espaço de memória

   V[0] = 1;
   V[2] = 3;
   printf("%d\n", V[0]);

   int naux = n;
   n=20;
   int* Vaux = V;
   V = (int *) malloc(n*sizeof(int));

   for(int i=0;i<naux;i++) V[i] = Vaux[i];

   free(Vaux);  // Libera memória alocada que está sendo apontada pelo ponteiro V
   Vaux = NULL; // Boa prática de programação: depois de desalocar, fazer ponteiro apontar para nulo

   return 0;
}
