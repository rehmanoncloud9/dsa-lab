// Name: Abdul Rehman
// Registration No: 576841
// Section: BSCS-15E
// Lab 07, Task 6: deque using doubly linked nodes (menu driven)

#include <iostream>
using namespace std;

class LinkedDeque {
private:
    struct node {
        int data;
        node* next;
        node* prev;
    };

    node* front;
    node* rear;

    bool IsEmpty() const {
        return front == nullptr;
    }

public:
    LinkedDeque() {
        front = nullptr;
        rear = nullptr;
    }

    // destructor ensures heap cleanup upon exit
    ~LinkedDeque() {
        ClearDeque();
    }

    // prevent shallow copies
    LinkedDeque(const LinkedDeque&) = delete;
    LinkedDeque& operator=(const LinkedDeque&) = delete;

    void InsertFront(int value) {
        node* n = new node;
        n->data = value;
        n->next = front;
        n->prev = nullptr;

        if (IsEmpty()) {
            rear = n;  // first node is both front and rear
        } else {
            front->prev = n;
        }
        front = n;
    }

    void InsertRear(int value) {
        node* n = new node;
        n->data = value;
        n->next = nullptr;
        n->prev = rear;

        if (IsEmpty()) {
            front = n;
        } else {
            rear->next = n;
        }
        rear = n;
    }

    void DeleteFront() {
        if (IsEmpty()) {
            cout << "Deque is empty, can't delete from front" << endl;
            return;
        }
        node* temp = front;
        cout << "Deleted from front: " << temp->data << endl;

        front = front->next;
        if (front == nullptr) {
            rear = nullptr;  // last remaining node was removed
        } else {
            front->prev = nullptr;  // detach backward pointer to deallocated node
        }
        delete temp;
    }

    void DeleteRear() {
        if (IsEmpty()) {
            cout << "Deque is empty, can't delete from rear" << endl;
            return;
        }
        node* temp = rear;
        cout << "Deleted from rear: " << temp->data << endl;

        rear = rear->prev;
        if (rear == nullptr) {
            front = nullptr;
        } else {
            rear->next = nullptr;
        }
        delete temp;
    }

    void Display() const {
        if (IsEmpty()) {
            cout << "Deque is empty" << endl;
            return;
        }
        cout << "Deque (front to rear): ";
        node* cur = front;
        while (cur != nullptr) {
            cout << cur->data << " ";
            cur = cur->next;
        }
        cout << endl;
    }

    void ClearDeque() {
        int count = 0;
        while (front != nullptr) {
            node* temp = front;
            front = front->next;
            delete temp;
            count++;
        }
        rear = nullptr;
        if (count > 0) {
            cout << "ClearDeque freed " << count << " node(s)" << endl;
        }
    }
};

void ShowMenu() {
    cout << "\n===== Linked Deque Menu =====" << endl;
    cout << "1. Insert at front" << endl;
    cout << "2. Insert at rear" << endl;
    cout << "3. Delete from front" << endl;
    cout << "4. Delete from rear" << endl;
    cout << "5. Display" << endl;
    cout << "6. Exit" << endl;
    cout << "Enter choice: ";
}

int main() {
    LinkedDeque d;
    int choice = 0;
    int value;

    do {
        ShowMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            d.InsertFront(value);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> value;
            d.InsertRear(value);
            break;
        case 3:
            d.DeleteFront();
            break;
        case 4:
            d.DeleteRear();
            break;
        case 5:
            d.Display();
            break;
        case 6:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice, pick a number from 1 to 6" << endl;
        }
    } while (choice != 6);

    d.ClearDeque();  // frees anything still left when the user quits
    return 0;
}
