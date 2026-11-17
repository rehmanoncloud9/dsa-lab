// Name: Abdul Rehman
// Reg No: 576841
// Section: 15E
// Lab 10 Task 1: BST deletion (leaf, one child and two children)

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    int height;  // not used in this task, kept so the struct matches the AVL tasks
};

Node* createNode(int value) {
    Node* n = new Node;
    n->data = value;
    n->left = nullptr;
    n->right = nullptr;
    n->height = 1;
    return n;
}

Node* insertBST(Node* root, int value) {
    if (root == nullptr) return createNode(value);
    if (value < root->data) root->left = insertBST(root->left, value);
    else if (value > root->data) root->right = insertBST(root->right, value);
    // equal keys fall through and get ignored
    return root;
}

// the inorder successor is the smallest key in the right subtree
Node* findMin(Node* root) {
    while (root->left != nullptr) root = root->left;
    return root;
}

Node* deleteBST(Node* root, int value) {
    if (root == nullptr) return nullptr;  // empty tree or key not found

    if (value < root->data) {
        root->left = deleteBST(root->left, value);
    } else if (value > root->data) {
        root->right = deleteBST(root->right, value);
    } else {
        // found it, a leaf also lands here because its left child is null
        if (root->left == nullptr) {
            Node* child = root->right;
            delete root;
            return child;
        }
        if (root->right == nullptr) {
            Node* child = root->left;
            delete root;
            return child;
        }
        // two children, copy the successor key up then delete the successor below
        Node* succ = findMin(root->right);
        root->data = succ->data;
        root->right = deleteBST(root->right, succ->data);
    }
    return root;
}

void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// sideways picture of the tree, right side on top and root on the left
void printTree(Node* root, int depth = 0) {
    if (root == nullptr) return;
    printTree(root->right, depth + 1);
    for (int i = 0; i < depth; i++) cout << "    ";
    cout << root->data << endl;
    printTree(root->left, depth + 1);
}

void freeTree(Node* root) {
    if (root == nullptr) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

void showInorder(const char* label, Node* root) {
    cout << label << ": ";
    inorder(root);
    cout << endl;
}

int main() {
    int keys[] = {50, 30, 70, 20, 40, 60, 80, 65};
    Node* root = nullptr;
    for (int k : keys) root = insertBST(root, k);

    cout << "Starting tree (right on top):" << endl;
    printTree(root);
    showInorder("Inorder", root);
    cout << endl;

    // delete 20, it is a leaf so the parent 30 just loses its left child
    // my prediction: 30 40 50 60 65 70 80
    cout << "Delete 20 (case: leaf)" << endl;
    root = deleteBST(root, 20);
    showInorder("Inorder", root);

    // delete 60, it has one child (65) so 65 takes its place under 70
    // my prediction: 30 40 50 65 70 80
    cout << "Delete 60 (case: one child)" << endl;
    root = deleteBST(root, 60);
    showInorder("Inorder", root);

    // delete 50, two children, successor is 65 so the root key becomes 65
    // my prediction: 30 40 65 70 80
    cout << "Delete 50 (case: two children, successor 65)" << endl;
    root = deleteBST(root, 50);
    showInorder("Inorder", root);
    cout << "Tree now:" << endl;
    printTree(root);
    cout << endl;

    // missing key should leave the tree as it is
    cout << "Delete 99 (missing key)" << endl;
    root = deleteBST(root, 99);
    showInorder("Inorder", root);
    cout << endl;

    // empty tree
    cout << "Delete 10 from an empty tree" << endl;
    Node* empty = nullptr;
    empty = deleteBST(empty, 10);
    cout << (empty == nullptr ? "still empty, returned nullptr" : "something went wrong") << endl;
    cout << endl;

    // only node
    cout << "Delete the only node (42)" << endl;
    Node* single = createNode(42);
    single = deleteBST(single, 42);
    cout << (single == nullptr ? "returned nullptr, tree is empty" : "something went wrong") << endl;

    freeTree(root);
    return 0;
}