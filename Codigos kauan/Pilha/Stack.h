#ifndef STACK_H
#define STACK_H
#include "Node.h"
#include <stdexcept>

template <typename K>
class Stack {
private:
    Node<K> *m_top; // ponteiro para o topo da pilha
    int m_size; // número de elementos na pilha
public:
    // Construtor: cria uma pilha vazia
    Stack() {
      m_top = nullptr;
      m_size = 0;
    }
    // Verifica se a pilha está vazia
    bool empty() {
      return m_top == nullptr;
    }
    // Retorna tamanho atual
    int size() {
      return m_size;
    }
    // Retorna o valor do elemento no topo da pilha, se estiver vazia, lance exceção
    K& top() {
      if(m_size == 0) {
        throw std::out_of_range("stack underflow");
      } else {
        return m_top->value;
      }
    }
    // Inserir na pilha
    void push(const K &val) {
      Node<K> *aux = new Node<K>(val, m_top);
      m_top = aux;
      m_size++;
    }
    // Remover o próximo elemento da pilha
    void pop() {
      if(m_size != 0) {
          Node<K> *aux = m_top;
          m_top = m_top->next;
          aux->next = nullptr;
          delete aux;
          m_size--;
      } else {
        throw std::out_of_range("a pilha esta vazia");
      }
    }
    // Destrutor
    ~Stack() {
      delete m_top;
    }
};

#endif