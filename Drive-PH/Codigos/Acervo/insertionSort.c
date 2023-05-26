



#include <stdio.h>
#include <stdlib.h>

void imprimeVetor(int *S, int p, int r) {
   for(int i=p;i<r;i++) printf("%d ",S[i]);
   printf("\n");
}

void insertionSort(int *S, int n) {
   int aux=0;

   for(int i=1;i<n;i++) {
	int j=i;
	while(S[j-1] > S[j] && j>0) {
		aux = S[j-1];
		S[j-1] = S[j];
		S[j] = aux;
		j--;
		imprimeVetor(S,0,n);
	}
   }  
}

int main() {
   int n=0;
   int *S=NULL;

   printf("Digite o tamanho do vetor: ");
   scanf("%d",&n);

   S = (int*) malloc(n*sizeof(int));
   for(int i=0;i<n;i++) S[i] = n-i+1;

   imprimeVetor(S,0,n);
   insertionSort(S,n);

   free(S);  

   return 0;
}


