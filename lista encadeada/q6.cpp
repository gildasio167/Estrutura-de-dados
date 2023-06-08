
#include <iostream>

struct Node {
    int data;
    Node* next;
    
    Node(int value) : data(value), next(nullptr) {}
};

void incluirOrdenado(Node*& head, int x) {
    Node* newNode = new Node(x);
    
    if (head == nullptr || x < head->data) {
        newNode->next = head;
        head = newNode;
    } else {
        Node* current = head;
        
        while (current->next != nullptr && x >= current->next->data) {
            current = current->next;
        }
        
        newNode->next = current->next;
        current->next = newNode;
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
    Node* head = nullptr;
    
    incluirOrdenado(head, 3);
    incluirOrdenado(head, 1);
    incluirOrdenado(head, 5);
    incluirOrdenado(head, 2);
    incluirOrdenado(head, 4);
    
    std::cout << "Lista ordenada: ";
    PrintList(head);
    
    // Libera a memória alocada
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    
    return 0;
}
