// Name: Abdul Rehman
// Registration Number: 576841
// Section: BSCS-15E
// Task 6: Customer service queue (linear array queue, size 5)
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
    int choice, token;
    do {
        cout << "\n===== Customer Service Queue =====" << endl;
        cout << "1. Add customer" << endl;
        cout << "2. Serve next" << endl;
        cout << "3. View next" << endl;
        cout << "4. Display queue" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter customer token number: ";
            cin >> token;
            enqueue(token);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            peekFront();
            break;
        case 4:
            display();
            break;
        case 5:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please enter a number from 1 to 5." << endl;
        }
    } while (choice != 5);
    return 0;
}
