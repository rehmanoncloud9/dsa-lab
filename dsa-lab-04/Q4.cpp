// Name: Abdul Rehman
// Registration No: 576841
// Section: BSCS-15E

#include <iostream>
using namespace std;

class List {
private:
    // node structure holding our integer and link to next
    struct node {
        int data;
        node* next;
    };
    node* head;  // pointer to the first node

public:
    // initialize head to nullptr
    List() {
        head = nullptr;
    }

    // destructor to safely free all nodes
    ~List() {
        ClearList();
    }

    // insert a new node right at the start of the list in O(1) time
    void InsertAtBeginning(int newValue) {
        // create new node with the given value
        node* fresh = new node;
        fresh->data = newValue;

        // point the new node's next to the current first node
        fresh->next = head;

        // update head so it now points to this new first node
        head = fresh;
    }

    // append a new node at the very end of the list
    void AddNode(int newValue) {
        node* fresh = new node;
        fresh->data = newValue;
        fresh->next = nullptr;

        // if list is empty, new node becomes the head
        if (head == nullptr) {
            head = fresh;
            return;
        }

        // traverse to the last node
        node* walker = head;
        while (walker->next != nullptr) {
            walker = walker->next;
        }
        walker->next = fresh;
    }

    // print every value from the first node to the last
    void PrintList() {
        if (head == nullptr) {
            cout << "The list is empty.\n";
            return;
        }

        node* walker = head;
        cout << "List: ";
        while (walker != nullptr) {
            cout << walker->data;
            if (walker->next != nullptr) {
                cout << " -> ";
            }
            walker = walker->next;
        }
        cout << "\n";
    }

    // delete all nodes and reset head to null
    void ClearList() {
        node* walker = head;
        while (walker != nullptr) {
            node* upcoming = walker->next;
            delete walker;
            walker = upcoming;
        }
        head = nullptr;
    }
};

int main() {
    List numbers;

    // step 1: check empty list output
    cout << "Starting with an empty list:\n";
    numbers.PrintList();

    // step 2: insert 20 at the beginning (list becomes: 20)
    cout << "\nInsert 20 at the beginning:\n";
    numbers.InsertAtBeginning(20);
    numbers.PrintList();

    // step 3: insert 10 at the beginning (list becomes: 10 -> 20)
    cout << "\nInsert 10 at the beginning:\n";
    numbers.InsertAtBeginning(10);
    numbers.PrintList();

    // step 4: append 30 at the end (list becomes: 10 -> 20 -> 30)
    cout << "\nAppend 30 at the end:\n";
    numbers.AddNode(30);
    numbers.PrintList();

    // clean up list before exiting
    numbers.ClearList();
    return 0;
}
