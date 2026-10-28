// Name: Abdul Rehman
// Reg No: 576841
// Section: 15E
// Lab 08 Task 2: level order traversal using a queue

#include <iostream>
#include <queue>
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

void levelOrder(Node* root) {
    if (root == nullptr) return;  // nothing to print
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* cur = q.front();
        q.pop();
        cout << cur->data << " ";
        if (cur->left != nullptr) q.push(cur->left);
        if (cur->right != nullptr) q.push(cur->right);
    }
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

    // expected: 40 20 60 10 30 50 70
    cout << "Level order: ";
    levelOrder(root);
    cout << endl;

    cout << "Empty tree:  ";
    levelOrder(nullptr);
    cout << endl;

    Node* single = createNode(5);
    cout << "Single node: ";
    levelOrder(single);
    cout << endl;

    freeTree(root);
    freeTree(single);
    return 0;
}
