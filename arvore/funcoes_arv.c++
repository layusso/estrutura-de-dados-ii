#include <iostream>

using namespace std;

// Estrutura do nó da árvore binária
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

// Função que insere um novo nó na árvore binária
Node* insertNode(Node* root, int value) {
    if (root == NULL) {
        return new Node(value);
    }
    if (value < root->data) {
        root->left = insertNode(root->left, value);
    } else if (value > root->data) {
        root->right = insertNode(root->right, value);
    }
    return root;
}

// Função que conta a quantidade de nós na árvore binária
int countNodes(Node* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Função que conta o total de folhas na árvore binária
int countLeaves(Node* root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    return countLeaves(root->left) + countLeaves(root->right);
}

// Função que calcula a altura da árvore binária
int height(Node* root) {
    if (root == NULL) {
        return -1;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return 1 + max(leftHeight, rightHeight);
}

// Função que verifica se um item está presente na árvore binária
bool search(Node* root, int value) {
    if (root == NULL) {
        return false;
    }
    if (root->data == value) {
        return true;
    } else if (value < root->data) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

int main() {
    // Exemplo de uso das funções
    Node* root = NULL;
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);

    cout << "Quantidade de nós: " << countNodes(root) << endl;
    cout << "Total de folhas: " << countLeaves(root) << endl;
    cout << "Altura da árvore: " << height(root) << endl;
    cout << "O item 40 está na árvore? " << (search(root, 40) ? "Sim" : "Não") << endl;
    cout << "O item 100 está na árvore? " << (search(root, 100) ? "Sim" : "Não") << endl;

    return 0;
}