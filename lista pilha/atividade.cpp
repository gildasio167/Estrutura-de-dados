#include <iostream>
#include "Pilha.h"
#include "Fila.h"
#include "Pilha_Encadeada.h"
#include "Fila_Encadeada.h"
#include "Pilha_Dupla_Encadeada.h"
#include "Fila_Dupla_Encadeada.h"

using namespace std;


int main(){
    int tam;
    tam = 5;
    Pilha P = criarPilha(tam);


    P = inserir_na_pilha(P, 1);
    P = inserir_na_pilha(P, 2);
    P = inserir_na_pilha(P, 3);
    P = inserir_na_pilha(P, 4);

    imprime_pilha(P);

    cout << endl;

    


}

