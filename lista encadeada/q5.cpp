#include <iostream>

struct Node {
    int data;
    Node* next;
    
    Node(int value) : data(value), next(nullptr) {}
};

void RemoveTodos(Node*& head, int x) {
    Node* current = head;
    Node* previous = nullptr;
    
    while (current != nullptr) {
        if (current->data == x) {
            // Remove o nó atual
            if (previous != nullptr) {
                previous->next = current->next;
            } else {
                head = current->next;
            }
            Node* temp = current;
            current = current->next;
            delete temp;
        } else {
            previous = current;
            current = current->next;
        }
    }
}

void PrintList(Node* head) {
    Node* current = head;
    
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    
    std::cout << std::endl;
}

int main() {
    Node* head = new Node(2);
    head->next = new Node(3);
    head->next->next = new Node(5);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(7);
    head->next->next->next->next->next = new Node(5);
    head->next->next->next->next->next->next = new Node(3);
    head->next->next->next->next->next->next->next = new Node(8);
    
    std::cout << "Lista original: ";
    PrintList(head);
    
    int valor = 3;
    RemoveTodos(head, valor);
    
    std::cout << "Lista após remover todos os elementos com valor " << valor << ": ";
    PrintList(head);
    
    // Libera a memória alocada
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    
    return 0;
}
