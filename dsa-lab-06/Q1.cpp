// Name: Abdul Rehman
// Registration Number: 576841
// Section: BSCS-15E
// Task 1: Stack using an array
#include <iostream>
using namespace std;

const int SIZE = 5;
int items[SIZE];
int top = -1;

void push(int value) {
    if (top == SIZE - 1) {
        cout << "Stack overflow: cannot push " << value << ", stack is full." << endl;
        return;
    }
    items[++top] = value;
    cout << "Pushed " << value << endl;
}

void pop() {
    if (top == -1) {
        cout << "Stack underflow: cannot pop, stack is empty." << endl;
        return;
    }
    cout << "Popped " << items[top--] << endl;
}

void peek() {
    if (top == -1) {
        cout << "Cannot peek: stack is empty." << endl;
        return;
    }
    cout << "Top element: " << items[top] << endl;
}

void display() {
    if (top == -1) {
        cout << "Stack is empty." << endl;
        return;
    }
    cout << "Stack (top to bottom): ";
    for (int i = top; i >= 0; i--)
        cout << items[i] << " ";
    cout << endl;
}

int main() {
    push(10);
    push(20);
    push(30);
    display();
    pop();
    peek();
    display();

    cout << "\n--- Fill the stack (capacity 5), then try one more insertion ---" << endl;
    push(40);
    push(50);
    push(60);
    push(70); // stack is full, this insertion must be blocked
    display();

    cout << "\n--- Remove all values, then pop again ---" << endl;
    while (top != -1)
        pop();
    pop(); // pop on empty stack
    peek(); // peek on empty stack
    display();
    return 0;
}
