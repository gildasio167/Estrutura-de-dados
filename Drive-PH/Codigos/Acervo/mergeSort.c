



#include <stdio.h>
#include <stdlib.h>

void imprimeVetor(int *S, int p, int r) {
   for(int i=p;i<r;i++) printf("%d ",S[i]);
   printf("\n");
}

void merge(int *S, int p, int q, int r) {
   int *L= (int*) malloc((q-p+2)*sizeof(int));
   int *R= (int*) malloc((r-q+1)*sizeof(int));

   int j=0;
   for(int i=p;i<=q;i++) {
	L[j] = S[i];
        j++;
   }
   L[j] = 1000000;  // Infinito
   int k=0;
   for(int i=q+1;i<=r;i++) {
	R[k] = S[i];
	k++;
   }
   R[k] = 1000000;  // Infinito

   j=0; k=0;
   for(int i=p;i<=r;i++) {
	if(L[j] < R[k]) {
		S[i] = L[j];
		j++;
	} else {
		S[i] = R[k];
		k++;
	}
   }
}

void mergeSort(int *S, int p, int r) {
   if(p>=r) return;

   int q=(r+p)/2;	
   mergeSort(S,p,q);
   mergeSort(S,q+1,r);
   merge(S,p,q,r); 
}

int main() {
   int n=0;
   int *S=NULL;

   printf("Digite o tamanho do vetor: ");
   scanf("%d",&n);

   S = (int*) malloc(n*sizeof(int));
   for(int i=0;i<n;i++) S[i] = n-i+1;

   imprimeVetor(S,0,n);
   mergeSort(S,0,n-1);
   imprimeVetor(S,0,n);

   free(S);  

   return 0;
}


