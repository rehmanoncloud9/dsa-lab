// Name: Abdul Rehman
// Registration No: 576841
// Section: BSCS-15E

#include <iostream>
using namespace std;

class List {
private:
    // node representation for list elements
    struct node {
        int data;
        node* next;
    };
    node* head;  // start of our list

public:
    // start with an empty list
    List() {
        head = nullptr;
    }

    // destructor for memory cleanup
    ~List() {
        ClearList();
    }

    // add a new node at the end of the list
    void AddNode(int newValue) {
        node* fresh = new node;
        fresh->data = newValue;
        fresh->next = nullptr;

        // if list is currently empty, point head directly to fresh node
        if (head == nullptr) {
            head = fresh;
            return;
        }

        // move to the last node
        node* walker = head;
        while (walker->next != nullptr) {
            walker = walker->next;
        }
        walker->next = fresh;
    }

    // search for a value and print its 1-based position upon first match
    void SearchNode(int target) {
        int place = 1;  // start position counting at 1
        node* walker = head;

        // traverse through the list looking for a match
        while (walker != nullptr) {
            if (walker->data == target) {
                cout << "Value " << target << " found at position " << place << "\n";
                return;  // stop searching after finding the first occurrence
            }
            walker = walker->next;
            place++;  // increment position tracker
        }

        // if we reach null without a match, print not found message
        cout << "Value not found\n";
    }

    // print only the second node in the list with safety checks
    void PrintSecondNode() {
        // check if list is empty or only has one node
        if (head == nullptr || head->next == nullptr) {
            cout << "There is no second node (fewer than two nodes in the list).\n";
            return;
        }
        // safely print the data of the second node
        cout << "Second node: " << head->next->data << "\n";
    }

    // print all values from head to end
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

    // delete every node and set head to nullptr
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

    // test case 1: test behavior on an empty list
    cout << "=== Test 1: empty list ===\n";
    numbers.PrintList();
    numbers.PrintSecondNode();
    numbers.SearchNode(20);

    // test case 2: test behavior on a single-node list
    cout << "\n=== Test 2: one-node list ===\n";
    numbers.AddNode(10);
    numbers.PrintList();
    numbers.PrintSecondNode();
    numbers.SearchNode(20);

    // test case 3: test list with multiple nodes and duplicate values (10, 20, 30, 20)
    cout << "\n=== Test 3: list 10, 20, 30, 20 ===\n";
    numbers.AddNode(20);
    numbers.AddNode(30);
    numbers.AddNode(20);
    numbers.PrintList();
    numbers.PrintSecondNode();

    // search for value 20 (expect position 2 for first match)
    cout << "Searching for 20 (expect position 2):\n";
    numbers.SearchNode(20);

    // search for value 99 (expect not found)
    cout << "Searching for 99 (expect not found):\n";
    numbers.SearchNode(99);

    // clean up list memory
    numbers.ClearList();
    return 0;
}
