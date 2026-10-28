// Name: Abdul Rehman
// Reg No: 576841
// Section: 15E
// Lab 08 Task 6: iterative insertion in a BST

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

Node* insertIterative(Node* root, int value) {
    if (root == nullptr) return createNode(value);  // empty tree case
    Node* cur = root;
    Node* parent = nullptr;
    while (cur != nullptr) {
        parent = cur;
        if (value < cur->data) cur = cur->left;
        else if (value > cur->data) cur = cur->right;
        else return root;  // duplicate, ignore it
    }
    // attach to the correct side of the parent
    if (value < parent->data) parent->left = createNode(value);
    else parent->right = createNode(value);
    return root;
}

// recursive insert from task 5, used to compare both trees
Node* insertRecursive(Node* root, int value) {
    if (root == nullptr) return createNode(value);
    if (value < root->data) root->left = insertRecursive(root->left, value);
    else if (value > root->data) root->right = insertRecursive(root->right, value);
    return root;
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

// same as search but also counts the nodes compared
int countCompared(Node* root, int key) {
    int count = 0;
    Node* cur = root;
    while (cur != nullptr) {
        count++;
        if (key == cur->data) break;
        if (key < cur->data) cur = cur->left;
        else cur = cur->right;
    }
    return count;
}

void inorder(Node* root) {
    if (root == nullptr) return;
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

void freeTree(Node* root) {
    if (root == nullptr) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main() {
    int values[] = {40, 20, 60, 10, 30, 50, 70};

    Node* recTree = nullptr;
    Node* itTree = nullptr;
    for (int v : values) {
        recTree = insertRecursive(recTree, v);
        itTree = insertIterative(itTree, v);
    }
    itTree = insertIterative(itTree, 25);
    recTree = insertRecursive(recTree, 25);
    itTree = insertIterative(itTree, 20);  // duplicate
    recTree = insertRecursive(recTree, 20);

    cout << "Recursive tree inorder:  ";
    inorder(recTree);
    cout << endl;
    cout << "Iterative tree inorder:  ";
    inorder(itTree);
    cout << endl;
    cout << "Recursive tree preorder: ";
    preorder(recTree);
    cout << endl;
    cout << "Iterative tree preorder: ";
    preorder(itTree);
    cout << endl;

    // skewed tree test
    Node* skewed = nullptr;
    int chain[] = {10, 20, 30, 40, 50};
    for (int v : chain) {
        skewed = insertIterative(skewed, v);
    }
    cout << "Skewed inorder:  ";
    inorder(skewed);
    cout << endl;
    cout << "Skewed preorder: ";
    preorder(skewed);
    cout << endl;

    cout << "Search 50: " << (searchIterative(skewed, 50) ? "Found" : "Not found") << endl;
    cout << "Nodes compared for 50: " << countCompared(skewed, 50) << endl;

    // 5 nodes compared here. a skewed tree is a linked list so height is n and search is O(n).
    // a balanced tree has height about log n so it needs far fewer comparisons as n grows.

    freeTree(recTree);
    freeTree(itTree);
    freeTree(skewed);
    return 0;
}
