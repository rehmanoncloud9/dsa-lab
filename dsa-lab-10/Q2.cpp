// Name: Abdul Rehman
// Reg No: 576841
// Section: 15E
// Lab 10 Task 2: AVL insertion with LL, RR, LR and RL rotations

#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    int height;
};

Node* createNode(int value) {
    Node* n = new Node;
    n->data = value;
    n->left = nullptr;
    n->right = nullptr;
    n->height = 1;  // a new leaf has height 1
    return n;
}

int height(Node* n) {
    return n == nullptr ? 0 : n->height;
}

int balanceFactor(Node* n) {
    return n == nullptr ? 0 : height(n->left) - height(n->right);
}

void updateHeight(Node* n) {
    n->height = 1 + max(height(n->left), height(n->right));
}

Node* rightRotate(Node* root) {
    Node* newRoot = root->left;
    Node* moved = newRoot->right;
    newRoot->right = root;
    root->left = moved;
    // the old root sits lower now so it gets updated first
    updateHeight(root);
    updateHeight(newRoot);
    return newRoot;
}

Node* leftRotate(Node* root) {
    Node* newRoot = root->right;
    Node* moved = newRoot->left;
    newRoot->left = root;
    root->right = moved;
    updateHeight(root);
    updateHeight(newRoot);
    return newRoot;
}

// fixes one node using the balance factors of the node and its heavy child
Node* rebalance(Node* root) {
    updateHeight(root);
    int bf = balanceFactor(root);

    if (bf > 1) {
        if (balanceFactor(root->left) >= 0) {
            cout << "  imbalance at " << root->data << ": LL case, right rotate" << endl;
            return rightRotate(root);
        }
        cout << "  imbalance at " << root->data << ": LR case, left rotate then right rotate" << endl;
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (bf < -1) {
        if (balanceFactor(root->right) <= 0) {
            cout << "  imbalance at " << root->data << ": RR case, left rotate" << endl;
            return leftRotate(root);
        }
        cout << "  imbalance at " << root->data << ": RL case, right rotate then left rotate" << endl;
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

Node* insertAVL(Node* root, int value) {
    if (root == nullptr) return createNode(value);
    if (value < root->data) root->left = insertAVL(root->left, value);
    else if (value > root->data) root->right = insertAVL(root->right, value);
    else return root;  // duplicate, nothing to do
    return rebalance(root);
}

void preorder(Node* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// checks stored heights and that every balance factor is -1, 0 or 1
bool isBalanced(Node* root) {
    if (root == nullptr) return true;
    if (root->height != 1 + max(height(root->left), height(root->right))) return false;
    int bf = balanceFactor(root);
    if (bf < -1 || bf > 1) return false;
    return isBalanced(root->left) && isBalanced(root->right);
}

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

void runSequence(const char* name, int a, int b, int c) {
    cout << "Sequence " << name << ": " << a << ", " << b << ", " << c << endl;
    Node* root = nullptr;
    root = insertAVL(root, a);
    root = insertAVL(root, b);
    root = insertAVL(root, c);

    cout << "Final tree (right on top):" << endl;
    printTree(root);
    cout << "Preorder: ";
    preorder(root);
    cout << endl << "Inorder:  ";
    inorder(root);
    cout << endl;
    cout << "All nodes balanced: " << (isBalanced(root) ? "yes" : "no") << endl;
    cout << endl;
    freeTree(root);
}

int main() {
    // expected: (a) LL, (b) RR, (c) LR, (d) RL and all four end with 20 as the root
    runSequence("a", 30, 20, 10);
    runSequence("b", 10, 20, 30);
    runSequence("c", 30, 10, 20);
    runSequence("d", 10, 30, 20);

    // extra checks, duplicate keys and a longer run
    cout << "Duplicate test: 10, 10, 10" << endl;
    Node* dup = nullptr;
    dup = insertAVL(dup, 10);
    dup = insertAVL(dup, 10);
    dup = insertAVL(dup, 10);
    cout << "Inorder: ";
    inorder(dup);
    cout << endl << endl;
    freeTree(dup);

    cout << "Longer run: 1 to 7 in order" << endl;
    Node* big = nullptr;
    for (int i = 1; i <= 7; i++) big = insertAVL(big, i);
    cout << "Preorder: ";
    preorder(big);
    cout << endl << "All nodes balanced: " << (isBalanced(big) ? "yes" : "no") << endl;
    freeTree(big);
    return 0;
}