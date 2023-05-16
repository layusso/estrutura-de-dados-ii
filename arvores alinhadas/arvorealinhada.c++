#include <iostream>
#include <vector>

using namespace std;

// Definição da estrutura do nó da árvore
struct Node {
    int data;
    vector<Node*> children;
};

// Função para criar um novo nó
Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    return newNode;
}

// Função para incluir um nó filho em um nó pai existente
void addChild(Node* parent, Node* child) {
    parent->children.push_back(child);
}

// Função para exibir a árvore alinhada
void displayTree(Node* root, int level) {
    if (root == NULL)
        return;

    for (int i = 0; i < level; i++)
        cout << "  ";

    cout << root->data << endl;

    for (Node* child : root->children)
        displayTree(child, level + 1);
}

// Função para realizar o percurso in-order
void inOrderTraversal(Node* node) {
    if (node == nullptr)
        return;

    for (Node* child : node->children)
        inOrderTraversal(child);

    cout << node->data << " ";
}

// Função para realizar o percurso pré-order
void preOrderTraversal(Node* node) {
    if (node == nullptr)
        return;

    cout << node->data << " ";

    for (Node* child : node->children)
        preOrderTraversal(child);
}


int main() {
    // Criando a árvore
    Node* root = createNode(1);
    Node* child1 = createNode(2);
    Node* child2 = createNode(3);
    Node* child3 = createNode(4);
    Node* grandchild1 = createNode(5);
    Node* grandchild2 = createNode(6);
    Node* grandchild3 = createNode(7);

    // Incluindo os nós filhos
    addChild(root, child1);
    addChild(root, child2);
    addChild(root, child3);
    addChild(child1, grandchild1);
    addChild(child1, grandchild2);
    addChild(child2, grandchild3);

    // Exibindo a árvore alinhada
    displayTree(root, 0);

    // Realizando o percurso in-order
    inOrderTraversal(root);

    // Realizando o percurso pré-order
    preOrderTraversal(root);

    return 0;
}
