// Name: Abdul Rehman
// Registration No: 576841
// Section: BSCS-15E

#include <iostream>
using namespace std;

class ArrayStack {
private:
    int items[5]; // fixed capacity of 5 values
    int top;      // index of the top value, -1 means the stack is empty

public:
    // an empty stack has top = -1
    ArrayStack() {
        top = -1;
    }


    // true when there are no values
    bool IsEmpty() {
        return top == -1;
    }

    // true when all 5 slots are used
    bool IsFull() {
        return top == 4;
    }

    // add a value on top, reject it if the stack is full (overflow)
    void Push(int value) {
        if (IsFull()) {
            cout << "Overflow: stack is full, cannot push " << value << ".\n";
            return;
        }
        top++;
        items[top] = value;
        cout << "Pushed " << value << ".\n";
    }

    // remove and show the top value, reject if the stack is empty (underflow)
    void Pop() {
        if (IsEmpty()) {
            cout << "Underflow: stack is empty, nothing to pop.\n";
            return;
        }
        cout << "Popped " << items[top] << ".\n";
        top--;
    }

    // show the top value without removing it
    void Peek() {
        if (IsEmpty()) {
            cout << "Underflow: stack is empty, nothing to peek.\n";
            return;
        }
        cout << "Top value is " << items[top] << ".\n";
    }

    // print values from top to bottom
    void Display() {
        if (IsEmpty()) {
            cout << "The stack is empty.\n";
            return;
        }

        cout << "Stack (top to bottom): ";
        for (int i = top; i >= 0; i--) {
            cout << items[i];
            if (i > 0) {
                cout << ", ";
            }
        }
        cout << "\n";
    }
};

int main() {
    ArrayStack stack;

    cout << "--- Push 10, 20, 30, 40, 50 ---\n";
    stack.Push(10);
    stack.Push(20);
    stack.Push(30);
    stack.Push(40);
    stack.Push(50);
    stack.Display();

    cout << "\n--- Sixth push must be rejected ---\n";
    stack.Push(60);
    stack.Display();

    cout << "\n--- Pop 50, then peek 40 ---\n";
    stack.Pop();
    stack.Peek();
    stack.Display();

    cout << "\n--- Empty the stack ---\n";
    stack.Pop();
    stack.Pop();
    stack.Pop();
    stack.Pop();
    stack.Display();

    cout << "\n--- One further pop and peek on the empty stack ---\n";
    stack.Pop();
    stack.Peek();

    return 0;
}
