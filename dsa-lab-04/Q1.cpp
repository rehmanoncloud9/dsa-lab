// Name: Abdul Rehman
// Registration No: 576841
// Section: BSCS-15E

#include <iostream>
using namespace std;

class List {
private:
    // basic building block of our linked list
    // each node stores its integer data and a pointer to the next node in memory
    struct node {
        int data;
        node* next;
    };
    node* head;  // points to the very first node in the list

public:
    // constructor: start with an empty list where head points to null
    List() {
        head = nullptr;
    }

    // destructor: automatically clean up all nodes when the list object goes out of scope
    ~List() {
        ClearList();
    }

    // read three integers from the user and link them in the exact order entered
    void CreateThreeNodes() {
        // check if list already has nodes so we don't accidentally overwrite them
        if (head != nullptr) {
            cout << "The list already has nodes, so nothing was created.\n";
            return;
        }

        // keep track of the last node created so we can hook the next one to it
        node* lastNode = nullptr;

        for (int round = 1; round <= 3; round++) {
            int typedValue;
            cout << "Enter integer " << round << ": ";
            cin >> typedValue;

            // allocate a new node on the heap using new
            node* fresh = new node;
            fresh->data = typedValue;
            fresh->next = nullptr;  // new node has no successor yet

            // if this is the first input, head should point to it
            if (head == nullptr) {
                head = fresh;
            } else {
                // otherwise attach it to the end of the previous node
                lastNode->next = fresh;
            }

            // advance lastNode forward to our newly added node
            lastNode = fresh;
        }
    }

    // print every value from the first node to the last
    void PrintList() {
        // check if the list is completely empty
        if (head == nullptr) {
            cout << "The list is empty.\n";
            return;
        }

        // use a local pointer to walk through the list so head stays unchanged
        node* walker = head;
        cout << "List: ";
        while (walker != nullptr) {
            cout << walker->data;
            // print an arrow between nodes as long as there is a next node
            if (walker->next != nullptr) {
                cout << " -> ";
            }
            walker = walker->next;  // step forward to the next node
        }
        cout << "\n";
    }

    // delete all nodes from heap memory and leave head as nullptr
    void ClearList() {
        node* walker = head;
        while (walker != nullptr) {
            // save the address of the next node before freeing the current one
            node* upcoming = walker->next;
            delete walker;          // free current node memory
            walker = upcoming;      // move walker to the saved upcoming node
        }
        head = nullptr;  // reset head so list is safely marked empty
    }
};

int main() {
    List numbers;

    // test 1: print list while it is still empty
    cout << "Printing before any nodes are created:\n";
    numbers.PrintList();

    // test 2: create three nodes (e.g. 10, 20, 30)
    cout << "\nNow creating three nodes (try 10, 20 and 30):\n";
    numbers.CreateThreeNodes();

    // test 3: print the list to confirm the values appear in order
    cout << "\nPrinting after creation:\n";
    numbers.PrintList();

    // test 4: clean up all memory and verify the list is empty again
    numbers.ClearList();
    cout << "\nPrinting after cleanup:\n";
    numbers.PrintList();

    return 0;
}
