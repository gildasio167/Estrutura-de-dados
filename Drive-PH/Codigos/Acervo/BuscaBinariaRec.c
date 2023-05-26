




#include <stdio.h>
#include <stdlib.h>

int BuscaBinariaRec(int *S, int p, int r, int x) {
   int q = (p+r-1)/2;

   if(S[q] == x) return q;
   if(p >= r-1) return -1; // Caso Base
   if(x < S[q]) BuscaBinariaRec(S,p,q-1,x);
   else BuscaBinariaRec(S,q+1,r,x); 
}

int main() {
   int n,x=0,pos;
   int *S=NULL;

   printf("Digite o tamanho do vetor: ");
   scanf("%d",&n);

   S = (int*) malloc(n*sizeof(int));
   for(int i=0;i<n;i++) S[i] = i;

   printf("Digite o elemento a ser pesquisado: ");
   scanf("%d",&x);
   pos = BuscaBinariaRec(S,0,n,x);
   if(pos != -1) printf("Valor encontrado na posição %d\n", pos);
   else printf("Valor NÃO encontrado!\n");

   free(S);

   return 0;
}


