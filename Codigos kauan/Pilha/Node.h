#ifndef NODE_H
#define NODE_H

template <typename K>

struct Node {
    K value; // valor a ser guardado, do tipo K
    Node *next; // ponteiro para o próximo elemento da pilha

    // Construtor
    Node(const K &val, Node *nextPtr) {
      value = val;
      next = nextPtr;
    }

    // Destrutor
    ~Node() {
      delete next; // quando um nó é deletado, ele deleta o próximo, delete no seu next 
    }
};

#endif