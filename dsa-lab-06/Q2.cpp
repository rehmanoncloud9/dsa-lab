// Name: Abdul Rehman
// Registration Number: 576841
// Section: BSCS-15E
// Task 2: Stack using a singly linked list
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* top = nullptr;

void push(int value) {
    Node* n = new Node;
    n->data = value;
    n->next = top; // insert at head
    top = n;
    cout << "Pushed " << value << endl;
}

void pop() {
    if (top == nullptr) {
        cout << "Stack underflow: cannot pop, stack is empty." << endl;
        return;
    }
    Node* temp = top;
    cout << "Popped " << temp->data << endl;
    top = top->next; // remove from head
    delete temp;
}

void peek() {
    if (top == nullptr) {
        cout << "Cannot peek: stack is empty." << endl;
        return;
    }
    cout << "Top element: " << top->data << endl;
}

void display() {
    if (top == nullptr) {
        cout << "Stack is empty." << endl;
        return;
    }
    cout << "Stack (top to bottom): ";
    for (Node* cur = top; cur != nullptr; cur = cur->next)
        cout << cur->data << " ";
    cout << endl;
}

void clearStack() {
    while (top != nullptr) {
        Node* temp = top;
        top = top->next;
        delete temp;
    }
}

int main() {
    push(5);
    push(15);
    push(25);
    display();
    pop();
    peek();
    display();

    cout << "\n--- Empty pop test ---" << endl;
    pop();
    pop();
    pop(); // stack is now empty, this one must be blocked
    peek();
    display();

    // Leave some nodes in the stack and release them before exit
    push(100);
    push(200);
    display();
    clearStack();
    cout << "All remaining nodes released." << endl;
    display();
    return 0;
}
