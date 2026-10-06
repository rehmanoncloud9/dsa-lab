// Name: Abdul Rehman
// Registration No: 576841
// Section: BSCS-15E

#include <iostream>
using namespace std;

class DoublyList {
private:
    // node structure for the doubly linked list
    struct node {
        int data;
        node* next;
        node* prev;
    };

    node* head; // pointer to the first node
    node* tail; // pointer to the last node

public:
    // initialize both pointers to nullptr for an empty list
    DoublyList() {
        head = nullptr;
        tail = nullptr;
    }

    // destructor to safely free all nodes before object is destroyed
    ~DoublyList() {
        ClearList();
    }


    // append a new node at the end using tail in O(1) time
    void AddNode(int value) {
        node* fresh = new node;
        fresh->data = value;
        fresh->next = nullptr;
        fresh->prev = tail;

        // empty list: the new node is both head and tail
        if (tail == nullptr) {
            head = fresh;
        } else {
            tail->next = fresh;
        }
        tail = fresh;
    }

    // print values from head to tail
    void PrintForward() {
        if (head == nullptr) {
            cout << "The list is empty.\n";
            return;
        }

        cout << "Forward: ";
        node* walker = head;
        while (walker != nullptr) {
            cout << walker->data;
            if (walker->next != nullptr) {
                cout << " <-> ";
            }
            walker = walker->next;
        }
        cout << "\n";
    }

    // print values from tail to head using the prev links
    void PrintReverse() {
        if (tail == nullptr) {
            cout << "The list is empty.\n";
            return;
        }

        cout << "Reverse: ";
        node* walker = tail;
        while (walker != nullptr) {
            cout << walker->data;
            if (walker->prev != nullptr) {
                cout << " <-> ";
            }
            walker = walker->prev;
        }
        cout << "\n";
    }

    // delete all nodes and leave head and tail as nullptr
    void ClearList() {
        node* walker = head;
        while (walker != nullptr) {
            node* upcoming = walker->next; // save the link before delete
            delete walker;
            walker = upcoming;
        }
        head = nullptr;
        tail = nullptr;
    }
};

int main() {
    DoublyList numbers;
    int count = 0;
    int typedValue;

    cout << "Enter how many integers to add: ";
    cin >> count;

    // append the requested number of integers
    for (int i = 1; i <= count; i++) {
        cout << "Enter value " << i << ": ";
        cin >> typedValue;
        numbers.AddNode(typedValue);
    }

    numbers.PrintForward();
    numbers.PrintReverse();

    // release all nodes before the program terminates
    numbers.ClearList();
    return 0;
}
