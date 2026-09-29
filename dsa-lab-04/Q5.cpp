// Name: Abdul Rehman
// Registration No: 576841
// Section: BSCS-15E

#include <iostream>
using namespace std;

class List {
private:
    // node structure
    struct node {
        int data;
        node* next;
    };
    node* head;  // start of list

public:
    // constructor: initialize head to null
    List() {
        head = nullptr;
    }

    // destructor: clean up remaining nodes
    ~List() {
        ClearList();
    }

    // append a new node at the end of the list
    void AddNode(int newValue) {
        node* fresh = new node;
        fresh->data = newValue;
        fresh->next = nullptr;

        if (head == nullptr) {
            head = fresh;
            return;
        }

        node* walker = head;
        while (walker->next != nullptr) {
            walker = walker->next;
        }
        walker->next = fresh;
    }

    // remove only the first node that matches the target value
    void DeleteNode(int target) {
        // case 1: check if the list is empty
        if (head == nullptr) {
            cout << "Cannot delete " << target << ", the list is empty.\n";
            return;
        }

        // case 2: check if the target is in the very first node (head)
        if (head->data == target) {
            node* doomed = head;       // save address of node to be deleted
            head = head->next;          // shift head pointer forward to the next node
            delete doomed;              // safely free memory of the old head
            cout << "Deleted " << target << " (it was the first node).\n";
            return;
        }

        // case 3: target is further down the list; use two pointers to find and unlink it
        node* behind = head;            // trails behind candidate
        node* candidate = head->next;   // the node being checked

        while (candidate != nullptr && candidate->data != target) {
            behind = candidate;
            candidate = candidate->next;
        }

        // case 4: target was not found anywhere in the list
        if (candidate == nullptr) {
            cout << "Value " << target << " not found, nothing was deleted.\n";
            return;
        }

        // case 5: target found in middle or at the end; bypass and delete candidate
        behind->next = candidate->next;  // reconnect previous node past candidate
        delete candidate;                // free the target node
        cout << "Deleted " << target << ".\n";
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

    // delete all nodes and reset head to nullptr
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

    // test 1: attempt deletion on an empty list
    cout << "=== Delete from an empty list ===\n";
    numbers.DeleteNode(5);
    numbers.PrintList();

    // build initial list: 10 -> 20 -> 20 -> 30
    numbers.AddNode(10);
    numbers.AddNode(20);
    numbers.AddNode(20);
    numbers.AddNode(30);
    cout << "\n=== Starting list ===\n";
    numbers.PrintList();

    // test 2: delete duplicate value (only the first occurrence should be deleted)
    cout << "\n=== Delete 20 once (duplicate, only the first goes) ===\n";
    numbers.DeleteNode(20);
    numbers.PrintList();

    // test 3: delete remaining 20 (middle node deletion)
    cout << "\n=== Delete 20 again (middle node) ===\n";
    numbers.DeleteNode(20);
    numbers.PrintList();

    // test 4: attempt to delete a missing value
    cout << "\n=== Delete 99 (missing value) ===\n";
    numbers.DeleteNode(99);
    numbers.PrintList();

    // test 5: delete the head node (first node)
    cout << "\n=== Delete 10 (first node) ===\n";
    numbers.DeleteNode(10);
    numbers.PrintList();

    // test 6: append and delete the tail node (last node)
    cout << "\n=== Append 40, then delete 40 (last node) ===\n";
    numbers.AddNode(40);
    numbers.PrintList();
    numbers.DeleteNode(40);
    numbers.PrintList();

    // test 7: delete the only remaining node (list becomes empty)
    cout << "\n=== Delete 30 (the only node left) ===\n";
    numbers.DeleteNode(30);
    numbers.PrintList();

    // clean up list memory
    numbers.ClearList();
    return 0;
}
