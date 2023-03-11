#include <iostream>
using namespace std;

struct No {
    int valor;
    No* esquerda;
    No* direita;
    No(int v) : valor(v), esquerda(nullptr), direita(nullptr) {}
};

bool eh_estritamente_binaria(No* no) {
    if (no == nullptr) {
        return true;
    }
    if (no->esquerda == nullptr && no->direita == nullptr) {
        return true;
    }
    if (no->esquerda != nullptr && no->direita != nullptr) {
        return eh_estritamente_binaria(no->esquerda) && eh_estritamente_binaria(no->direita);
    }
    return false;
}

int main() {
    No* raiz = new No(1);
    raiz->esquerda = new No(2);
    raiz->direita = new No(3);
    raiz->esquerda->esquerda = new No(4);
    raiz->esquerda->direita = new No(5);
    raiz->direita->esquerda = new No(6);

    if (eh_estritamente_binaria(raiz)) {
        cout << "A arvore eh estritamente binaria." << endl;
    } else {
        cout << "A arvore nao eh estritamente binaria." << endl;
    }

    return 0;
}
