



#include <stdio.h>
#include <stdlib.h>

struct NO {
 int chave;
 struct NO * proximo;
};
typedef struct NO NO;

int main() {
   NO cabeca;
   
   cabeca.chave = 10;
   
   NO *p = (NO*) malloc(sizeof(NO));
   (*p).chave = 5;

   cabeca.proximo = p;  

   return 0;
}


