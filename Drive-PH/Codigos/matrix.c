#include <stdio.h>
#include <stdlib.h>

int main() {
   int M[5][5];
   nlin = ncol = 5;

   M[0][2] = 10;
   for(int i=0;i<nlin;i++) {
	for(int j=0;j<ncol;j++)
		printf("%d ", M[i][j]);
        printf("\n");
   }

   return 0;
}
