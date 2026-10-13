// Name: Abdul Rehman
// Registration Number: 576841
// Section: BSCS-15E
// Task 5: Removing values from a linear array queue
#include <iostream>
using namespace std;

const int SIZE = 5;
int items[SIZE];
int front = -1;
int rear = -1;

void enqueue(int value) {
    if (rear == SIZE - 1) {
        cout << "Insertion blocked: rear is at the last index (queue is full or cannot reuse earlier spaces)." << endl;
        return;
    }
    if (front == -1) { // first insertion
        front = 0;
        rear = 0;
    } else {
        rear++;
    }
    items[rear] = value;
    cout << "Inserted " << value << endl;
}

void display() {
    if (front == -1) {
        cout << "Queue is empty." << endl;
        return;
    }
    cout << "Queue (front to rear): ";
    for (int i = front; i <= rear; i++)
        cout << items[i] << " ";
    cout << endl;
}

void dequeue() {
    if (front == -1) {
        cout << "Cannot remove: queue is empty." << endl;
        return;
    }
    cout << "Removed " << items[front] << endl;
    if (front == rear) { // last item removed, reset
        front = -1;
        rear = -1;
    } else {
        front++;
    }
}

void peekFront() {
    if (front == -1) {
        cout << "Cannot peek: queue is empty." << endl;
        return;
    }
    cout << "Front element: " << items[front] << endl;
}

int main() {
    cout << "--- Insert 10, 20, 30 ---" << endl;
    enqueue(10);
    enqueue(20);
    enqueue(30);

    cout << "\n--- Remove once, then peek and display ---" << endl;
    dequeue();
    peekFront();
    display();

    cout << "\n--- Remove all remaining items ---" << endl;
    dequeue();
    dequeue();
    display();

    cout << "\n--- Try another removal on empty queue ---" << endl;
    dequeue();
    peekFront();

    cout << "\n--- Insert 40 after reset ---" << endl;
    enqueue(40);
    peekFront();
    display();
    cout << "front = " << front << ", rear = " << rear << endl;
    return 0;
}
