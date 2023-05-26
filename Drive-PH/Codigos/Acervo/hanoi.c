



#include <stdio.h>
#include <stdlib.h>

int * O, *T, *D;

int HanoiRec(int *T1, int *topo_T1, int *T2, int *topo_T2, int *T3, int *topo_T3, int n) {
  if(n==1) {
    (*topo_T3)++;
    T3[*topo_T3] = T1[*topo_T1];
    (*topo_T1)--;

    char T1_nome[20], T3_nome[20];
    if(T1 == O) sprintf(T1_nome,"Origem");
    if(T1 == T) sprintf(T1_nome,"Trabalho");
    if(T1 == D) sprintf(T1_nome,"Destino");

    if(T3 == O) sprintf(T3_nome,"Origem");
    if(T3 == T) sprintf(T3_nome,"Trabalho");
    if(T3 == D) sprintf(T3_nome,"Destino");
    printf("Move Disco %d da torre %s para a torre %s.\n", T3[*topo_T3], T1_nome, T3_nome);
    return 1;
  } else {
  	return HanoiRec(T1,topo_T1,T3,topo_T3,T2,topo_T2,n-1) +
  	HanoiRec(T1,topo_T1,T2,topo_T2,T3,topo_T3,1) +
  	HanoiRec(T2,topo_T2,T1,topo_T1,T3,topo_T3,n-1);
  }
}

int main() {
   int n, topo_O=-1, topo_T=-1, topo_D = -1;

   printf("Digite o número de discos: ");
   scanf("%d",&n);

   O= (int *) malloc(n*sizeof(int));
   T= (int *) malloc(n*sizeof(int));
   D= (int *) malloc(n*sizeof(int));

   for(int i=0;i<n;i++) O[i]=n-i;
   topo_O = n-1;

   int nMove = HanoiRec(O,&topo_O,T,&topo_T,D,&topo_D,n);
   printf("Número de Movimentos = %d.\n",nMove);

   free(O);
   free(T);
   free(D);

   return 0;
}


