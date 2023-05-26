



#include <stdio.h>
#include <stdlib.h>

void imprimeVetor(int *S, int p, int r) {
   for(int i=p;i<r;i++) printf("%d ",S[i]);
   printf("\n");
}

void bubbleSortRec(int *S, int p, int r) {
    if(p==r-1) return; // CASO BASE

    int m=p;
    for(int i=p+1;i<r;i++)
       if(S[i] > S[m]) m=i;

    int aux=S[m];
    S[m]=S[r-1];
    S[r-1]=aux;

    r--;
    bubbleSortRec(S,p,r);
}

void bubbleSort(int *S, int p, int r) {
   int n=r,trocado=0;  // trocado = FALSE

   do {
      trocado=0;  // trocado = FALSE
      for(int i=p;i<r-1;i++)
	if(S[i] > S[i+1]) {
   	   int aux=S[i];
           S[i]=S[i+1];
           S[i+1]=aux;
	   trocado=1;  // trocado = TRUE
	}
      r--;
      imprimeVetor(S,0,n);
   } while(trocado);
}

int main() {
   int n=0;
   int *S=NULL;

   printf("Digite o tamanho do vetor: ");
   scanf("%d",&n);

   S = (int*) malloc(n*sizeof(int));
   for(int i=0;i<n;i++) S[i] = i+1;

   imprimeVetor(S,0,n);
   bubbleSort(S,0,n);
   //imprimeVetor(S,0,n);

   free(S);  

   return 0;
}


