// Name: Abdul Rehman
// Registration No: 576841
// Section: BSCS-15E
// Lab 07, Task 4: rotating service turns (CircularQueue from Task 3 + RotateTurn)

#include <iostream>
using namespace std;

const int SIZE = 5;

class CircularQueue {
private:
    int arr[SIZE];
    int front;
    int rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    bool IsEmpty() const {
        return front == -1;
    }

    bool IsFull() const {
        return (rear + 1) % SIZE == front;
    }

    void Enqueue(int value) {
        if (IsFull()) {
            cout << "Queue is full, can't insert " << value << endl;
            return;
        }
        if (IsEmpty()) {
            front = 0;
            rear = 0;
        } else {
            rear = (rear + 1) % SIZE;
        }
        arr[rear] = value;
    }

    void Dequeue() {
        if (IsEmpty()) {
            cout << "Queue is empty, nothing to dequeue" << endl;
            return;
        }
        cout << "Dequeued: " << arr[front] << endl;

        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % SIZE;
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
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) {
                break;
            }
            i = (i + 1) % SIZE;
        }
        cout << "  [front = " << front << ", rear = " << rear << "]" << endl;
    }

    // calculate total elements currently in the circular queue
    int Count() const {
        if (IsEmpty()) {
            return 0;
        }
        return (rear - front + SIZE) % SIZE + 1;
    }

    // serve the front student and re-enqueue them at the back of the queue
    void RotateTurn() {
        if (IsEmpty()) {
            cout << "No students waiting, nothing to rotate" << endl;
            return;
        }
        int id = arr[front];  // preserve ID before advancing front
        Dequeue();
        Enqueue(id);          // re-insert at rear in the newly freed slot

        cout << "Served ID: " << id << endl;
        Display();
    }
};

int main() {
    CircularQueue q;

    q.Enqueue(101);
    q.Enqueue(102);
    q.Enqueue(103);
    cout << "Starting line-up" << endl;
    q.Display();

    for (int turn = 1; turn <= 5; turn++) {
        cout << "\n--- Turn " << turn << " ---" << endl;
        q.RotateTurn();
        cout << "Students in queue: " << q.Count() << endl;
    }

    cout << "\n--- empty queue ---" << endl;
    CircularQueue emptyQ;
    emptyQ.RotateTurn();

    cout << "\n--- only one student ---" << endl;
    CircularQueue oneQ;
    oneQ.Enqueue(201);
    oneQ.RotateTurn();
    cout << "Students in queue: " << oneQ.Count() << endl;  // still 1

    return 0;
}
