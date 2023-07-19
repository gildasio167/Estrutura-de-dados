#include <iostream>
#include "Stack.h"
#include <sstream>
using namespace std;

int main() {
    Stack<string> pilha;

    string input, palavra;
    cout << "Digite uma lista de nomes: ";
    getline(cin, input);
    stringstream ss {input};
    while(ss >> palavra) {
        pilha.push(palavra);
    }

    while(!pilha.empty()) {
        cout << pilha.top() << endl;
        pilha.pop();
    }
    cout << "size da pilha: " << pilha.size() << endl;
}