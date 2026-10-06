// Name: Abdul Rehman
// Registration No: 576841
// Section: BSCS-15E

#include <iostream>
using namespace std;

class CircularList {
private:
    // node structure for the singly circular list
    struct node {
        int data;
        node* next;
    };

    node* head; // pointer to the first node
    node* tail; // pointer to the last node, tail->next always points to head

public:
    // initialize both pointers to nullptr for an empty list
    CircularList() {
        head = nullptr;
        tail = nullptr;
    }

    // destructor to safely free all nodes before object is destroyed
    ~CircularList() {
        ClearList();
    }


    // append a new node at the end using tail and keep tail->next = head
    void AddNode(int value) {
        node* fresh = new node;
        fresh->data = value;

        if (tail == nullptr) {
            // first node links to itself
            fresh->next = fresh;
            head = fresh;
        } else {
            fresh->next = head;
            tail->next = fresh;
        }
        tail = fresh;
    }

    // print every value exactly once, stopping after one complete cycle
    void PrintList() {
        // check for an empty list before traversing
        if (head == nullptr) {
            cout << "The list is empty.\n";
            return;
        }

        cout << "List: ";
        node* walker = head;
        do {
            cout << walker->data;
            walker = walker->next;
            if (walker != head) {
                cout << " -> ";
            }
        } while (walker != head); // back at head means one full cycle is done
        cout << " -> (back to head)\n";
    }

    // count the nodes in one complete cycle
    int CountNodes() {
        if (head == nullptr) {
            return 0;
        }

        int total = 0;
        node* walker = head;
        do {
            total++;
            walker = walker->next;
        } while (walker != head);
        return total;
    }

    // delete all nodes and leave head and tail as nullptr
    void ClearList() {
        if (head == nullptr) {
            return;
        }

        // break the circle first so the loop can stop at nullptr
        tail->next = nullptr;

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

// a nullptr-based loop never ends here because no node has next == nullptr:
// tail->next points back to head, so traversal must stop when it returns to head
int main() {
    CircularList empty;
    CircularList single;
    CircularList three;

    cout << "--- Test 1: empty list ---\n";
    empty.PrintList();
    cout << "Count: " << empty.CountNodes() << "\n\n";

    cout << "--- Test 2: one node ---\n";
    single.AddNode(10);
    single.PrintList();
    cout << "Count: " << single.CountNodes() << "\n\n";

    cout << "--- Test 3: 10, 20, 30 ---\n";
    three.AddNode(10);
    three.AddNode(20);
    three.AddNode(30);
    three.PrintList();
    cout << "Count: " << three.CountNodes() << "\n\n";

    // release all remaining nodes before the program terminates
    empty.ClearList();
    single.ClearList();
    three.ClearList();
    return 0;
}
