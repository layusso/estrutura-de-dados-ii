#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

// Estrutura para representar um nó da árvore
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Função para verificar se a árvore é completa
bool isComplete(Node* root) {
    // Se a árvore estiver vazia, ela é considerada completa
    if (root == NULL)
        return true;

    // Cálculo da altura mínima da árvore completa
    int h_min = log2(root->data) + 1;

    queue<Node*> q;
    q.push(root);

    // Variável para controlar se já encontrou um nó que não tem dois filhos
    bool foundIncomplete = false;

    // Percorre a árvore em nível usando uma fila
    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        // Verifica se o nó atual é incompleto
        if ((curr->left == NULL && curr->right != NULL) || (curr->left != NULL && curr->right == NULL)) {
            foundIncomplete = true;
        }
        // Se já encontrou um nó incompleto e o nó atual tem filhos, então não é completa
        else if (foundIncomplete && (curr->left != NULL || curr->right != NULL)) {
            return false;
        }

        // Adiciona os filhos do nó atual na fila
        if (curr->left != NULL)
            q.push(curr->left);
        if (curr->right != NULL)
            q.push(curr->right);
    }

    // Se chegou aqui, a árvore é completa
    return true;
}

int main() {
    // Cria a árvore
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->left = new Node(60);
    root->right->right = new Node(70);

    // Verifica se a árvore é completa
    if (isComplete(root))
        cout << "A arvore e completa" << endl;
    else
        cout << "A arvore nao e completa" << endl;

    return 0;
}
