#include <iostream>
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
bool isComplete(Node* root, int height, int& min_height) {
    if (root == NULL) {
        min_height = height - 1;
        return true;
    }

    int left_height = 0, right_height = 0;
    bool is_left_complete = isComplete(root->left, height + 1, left_height);
    bool is_right_complete = isComplete(root->right, height + 1, right_height);

    // Verifica se a altura da subárvore esquerda é menor ou igual à altura da subárvore direita
    if (left_height <= right_height) {
        min_height = left_height;
    } 
    // Se a altura da subárvore esquerda for maior, verifica se a subárvore direita é completa
    else if (is_right_complete) {
        min_height = right_height;
    }
    // Caso contrário, a árvore não é completa
    else {
        return false;
    }

    // Verifica se a subárvore esquerda é completa e se a altura da subárvore direita é a mesma que a da subárvore esquerda
    if (is_left_complete && left_height == right_height) {
        return true;
    } else {
        return false;
    }
}

bool isComplete(Node* root) {
    int height = 0, min_height = 0;
    return isComplete(root, height, min_height);
}

int main() {
    // Árvore completa
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);
    root1->right->left = new Node(6);
    root1->right->right = new Node(7);

    // Verifica se a primeira árvore é completa
    if (isComplete(root1))
        cout << "A arvore 1 e completa" << endl;
    else
        cout << "A arvore 1 nao e completa" << endl;

    // Árvore incompleta
    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);
    root2->left->left = new Node(4);
    root2->left->right = new Node(5);
    root2->right->left = new Node(6);

    // Verifica se a segunda árvore é completa
    if (isComplete(root2))
        cout << "A arvore 2 e completa" << endl;
    else
        cout << "A arvore 2 nao e completa" << endl;

    return 0;
}
