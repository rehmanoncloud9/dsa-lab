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

    // count nodes so insertion positions can be validated
    int Size() {
        int total = 0;
        node* walker = head;
        while (walker != nullptr) {
            total++;
            walker = walker->next;
        }
        return total;
    }

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

        if (tail == nullptr) {
            head = fresh;
        } else {
            tail->next = fresh;
        }
        tail = fresh;
    }

    // insert a new node before the node at the given 1-based position
    void InsertBefore(int position, int value) {
        // only positions of existing nodes are allowed
        if (position < 1 || position > Size()) {
            cout << "Invalid position " << position << ", nothing was inserted.\n";
            return;
        }

        // walk to the node currently at that position
        node* target = head;
        for (int i = 1; i < position; i++) {
            target = target->next;
        }

        node* fresh = new node;
        fresh->data = value;
        fresh->next = target;
        fresh->prev = target->prev;

        if (target->prev == nullptr) {
            // inserting before head: the new node becomes the head
            head = fresh;
        } else {
            target->prev->next = fresh;
        }
        target->prev = fresh;

        cout << "Inserted " << value << " before position " << position << ".\n";
    }

    // delete only the first node holding the given value
    void DeleteNode(int value) {
        // case 1: list is empty
        if (head == nullptr) {
            cout << "Cannot delete " << value << ", the list is empty.\n";
            return;
        }

        // find the first matching node
        node* doomed = head;
        while (doomed != nullptr && doomed->data != value) {
            doomed = doomed->next;
        }

        // case 2: value is not in the list
        if (doomed == nullptr) {
            cout << "Value " << value << " not found, nothing was deleted.\n";
            return;
        }

        // fix the link coming from the previous side (or move head)
        if (doomed->prev == nullptr) {
            head = doomed->next;
        } else {
            doomed->prev->next = doomed->next;
        }

        // fix the link coming from the next side (or move tail)
        if (doomed->next == nullptr) {
            tail = doomed->prev;
        } else {
            doomed->next->prev = doomed->prev;
        }

        delete doomed;
        cout << "Deleted " << value << ".\n";
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

    // print values from tail to head
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
            node* upcoming = walker->next;
            delete walker;
            walker = upcoming;
        }
        head = nullptr;
        tail = nullptr;
    }
};

// print the list in both directions after every change
void ShowBoth(DoublyList& list) {
    list.PrintForward();
    list.PrintReverse();
    cout << "\n";
}

int main() {
    DoublyList numbers;

    cout << "--- Test 1: build 10, 20, 30 ---\n";
    numbers.AddNode(10);
    numbers.AddNode(20);
    numbers.AddNode(30);
    ShowBoth(numbers);

    cout << "--- Test 2: insert 15 before position 2 (expect 10, 15, 20, 30) ---\n";
    numbers.InsertBefore(2, 15);
    ShowBoth(numbers);

    cout << "--- Test 3: delete 20 (expect 10, 15, 30) ---\n";
    numbers.DeleteNode(20);
    ShowBoth(numbers);

    cout << "--- Test 4: invalid positions must not change the list ---\n";
    numbers.InsertBefore(0, 99);
    numbers.InsertBefore(4, 99);
    numbers.InsertBefore(-3, 99);
    ShowBoth(numbers);

    cout << "--- Test 5: insert before head (position 1) ---\n";
    numbers.InsertBefore(1, 5);
    ShowBoth(numbers);

    cout << "--- Test 6: delete the head (5) ---\n";
    numbers.DeleteNode(5);
    ShowBoth(numbers);

    cout << "--- Test 7: delete the tail (30) ---\n";
    numbers.DeleteNode(30);
    ShowBoth(numbers);

    cout << "--- Test 8: delete a value that is missing (99) ---\n";
    numbers.DeleteNode(99);
    ShowBoth(numbers);

    cout << "--- Test 9: delete until only one node remains, then delete it ---\n";
    numbers.DeleteNode(10);
    ShowBoth(numbers);
    numbers.DeleteNode(15);
    ShowBoth(numbers);

    cout << "--- Test 10: empty list operations ---\n";
    numbers.DeleteNode(15);
    numbers.InsertBefore(1, 7);
    ShowBoth(numbers);

    // release all nodes before the program terminates
    numbers.ClearList();
    return 0;
}
