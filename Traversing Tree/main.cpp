#include <iostream>

// Definição da estrutura de um nó da BST
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Função para inserção na BST
TreeNode* insert(TreeNode* root, int data) {
    if (root == nullptr) {
        return new TreeNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }

    return root;
}

// Função para imprimir os nós da BST em ordem pre-order
void preOrder(TreeNode* root) {
    if (root != nullptr) {
        std::cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Função para imprimir os nós da BST em ordem in-order
void inOrder(TreeNode* root) {
    if (root != nullptr) {
        inOrder(root->left);
        std::cout << root->data << " ";
        inOrder(root->right);
    }
}

// Função para imprimir os nós da BST em ordem post-order
void postOrder(TreeNode* root) {
    if (root != nullptr) {
        postOrder(root->left);
        postOrder(root->right);
        std::cout << root->data << " ";
    }
}

int main() {
    int n;
    std::cin >> n;

    TreeNode* root = nullptr;

    for (int i = 0; i < n; i++) {
        int data;
        std::cin >> data;
        root = insert(root, data);
    }

    std::cout << "Pre order : ";
    preOrder(root);
    std::cout << std::endl;

    std::cout << "In order  : ";
    inOrder(root);
    std::cout << std::endl;

    std::cout << "Post order: ";
    postOrder(root);
    std::cout << std::endl;

    return 0;
}
