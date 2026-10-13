// Name: Abdul Rehman
// Registration Number: 576841
// Section: BSCS-15E
// Task 4: Inserting values into a linear array queue
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

int main() {
    cout << "--- Display on empty queue ---" << endl;
    display();

    cout << "\n--- Insert 10, 20, 30 ---" << endl;
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();

    cout << "\n--- Fill the queue ---" << endl;
    enqueue(40);
    enqueue(50);
    display();

    cout << "\n--- Attempt one more insertion ---" << endl;
    enqueue(60);
    display();
    return 0;
}
