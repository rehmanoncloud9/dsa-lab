// Name: Abdul Rehman
// Registration No: 576841
// Section: BSCS-15E

#include <iostream>
using namespace std;

// LIFO: the last value pushed is the first one popped
// Task 5 array stack has a fixed capacity of 5 and rejects a sixth push,
// Task 6 allocates one node per push with new, so it grows as needed
class LinkedStack {
private:
    // node structure for the linked stack
    struct node {
        int data;
        node* next;
    };

    node* top; // pointer to the top node (the head of the list)

public:
    // an empty stack has top = nullptr
    LinkedStack() {
        top = nullptr;
    }

    // destructor to safely free all nodes before object is destroyed
    ~LinkedStack() {
        ClearStack();
    }


    // true when there are no nodes
    bool IsEmpty() {
        return top == nullptr;
    }

    // add a new node at the head in O(1) time
    void Push(int value) {
        node* fresh = new node;
        fresh->data = value;
        fresh->next = top;
        top = fresh;
        cout << "Pushed " << value << ".\n";
    }

    // remove the head node in O(1) time and show its value
    void Pop() {
        if (IsEmpty()) {
            cout << "Underflow: stack is empty, nothing to pop.\n";
            return;
        }

        node* doomed = top;
        top = top->next; // save the link before delete
        cout << "Popped " << doomed->data << ".\n";
        delete doomed;
    }

    // show the top value without removing it
    void Peek() {
        if (IsEmpty()) {
            cout << "Underflow: stack is empty, nothing to peek.\n";
            return;
        }
        cout << "Top value is " << top->data << ".\n";
    }

    // print values from top to bottom
    void Display() {
        if (IsEmpty()) {
            cout << "The stack is empty.\n";
            return;
        }

        cout << "Stack (top to bottom): ";
        node* walker = top;
        while (walker != nullptr) {
            cout << walker->data;
            if (walker->next != nullptr) {
                cout << ", ";
            }
            walker = walker->next;
        }
        cout << "\n";
    }

    // delete all nodes and leave top as nullptr
    void ClearStack() {
        node* walker = top;
        while (walker != nullptr) {
            node* upcoming = walker->next;
            delete walker;
            walker = upcoming;
        }
        top = nullptr;
    }
};

// print the application menu options
void ShowMenu() {
    cout << "\n===== Linked Stack Menu =====\n";
    cout << "1. Push\n";
    cout << "2. Pop\n";
    cout << "3. Peek\n";
    cout << "4. Display\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    LinkedStack stack;
    int choice = 0;
    int typedValue;

    // run menu loop until user chooses option 5 (Exit)
    do {
        ShowMenu();

        // handle non-numeric or broken input gracefully
        if (!(cin >> choice)) {
            cout << "\nCould not read the choice, leaving the program.\n";
            break;
        }

        switch (choice) {
            case 1: // push
                cout << "Enter the value to push: ";
                cin >> typedValue;
                stack.Push(typedValue);
                break;
            case 2: // pop
                stack.Pop();
                break;
            case 3: // peek
                stack.Peek();
                break;
            case 4: // display
                stack.Display();
                break;
            case 5: // exit
                cout << "Exiting...\n";
                break;
            default: // handle invalid numeric choices
                cout << "Invalid choice, please enter a number from 1 to 5.\n";
                break;
        }
    } while (choice != 5);

    // release all remaining nodes before the program terminates
    stack.ClearStack();
    return 0;
}
