



#include <stdio.h>
#include <stdlib.h>

void imprimeVetor(int *S, int p, int r) {
   for(int i=p;i<r;i++) printf("%d ",S[i]);
   printf("\n");
}

void troca(int *a, int *b) {
 int aux=*a;
 *a=*b;
 *b=aux;
}

int partition(int *S, int p, int r) {
    int pivo = S[p], j = p+1, k = r;
    
    while(j<=k) {
       while(j <= r && S[j] <= pivo) j++;
       while(S[k] > pivo) k--;
       if(j < k) troca(&S[j],&S[k]);
    }
    S[p] = S[k];
    S[k] = pivo;
    return k;
}

void quickSort(int *S, int p, int r) {
   int q=0;

   if(p<r) {
 	q = partition(S,p,r);
        quickSort(S,p,q-1);
	quickSort(S,q+1,r);
   }  
}

int main() {
   int n=0;
   int *S=NULL;

   printf("Digite o tamanho do vetor: ");
   scanf("%d",&n);

   S = (int*) malloc(n*sizeof(int));
   for(int i=0;i<n;i++) S[i] = n-i;

   imprimeVetor(S,0,n);
   quickSort(S,0,n-1);
   imprimeVetor(S,0,n);

   free(S);  

   return 0;
}


