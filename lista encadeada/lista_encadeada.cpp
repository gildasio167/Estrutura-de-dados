#include<iostream>

using namespace std;

typedef struct NO_ {
	int chave;
	struct NO_* prox;
} NO;

NO* criarLista() {
	NO* v = (NO*) malloc(sizeof(NO));
	v->prox = NULL;
	return v;
}

void inserir(NO* L, int x) {
	NO* v = (NO*) malloc(sizeof(NO));
	v->chave = x;
	v->prox = L->prox;
	L->prox = v;
}

void imprimir(NO* L_) {
	L_= L_->prox;
	while(L_ != NULL) {
		cout << L_->chave << " ";
		L_= L_->prox;
	}
	cout << "\n";
}

NO* busca(NO* L_, int x) {
	L_ = L_->prox;
	while(L_!=NULL && L_->chave != x) L_= L_->prox;
	if(L_ == NULL) cout << "Elemento não encontrado!\n";
	return L_;
}

NO* buscaRemocao(NO* L_, int x) {
	while(L_->prox!=NULL && L_->prox->chave != x) L_= L_->prox;
	return L_;
}

void remover(NO* L_, int x) {
	NO* p = buscaRemocao(L_,x);
	if(p->prox == NULL) cout << "Elemento não encontrado!\n";
	else {
            NO* p_aux = p->prox;
	    p->prox = p->prox->prox;
	    free(p_aux);
	}
	
}

int main() {
	NO* L=NULL;

	L = criarLista();
        if(L->prox == NULL) cout << "Lista vazia!\n";
	inserir(L,5);
	inserir(L,7);
	inserir(L,10);
	imprimir(L);
	
	return 0; 
}
