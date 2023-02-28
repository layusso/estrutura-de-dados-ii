include <stdio.h>
#include <stdlib.h>

// Definindo a estrutura do nó da árvore
typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;

// Função para criar um novo nó
Node* newNode(int value) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Função para imprimir os nós da árvore
void printNodes(Node* node) {
    printf("%d ", node->value);
    if (node->left != NULL) {
        printf("%d ", node->left->value);
    }
    if (node->right != NULL) {
        printf("%d ", node->right->value);
    }
    printf("\n");
    if (node->left != NULL) {
        printNodes(node->left);
    }
    if (node->right != NULL) {
        printNodes(node->right);
    }
}

// Função para percorrer a árvore em largura
void breadthFirstSearch(Node* root) {
    // Criando uma fila para manter o rastreamento dos nós a serem visitados
    Node* queue[100];
    int front = 0;
    int rear = 0;

    // Adicionando o nó raiz na fila
    queue[rear++] = root;

    while (front != rear) {
        // Removendo o primeiro nó da fila
        Node* current = queue[front++];

        // Visitando o nó atual
        printf("%d ", current->value);

        // Adicionando os filhos do nó atual na fila
        if (current->left != NULL) {
            queue[rear++] = current->left;
        }
        if (current->right != NULL) {
            queue[rear++] = current->right;
        }
    }
}

// Função principal
int main() {
    // Criando a árvore
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    // Imprimindo os nós da árvore
    printf("Nodes: ");
    printNodes(root);

    // Percorrendo a árvore em largura
    printf("BFS: ");
    breadthFirstSearch(root);

    return 0;
}





