// Name: Abdul Rehman
// Registration No: 576841
// Section: BSCS-15E
// Lab 07, Task 3: circular queue

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

    // next position wrapping around to front indicates the queue is full
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
            rear = (rear + 1) % SIZE;  // wrap around to reuse freed front slots
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

        // traverse circularly until reaching rear
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
};

int main() {
    CircularQueue q;

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

    cout << "\n--- enqueue 60 and 70, these wrap around ---" << endl;
    q.Enqueue(60);
    q.Enqueue(70);
    q.Display();  // 30 40 50 60 70, front = 2, rear = 1
    q.Peek();

    cout << "\n--- one more insert, should be rejected ---" << endl;
    q.Enqueue(80);

    cout << "\n--- empty the queue ---" << endl;
    q.Dequeue();
    q.Dequeue();
    q.Dequeue();
    q.Dequeue();
    q.Dequeue();
    q.Display();

    cout << "\n--- dequeue and peek on empty ---" << endl;
    q.Dequeue();
    q.Peek();

    cout << "\n--- insert into the empty queue again ---" << endl;
    q.Enqueue(90);
    q.Enqueue(95);
    q.Display();

    return 0;
}
