#include <iostream>
using namespace std;

struct No {
    int valor;
    No* esquerda;
    No* direita;
    No(int v) : valor(v), esquerda(nullptr), direita(nullptr) {}
};

bool sao_iguais(No* a, No* b) {
    if (a == nullptr && b == nullptr) {
        return true;
    }
    if (a != nullptr && b != nullptr) {
        return a->valor == b->valor &&
               sao_iguais(a->esquerda, b->esquerda) &&
               sao_iguais(a->direita, b->direita);
    }
    return false;
}

int main() {
    // cria duas árvores de exemplo
    No* a = new No(1);
    a->esquerda = new No(2);
    a->direita = new No(3);
    a->esquerda->esquerda = new No(4);
    a->esquerda->direita = new No(5);
    a->direita->esquerda = new No(6);

    No* b = new No(1);
    b->esquerda = new No(2);
    b->direita = new No(3);
    b->esquerda->esquerda = new No(4);
    b->esquerda->direita = new No(5);
    b->direita->esquerda = new No(6);

    // verifica se as árvores são iguais
    if (sao_iguais(a, b)) {
        cout << "As arvores sao iguais." << endl;
    } else {
        cout << "As arvores nao sao iguais." << endl;
    }

    return 0;
}
