



#include <stdio.h>
#include <stdlib.h>

int *fibVetor;

int FIB(int n) {
  if(n==0) {
    fibVetor[0] = 0;
    return fibVetor[0];
  }
  if(n==1) {
    fibVetor[1] = 1;
    return fibVetor[1];
  }

  if(fibVetor[n-1] == -1) fibVetor[n-1] = FIB(n-1);
  if(fibVetor[n-2] == -1) fibVetor[n-2] = FIB(n-2); 
  return fibVetor[n-1] + fibVetor[n-2];
}

int FIB_iter(int n) {
  int resultado = 0;
  int *fibVetor = (int *) malloc((n+1)*sizeof(int));

  fibVetor[0] = 0;
  fibVetor[1] = 1;

  for(int i=2;i<=n;i++)
	fibVetor[i] = fibVetor[i-1] + fibVetor[i-2];

  resultado = fibVetor[n];
  free(fibVetor);
  return resultado;
}

int main() {
   int n=0;

   printf("Digite o valor de n: ");
   scanf("%d", &n);
   fibVetor = (int *) malloc((n+1)*sizeof(int));
   for(int i=0;i<=n;i++) fibVetor[i] = -1;
 
   printf("FIB(n)=%d\n", FIB(n));
   //printf("FIB_iter(n)=%d\n", FIB_iter(n));  

   return 0;
}


