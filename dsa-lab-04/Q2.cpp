// Name: Abdul Rehman
// Registration No: 576841
// Section: BSCS-15E

#include <iostream>
using namespace std;

class List {
private:
    // node structure representing each element in the chain
    struct node {
        int data;
        node* next;
    };
    node* head;  // pointer to the start of the list

public:
    // initialize head to nullptr for an empty list
    List() {
        head = nullptr;
    }

    // destructor to clean up any leftover heap memory
    ~List() {
        ClearList();
    }

    // add a new node at the very end of the list
    void AddNode(int newValue) {
        // create and populate the new node on heap
        node* fresh = new node;
        fresh->data = newValue;
        fresh->next = nullptr;  // it will be the last node, so next must be null

        // if the list is empty, make this new node the head
        if (head == nullptr) {
            head = fresh;
            return;
        }

        // otherwise walk through the list until reaching the current last node
        node* walker = head;
        while (walker->next != nullptr) {
            walker = walker->next;
        }

        // link the current last node to the new node
        walker->next = fresh;
    }

    // count and return the total number of nodes currently in the list
    int CountNodes() {
        int total = 0;
        node* walker = head;

        // traverse from head to null, incrementing count at each step
        while (walker != nullptr) {
            total++;
            walker = walker->next;
        }
        return total;
    }

    // print every value from the first node to the last
    void PrintList() {
        // check for an empty list
        if (head == nullptr) {
            cout << "The list is empty.\n";
            return;
        }

        // walk through nodes and print each data value
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

    // delete all nodes and leave head as nullptr to prevent memory leaks
    void ClearList() {
        node* walker = head;
        while (walker != nullptr) {
            // save next pointer before freeing current node
            node* upcoming = walker->next;
            delete walker;
            walker = upcoming;
        }
        head = nullptr;
    }
};

int main() {
    List numbers;
    int howMany;

    // take user input for how many elements to append
    cout << "How many integers do you want to add? ";
    cin >> howMany;

    // loop to read and append each integer one by one
    for (int i = 1; i <= howMany; i++) {
        int typedValue;
        cout << "Enter integer " << i << ": ";
        cin >> typedValue;
        numbers.AddNode(typedValue);
    }

    // print the full list and the total node count
    cout << "\n";
    numbers.PrintList();
    cout << "Number of nodes: " << numbers.CountNodes() << "\n";

    // free all allocated nodes before exiting
    numbers.ClearList();
    return 0;
}
