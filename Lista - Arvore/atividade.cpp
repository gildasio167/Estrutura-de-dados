#include <iostream>
//#include "arvore.h"
#include "Arvore_Encadeada.h"

int main(){

    NO* arv;

    arv = criarBST();
    // arv = inserir(arv,10);
    // arv = inserir(arv,5);
    // arv = inserir(arv,15);
    // arv = inserir(arv,3);
    // arv = inserir(arv,7);
    // arv = inserir(arv,12);

    arv = inserir_com_altura(arv,10);
    arv = inserir_com_altura(arv,5);
    arv = inserir_com_altura(arv,15);
    arv = inserir_com_altura(arv,3);
    arv = inserir_com_altura(arv,7);
    arv = inserir_com_altura(arv,12);


    int Quant_Folhas = ContarFolhas(arv);
    cout << "Quantidade de folhas: " << Quant_Folhas << endl;

    int Quant_Nos = ContarNos_SubArvoreVazia(arv);
    cout << "Quantidade de nos com pelo menos uma subarvore vazia: " << Quant_Nos << endl;

    imprimir_com_altura(arv);
    cout << "===============" << endl;

    RemoveTodos(arv, 3);
    imprimir(arv);
    cout << "===============" << endl;
    //imprimir_interativo_pilha(arv);

    imprimir_interativo(arv);


    return 0;
    
}