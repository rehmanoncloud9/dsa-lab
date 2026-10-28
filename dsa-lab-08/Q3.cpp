// Name: Abdul Rehman
// Reg No: 576841
// Section: 15E
// Lab 08 Task 3: iterative traversals using a stack

#include <iostream>
#include <stack>
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

// recursive versions from task 1, only for comparing output
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

void preorderIterative(Node* root) {
    if (root == nullptr) return;
    stack<Node*> st;
    st.push(root);
    while (!st.empty()) {
        Node* cur = st.top();
        st.pop();
        cout << cur->data << " ";
        // push right first so left comes off the stack first
        if (cur->right != nullptr) st.push(cur->right);
        if (cur->left != nullptr) st.push(cur->left);
    }
}

void inorderIterative(Node* root) {
    stack<Node*> st;
    Node* cur = root;
    while (cur != nullptr || !st.empty()) {
        // go left as far as possible and remember the nodes on the way
        while (cur != nullptr) {
            st.push(cur);
            cur = cur->left;
        }
        cur = st.top();
        st.pop();
        cout << cur->data << " ";
        cur = cur->right;
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

    cout << "Preorder recursive: ";
    preorder(root);
    cout << endl;
    cout << "Preorder iterative: ";
    preorderIterative(root);
    cout << endl;

    cout << "Inorder recursive:  ";
    inorder(root);
    cout << endl;
    cout << "Inorder iterative:  ";
    inorderIterative(root);
    cout << endl;

    // nullptr test, should print nothing
    cout << "Empty preorder iterative: ";
    preorderIterative(nullptr);
    cout << endl;
    cout << "Empty inorder iterative:  ";
    inorderIterative(nullptr);
    cout << endl;

    freeTree(root);
    return 0;
}
