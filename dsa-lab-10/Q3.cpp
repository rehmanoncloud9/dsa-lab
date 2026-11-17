// Name: Abdul Rehman
// Reg No: 576841
// Section: 15E
// Lab 10 Task 3: AVL insertion and deletion

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
    n->height = 1;
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
    updateHeight(root);  // old root first since it is the lower node now
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

// picks the rotation from the child balance factor, never from the key that was removed
Node* rebalance(Node* root) {
    updateHeight(root);
    int bf = balanceFactor(root);

    if (bf > 1) {
        int childBf = balanceFactor(root->left);
        if (childBf >= 0) {
            // childBf of 0 only happens after a deletion and one rotation is enough
            cout << "  imbalance at " << root->data << " (left child balance " << childBf
                 << "): right rotate" << endl;
            return rightRotate(root);
        }
        cout << "  imbalance at " << root->data << " (left child balance " << childBf
             << "): left rotate then right rotate" << endl;
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (bf < -1) {
        int childBf = balanceFactor(root->right);
        if (childBf <= 0) {
            cout << "  imbalance at " << root->data << " (right child balance " << childBf
                 << "): left rotate" << endl;
            return leftRotate(root);
        }
        cout << "  imbalance at " << root->data << " (right child balance " << childBf
             << "): right rotate then left rotate" << endl;
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

Node* insertAVL(Node* root, int value) {
    if (root == nullptr) return createNode(value);
    if (value < root->data) root->left = insertAVL(root->left, value);
    else if (value > root->data) root->right = insertAVL(root->right, value);
    else return root;  // ignore duplicates
    return rebalance(root);
}

Node* findMin(Node* root) {
    while (root->left != nullptr) root = root->left;
    return root;
}

Node* deleteAVL(Node* root, int value) {
    if (root == nullptr) return nullptr;  // empty tree or missing key

    if (value < root->data) {
        root->left = deleteAVL(root->left, value);
    } else if (value > root->data) {
        root->right = deleteAVL(root->right, value);
    } else {
        if (root->left == nullptr) {
            Node* child = root->right;
            delete root;
            return child;  // nothing left here so there is nothing to rebalance
        }
        if (root->right == nullptr) {
            Node* child = root->left;
            delete root;
            return child;
        }
        Node* succ = findMin(root->right);
        root->data = succ->data;
        root->right = deleteAVL(root->right, succ->data);
    }
    // runs at every ancestor on the way back up
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

void printTree(Node* root, int depth = 0) {
    if (root == nullptr) return;
    printTree(root->right, depth + 1);
    for (int i = 0; i < depth; i++) cout << "    ";
    cout << root->data << endl;
    printTree(root->left, depth + 1);
}

// one line per node in sorted order
void printDetails(Node* root) {
    if (root == nullptr) return;
    printDetails(root->left);
    cout << "  key " << root->data << "  height " << root->height
         << "  balance " << balanceFactor(root) << endl;
    printDetails(root->right);
}

bool isBalanced(Node* root) {
    if (root == nullptr) return true;
    if (root->height != 1 + max(height(root->left), height(root->right))) return false;
    int bf = balanceFactor(root);
    if (bf < -1 || bf > 1) return false;
    return isBalanced(root->left) && isBalanced(root->right);
}

// checks the ordering rule using the allowed range for every node
bool isBST(Node* root, long lo, long hi) {
    if (root == nullptr) return true;
    if (root->data <= lo || root->data >= hi) return false;
    return isBST(root->left, lo, root->data) && isBST(root->right, root->data, hi);
}

void freeTree(Node* root) {
    if (root == nullptr) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

void report(Node* root) {
    cout << "Tree (right on top):" << endl;
    if (root == nullptr) cout << "(empty)" << endl;
    else printTree(root);
    cout << "Preorder: ";
    preorder(root);
    cout << endl << "Inorder:  ";
    inorder(root);
    cout << endl;
    printDetails(root);
    cout << "BST order ok: " << (isBST(root, -2147483648L, 2147483647L) ? "yes" : "no")
         << ", AVL balance ok: " << (isBalanced(root) ? "yes" : "no") << endl;
    cout << endl;
}

int main() {
    int keys[] = {30, 20, 40, 10, 25, 50, 5};
    Node* root = nullptr;
    for (int k : keys) root = insertAVL(root, k);

    cout << "=== Main test: 30, 20, 40, 10, 25, 50, 5 ===" << endl;
    report(root);

    // delete 50, a leaf. node 30 turns left heavy (balance 2) and its left child 20
    // has balance 1 so this is the LL case and one right rotation fixes it
    cout << "Delete 50" << endl;
    root = deleteAVL(root, 50);
    report(root);

    // delete 40, a leaf. every ancestor stays within -1 to 1 so no rotation is needed
    cout << "Delete 40" << endl;
    root = deleteAVL(root, 40);
    report(root);

    cout << "=== Missing key ===" << endl;
    cout << "Delete 99" << endl;
    root = deleteAVL(root, 99);
    report(root);
    freeTree(root);

    cout << "=== Empty tree ===" << endl;
    Node* empty = nullptr;
    empty = deleteAVL(empty, 10);
    cout << (empty == nullptr ? "still empty, returned nullptr" : "something went wrong") << endl;
    cout << endl;

    cout << "=== One node tree ===" << endl;
    Node* single = createNode(42);
    single = deleteAVL(single, 42);
    cout << (single == nullptr ? "returned nullptr, tree is empty" : "something went wrong") << endl;
    cout << endl;

    // heavy child balance 0: node 20 has two children and 40 is removed
    cout << "=== Heavy child balance 0 ===" << endl;
    Node* t = nullptr;
    int zero[] = {30, 20, 40, 10, 25};
    for (int k : zero) t = insertAVL(t, k);
    report(t);
    cout << "Delete 40" << endl;
    t = deleteAVL(t, 40);
    report(t);
    // here 30 is left heavy and its left child 20 has balance 0. a single right rotate
    // lifts 20 and gives 25 to 30 as its left child, so the result is balanced.
    // the double rotation is only for a child leaning the other way (balance -1),
    // and with balance 0 it would not even be needed, one rotation already works
    freeTree(t);

    // extra tests for the double rotation cases on deletion
    cout << "=== Delete causing LR ===" << endl;
    Node* lr = nullptr;
    int lrKeys[] = {30, 10, 40, 20};
    for (int k : lrKeys) lr = insertAVL(lr, k);
    cout << "Delete 40" << endl;
    lr = deleteAVL(lr, 40);
    report(lr);
    freeTree(lr);

    cout << "=== Delete causing RL ===" << endl;
    Node* rl = nullptr;
    int rlKeys[] = {30, 10, 40, 35};
    for (int k : rlKeys) rl = insertAVL(rl, k);
    cout << "Delete 10" << endl;
    rl = deleteAVL(rl, 10);
    report(rl);
    freeTree(rl);

    return 0;
}