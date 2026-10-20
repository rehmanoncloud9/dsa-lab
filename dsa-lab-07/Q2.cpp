// Name: Abdul Rehman
// Registration No: 576841
// Section: BSCS-15E
// Lab 07, Task 2: queue using linked nodes

#include <iostream>
using namespace std;

class LinkedQueue {
private:
    // singly linked node structure
    struct node {
        int data;
        node* next;
    };

    node* front;
    node* rear;

public:
    LinkedQueue() {
        front = nullptr;
        rear = nullptr;
    }

    // clean up any remaining nodes on destruction
    ~LinkedQueue() {
        ClearQueue();
    }

    // disable copy semantics to prevent double deletion
    LinkedQueue(const LinkedQueue&) = delete;
    LinkedQueue& operator=(const LinkedQueue&) = delete;

    bool IsEmpty() const {
        return front == nullptr;
    }

    void Enqueue(int value) {
        node* n = new node;
        n->data = value;
        n->next = nullptr;

        if (rear == nullptr) {
            front = n;
            rear = n;
        } else {
            rear->next = n;  // rear directly tracks tail for O(1) insert
            rear = n;
        }
    }

    void Dequeue() {
        if (IsEmpty()) {
            cout << "Queue is empty, nothing to dequeue" << endl;
            return;
        }
        node* temp = front;
        cout << "Dequeued: " << temp->data << endl;

        front = front->next;
        if (front == nullptr) {
            rear = nullptr;  // reset rear when last node is removed
        }
        delete temp;
    }

    void Peek() const {
        if (IsEmpty()) {
            cout << "Queue is empty, nothing to peek" << endl;
            return;
        }
        cout << "Front value: " << front->data << endl;
    }

    void Display() const {
        if (IsEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue (front to rear): ";
        node* cur = front;
        while (cur != nullptr) {
            cout << cur->data << " ";
            cur = cur->next;
        }
        cout << endl;
    }

    void ClearQueue() {
        int count = 0;
        while (front != nullptr) {
            node* temp = front;
            front = front->next;
            delete temp;
            count++;
        }
        rear = nullptr;
        if (count > 0) {
            cout << "ClearQueue freed " << count << " node(s)" << endl;
        }
    }
};

int main() {
    LinkedQueue q;

    cout << "--- empty queue checks ---" << endl;
    q.Dequeue();
    q.Peek();
    q.Display();

    cout << "\n--- enqueue 10, 20, 30 ---" << endl;
    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);
    q.Display();

    cout << "\n--- dequeue once ---" << endl;
    q.Dequeue();
    q.Display();  // 20 30
    q.Peek();     // 20

    cout << "\n--- remove down to the only node ---" << endl;
    q.Dequeue();
    q.Display();  // just 30
    q.Dequeue();  // removing the only node, rear must reset too
    q.Display();
    q.Dequeue();  // empty again

    cout << "\n--- insert after it became empty ---" << endl;
    q.Enqueue(40);
    q.Enqueue(50);
    q.Display();
    q.Peek();

    cout << "\n--- cleanup before exit ---" << endl;
    q.ClearQueue();
    q.Display();

    return 0;
}
