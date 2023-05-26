#include <stdio.h>
#include <stdlib.h>

void ler(int** M, int nlin, int ncol) {
    for(int i=0;i<nlin;i++) {
	for(int j=0;j<ncol;j++)
            scanf("%d", &M[i][j]);
    }
}

void imprimir(int** M, int nlin, int ncol) {
    for(int i=0;i<nlin;i++) {
	for(int j=0;j<ncol-1;j++)
            printf("%d ", M[i][j]);
        printf("%d\n", M[i][ncol-1]);
    }
}

int main() {
   int** M=NULL;
   int nlin=0, ncol=0;

   scanf("%d",&nlin);
   scanf("%d",&ncol);

   M = (int**) malloc(nlin*sizeof(int*));
   for(int i=0;i<nlin;i++)
       M[i] = (int*) malloc(ncol*sizeof(int));

   ler(M,nlin,ncol);
   imprimir(M,nlin,ncol);

   for(int i=0;i<nlin;i++) free(M[i]);
   free(M);

   return 0;
}
