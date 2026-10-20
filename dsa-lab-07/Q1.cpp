// Name: Abdul Rehman
// Registration No: 576841
// Section: BSCS-15E
// Lab 07, Task 1: linear queue using an array

#include <iostream>
using namespace std;

const int SIZE = 5;

class ArrayQueue {
private:
    int arr[SIZE];
    int front;
    int rear;

public:
    ArrayQueue() {
        front = -1;
        rear = -1;
    }

    bool IsEmpty() const {
        return front == -1;
    }

    // In linear queue, rear reaching SIZE - 1 means full even if front has moved ahead
    bool IsFull() const {
        return rear == SIZE - 1;
    }

    void Enqueue(int value) {
        if (IsFull()) {
            cout << "Queue is full, can't insert " << value << endl;
            return;
        }
        if (IsEmpty()) {
            front = 0;  // set front to 0 on the first insertion
        }
        rear++;
        arr[rear] = value;
    }

    void Dequeue() {
        if (IsEmpty()) {
            cout << "Queue is empty, nothing to dequeue" << endl;
            return;
        }
        cout << "Dequeued: " << arr[front] << endl;

        if (front == rear) {
            // queue is now empty, reset pointers to start fresh
            front = -1;
            rear = -1;
        } else {
            front++;
        }
    }

    void Peek() const {
        if (IsEmpty()) {
            cout << "Queue is empty, nothing to peek" << endl;
            return;
        }
        cout << "Front value: " << arr[front] << endl;
    }

    void Display() const {
        if (IsEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue (front to rear): ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    ArrayQueue q;

    cout << "--- enqueue 10 to 50 ---" << endl;
    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);
    q.Enqueue(40);
    q.Enqueue(50);
    q.Display();

    cout << "\n--- dequeue twice ---" << endl;
    q.Dequeue();
    q.Dequeue();

    cout << "\n--- try 60, should be rejected ---" << endl;
    q.Enqueue(60);
    q.Display();  // 30 40 50
    q.Peek();

    cout << "\n--- empty the queue ---" << endl;
    q.Dequeue();
    q.Dequeue();
    q.Dequeue();
    q.Display();

    cout << "\n--- dequeue and peek on empty ---" << endl;
    q.Dequeue();
    q.Peek();

    cout << "\n--- enqueue 70, indices should have been reset ---" << endl;
    q.Enqueue(70);
    q.Display();
    q.Peek();

    return 0;
}
