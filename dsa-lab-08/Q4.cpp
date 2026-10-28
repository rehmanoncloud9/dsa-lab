// Name: Abdul Rehman
// Reg No: 576841
// Section: 15E
// Lab 08 Task 4: searching in a BST

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

Node* searchRecursive(Node* root, int key) {
    if (root == nullptr || root->data == key) return root;
    if (key < root->data) return searchRecursive(root->left, key);
    return searchRecursive(root->right, key);
}

Node* searchIterative(Node* root, int key) {
    Node* cur = root;
    while (cur != nullptr) {
        if (key == cur->data) return cur;
        if (key < cur->data) cur = cur->left;
        else cur = cur->right;
    }
    return nullptr;
}

// prints every node compared on the way, just for the demo
void showPath(Node* root, int key) {
    cout << "Nodes compared for " << key << ": ";
    Node* cur = root;
    while (cur != nullptr) {
        cout << cur->data << " ";
        if (key == cur->data) break;
        if (key < cur->data) cur = cur->left;
        else cur = cur->right;
    }
    cout << endl;
}

void report(Node* root, int key) {
    Node* r = searchRecursive(root, key);
    Node* i = searchIterative(root, key);
    cout << "Search " << key << " recursive: " << (r ? "Found" : "Not found");
    cout << ", iterative: " << (i ? "Found" : "Not found") << endl;
}

void freeTree(Node* root) {
    if (root == nullptr) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main() {
    Node* root = createNode(40);
    root->left = createNode(20);
    root->right = createNode(60);
    root->left->left = createNode(10);
    root->left->right = createNode(30);
    root->right->left = createNode(50);
    root->right->right = createNode(70);

    report(root, 40);
    report(root, 10);
    report(root, 70);
    report(root, 25);

    // for 25 the path is 40, 20, 30 then nullptr so it is not found
    showPath(root, 25);

    cout << "Empty tree" << endl;
    report(nullptr, 40);

    freeTree(root);
    return 0;
}
