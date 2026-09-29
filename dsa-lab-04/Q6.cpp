// Name: Abdul Rehman
// Registration No: 576841
// Section: BSCS-15E

#include <iostream>
using namespace std;

class List {
private:
    // node structure for the singly linked list
    struct node {
        int data;
        node* next;
    };
    node* head;  // pointer to the first node

public:
    // initialize head to nullptr for an empty list
    List() {
        head = nullptr;
    }

    // destructor to safely free all nodes before object is destroyed
    ~List() {
        ClearList();
    }

    // insert a new node at the front of the list in O(1) time
    void InsertAtBeginning(int newValue) {
        node* fresh = new node;
        fresh->data = newValue;
        fresh->next = head;
        head = fresh;
    }

    // append a new node at the very end of the list
    void AddNode(int newValue) {
        node* fresh = new node;
        fresh->data = newValue;
        fresh->next = nullptr;

        // if list is empty, point head directly to the fresh node
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

    // count and return the total number of nodes in the list
    int CountNodes() {
        int total = 0;
        node* walker = head;
        while (walker != nullptr) {
            total++;
            walker = walker->next;
        }
        return total;
    }

    // search for a value and print its 1-based position for the first match
    void SearchNode(int target) {
        int place = 1;
        node* walker = head;

        while (walker != nullptr) {
            if (walker->data == target) {
                cout << "Value " << target << " found at position " << place << "\n";
                return;
            }
            walker = walker->next;
            place++;
        }

        cout << "Value not found\n";
    }

    // print the second node in the list if available
    void PrintSecondNode() {
        // check if there are fewer than two nodes
        if (head == nullptr || head->next == nullptr) {
            cout << "There is no second node (fewer than two nodes in the list).\n";
            return;
        }
        cout << "Second node: " << head->next->data << "\n";
    }

    // delete only the first node holding the target value
    void DeleteNode(int target) {
        // case 1: check if list is empty
        if (head == nullptr) {
            cout << "Cannot delete " << target << ", the list is empty.\n";
            return;
        }

        // case 2: check if head node holds the target
        if (head->data == target) {
            node* doomed = head;
            head = head->next;
            delete doomed;
            cout << "Deleted " << target << " (it was the first node).\n";
            return;
        }

        // case 3: look for target in middle or tail using two pointers
        node* behind = head;
        node* candidate = head->next;
        while (candidate != nullptr && candidate->data != target) {
            behind = candidate;
            candidate = candidate->next;
        }

        // case 4: target was not found
        if (candidate == nullptr) {
            cout << "Value " << target << " not found, nothing was deleted.\n";
            return;
        }

        // case 5: unlink and delete the candidate node
        behind->next = candidate->next;
        delete candidate;
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

    // delete all nodes and leave head as nullptr
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

// print the application menu options
void ShowMenu() {
    cout << "\n===== Singly Linked List Menu =====\n";
    cout << "1. Insert at beginning\n";
    cout << "2. Insert at end\n";
    cout << "3. Search by value\n";
    cout << "4. Delete by value\n";
    cout << "5. Display all nodes\n";
    cout << "6. Count nodes\n";
    cout << "7. Display second node\n";
    cout << "8. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    List numbers;
    int choice = 0;
    int typedValue;

    // run menu loop until user chooses option 8 (Exit)
    do {
        ShowMenu();

        // handle non-numeric or broken input gracefully
        if (!(cin >> choice)) {
            cout << "\nCould not read the choice, leaving the program.\n";
            break;
        }

        switch (choice) {
        case 1:  // insert at beginning
            cout << "Enter the value to insert at the beginning: ";
            cin >> typedValue;
            numbers.InsertAtBeginning(typedValue);
            cout << "Inserted " << typedValue << " at the beginning.\n";
            break;

        case 2:  // insert at end
            cout << "Enter the value to insert at the end: ";
            cin >> typedValue;
            numbers.AddNode(typedValue);
            cout << "Inserted " << typedValue << " at the end.\n";
            break;

        case 3:  // search by value
            cout << "Enter the value to search for: ";
            cin >> typedValue;
            numbers.SearchNode(typedValue);
            break;

        case 4:  // delete by value
            cout << "Enter the value to delete: ";
            cin >> typedValue;
            numbers.DeleteNode(typedValue);
            break;

        case 5:  // display all nodes
            numbers.PrintList();
            break;

        case 6:  // count nodes
            cout << "Number of nodes: " << numbers.CountNodes() << "\n";
            break;

        case 7:  // display second node
            numbers.PrintSecondNode();
            break;

        case 8:  // exit
            cout << "Exiting...\n";
            break;

        default: // handle invalid numeric choices
            cout << "Invalid choice, please enter a number from 1 to 8.\n";
            break;
        }
    } while (choice != 8);

    // release all remaining dynamically allocated nodes before program terminates
    numbers.ClearList();
    return 0;
}
