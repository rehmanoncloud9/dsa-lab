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
            fresh->next = fresh;
            head = fresh;
        } else {
            fresh->next = head;
            tail->next = fresh;
        }
        tail = fresh;
    }

    // delete only the first node holding the given value
    void DeleteNode(int value) {
        // case 1: list is empty
        if (head == nullptr) {
            cout << "Cannot delete " << value << ", the list is empty.\n";
            return;
        }

        // search for the value, stopping after one complete cycle
        node* before = tail;   // node just behind the one being checked
        node* current = head;
        bool found = false;
        do {
            if (current->data == value) {
                found = true;
                break;
            }
            before = current;
            current = current->next;
        } while (current != head);

        // case 2: value is not in the list
        if (!found) {
            cout << "Value " << value << " not found, nothing was deleted.\n";
            return;
        }

        if (head == tail) {
            // case 3: the only node, list becomes empty
            delete current;
            head = nullptr;
            tail = nullptr;
        } else if (current == head) {
            // case 4: deleting head, tail must now point to the new head
            head = head->next;
            tail->next = head;
            delete current;
        } else if (current == tail) {
            // case 5: deleting tail, the node before it becomes the new tail
            before->next = head;
            tail = before;
            delete current;
        } else {
            // case 6: deleting a middle node
            before->next = current->next;
            delete current;
        }

        cout << "Deleted " << value << ".\n";
    }

    // print every value exactly once, stopping after one complete cycle
    void PrintList() {
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
        } while (walker != head);
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

    // true only when both head and tail are nullptr
    bool IsEmpty() {
        return head == nullptr && tail == nullptr;
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
            node* upcoming = walker->next;
            delete walker;
            walker = upcoming;
        }
        head = nullptr;
        tail = nullptr;
    }
};

// show the list and its count after an operation
void Show(CircularList& list) {
    list.PrintList();
    cout << "Count: " << list.CountNodes() << "\n\n";
}

int main() {
    CircularList numbers;

    cout << "--- Test 1: delete from an empty list ---\n";
    numbers.DeleteNode(10);
    Show(numbers);

    cout << "--- Test 2: build 10, 20, 30 ---\n";
    numbers.AddNode(10);
    numbers.AddNode(20);
    numbers.AddNode(30);
    Show(numbers);

    cout << "--- Test 3: delete a missing value (99) ---\n";
    numbers.DeleteNode(99);
    Show(numbers);

    cout << "--- Test 4: delete head (10) ---\n";
    numbers.DeleteNode(10);
    Show(numbers);

    cout << "--- Test 5: delete tail (30) ---\n";
    numbers.DeleteNode(30);
    Show(numbers);

    cout << "--- Test 6: delete the only node (20) ---\n";
    numbers.DeleteNode(20);
    Show(numbers);
    cout << "Head and tail are both nullptr: " << (numbers.IsEmpty() ? "yes" : "no") << "\n\n";

    cout << "--- Test 7: duplicates, build 10, 20, 20, 30 and delete 20 once ---\n";
    numbers.AddNode(10);
    numbers.AddNode(20);
    numbers.AddNode(20);
    numbers.AddNode(30);
    Show(numbers);
    numbers.DeleteNode(20);
    Show(numbers);

    cout << "--- Test 8: delete a middle node (20) ---\n";
    numbers.DeleteNode(20);
    Show(numbers);

    // release all remaining nodes before the program terminates
    numbers.ClearList();
    return 0;
}
