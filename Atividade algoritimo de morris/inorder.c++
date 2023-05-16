#include <iostream>
#include <stack>

template <typename T>
struct ArvoreNo {
    T valor;
    ArvoreNo<T>* esquerda;
    ArvoreNo<T>* direita;

    ArvoreNo(T valor) : valor(valor), esquerda(nullptr), direita(nullptr) {}
};

template <typename T>
void visit(ArvoreNo<T>* no) {
    std::cout << no->valor << " ";
}

template <typename T>
void MorrisInorder(ArvoreNo<T>* root) {
    ArvoreNo<T>* p = root;
    while (p != nullptr) {
        if (p->esquerda == nullptr) {
            // Nenhum filho esquerdo, visita o nó atual
            visit(p);
            p = p->direita;
        } else {
            // Encontra o predecessor do nó atual na subárvore esquerda
            ArvoreNo<T>* pred = p->esquerda;
            while (pred->direita != nullptr && pred->direita != p) {
                pred = pred->direita;
            }

            if (pred->direita == nullptr) {
                // Define o ponteiro right do predecessor para o nó atual
                pred->direita = p;
                p = p->esquerda;
            } else {
                // O ponteiro right do predecessor já está definido, visita o nó atual
                pred->direita = nullptr;
                visit(p);
                p = p->direita;
            }
        }
    }
}

int main() {
    // Criar a árvore de exemplo
    ArvoreNo<int>* root = new ArvoreNo<int>(1);
    root->esquerda = new ArvoreNo<int>(2);
    root->direita = new ArvoreNo<int>(3);
    root->esquerda->esquerda = new ArvoreNo<int>(4);
    root->esquerda->direita = new ArvoreNo<int>(5);
    root->direita->esquerda = new ArvoreNo<int>(6);
    root->direita->direita = new ArvoreNo<int>(7);

    // Executar o percurso in-ordem utilizando o algoritmo de Morris
    MorrisInorder(root);

    // Liberar a memória alocada pela árvore
    delete root->esquerda->esquerda;
    delete root->esquerda->direita;
    delete root->direita->esquerda;
    delete root->direita->direita;
    delete root->esquerda;
    delete root->direita;
    delete root;

    return 0;
}
