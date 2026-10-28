// Name: Abdul Rehman
// Reg No: 576841
// Section: 15E
// Lab 08 Task 1: recursive depth first traversals

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* n = new Node;
    n->data = value;
    n->left = nullptr;
    n->right = nullptr;
    return n;
}

void inorder(Node* root) {
    if (root == nullptr) return;  // stop at empty child
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void freeTree(Node* root) {
    if (root == nullptr) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main() {
    // build the seven node tree by linking nodes
    Node* root = createNode(40);
    root->left = createNode(20);
    root->right = createNode(60);
    root->left->left = createNode(10);
    root->left->right = createNode(30);
    root->right->left = createNode(50);
    root->right->right = createNode(70);

    // my predictions: inorder 10 20 30 40 50 60 70
    // preorder 40 20 10 30 60 50 70, postorder 10 30 20 50 70 60 40
    cout << "Inorder:   ";
    inorder(root);
    cout << endl;

    cout << "Preorder:  ";
    preorder(root);
    cout << endl;

    cout << "Postorder: ";
    postorder(root);
    cout << endl;

    // nullptr test, should print nothing
    cout << "Empty tree inorder:   ";
    inorder(nullptr);
    cout << endl;
    cout << "Empty tree preorder:  ";
    preorder(nullptr);
    cout << endl;
    cout << "Empty tree postorder: ";
    postorder(nullptr);
    cout << endl;

    // single node test
    Node* single = createNode(5);
    cout << "Single node inorder:   ";
    inorder(single);
    cout << endl;
    cout << "Single node preorder:  ";
    preorder(single);
    cout << endl;
    cout << "Single node postorder: ";
    postorder(single);
    cout << endl;

    freeTree(root);
    freeTree(single);
    return 0;
}
