// Name: Abdul Rehman
// Registration No: 576841
// Section: BSCS-15E
// Lab 07, Task 5: deque using a circular array

#include <iostream>
using namespace std;

const int SIZE = 5;

class ArrayDeque {
private:
    int arr[SIZE];
    int front;
    int rear;

public:
    ArrayDeque() {
        front = -1;
        rear = -1;
    }

    bool IsEmpty() const {
        return front == -1;
    }

    bool IsFull() const {
        return (rear + 1) % SIZE == front;
    }

    void InsertFront(int value) {
        if (IsFull()) {
            cout << "Deque is full, can't insert " << value << " at front" << endl;
            return;
        }
        if (IsEmpty()) {
            front = 0;
            rear = 0;
        } else {
            front = (front + SIZE - 1) % SIZE;  // +SIZE prevents negative modulo in C++
        }
        arr[front] = value;
    }

    void InsertRear(int value) {
        if (IsFull()) {
            cout << "Deque is full, can't insert " << value << " at rear" << endl;
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

    void DeleteFront() {
        if (IsEmpty()) {
            cout << "Deque is empty, can't delete from front" << endl;
            return;
        }
        cout << "Deleted from front: " << arr[front] << endl;

        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
    }

    void DeleteRear() {
        if (IsEmpty()) {
            cout << "Deque is empty, can't delete from rear" << endl;
            return;
        }
        cout << "Deleted from rear: " << arr[rear] << endl;

        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            rear = (rear + SIZE - 1) % SIZE;
        }
    }

    void Display() const {
        if (IsEmpty()) {
            cout << "Deque is empty" << endl;
            return;
        }
        cout << "Deque (front to rear): ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) {
                break;
            }
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
};

int main() {
    ArrayDeque d;

    cout << "--- 20 at rear, 10 at front, 30 at rear ---" << endl;
    d.InsertRear(20);
    d.InsertFront(10);
    d.InsertRear(30);
    d.Display();  // 10 20 30

    cout << "\n--- delete rear, then front ---" << endl;
    d.DeleteRear();
    d.DeleteFront();
    d.Display();  // 20

    cout << "\n--- 5 at front, 30 and 40 at rear, 1 at front ---" << endl;
    d.InsertFront(5);
    d.InsertRear(30);
    d.InsertRear(40);
    d.InsertFront(1);
    d.Display();  // 1 5 20 30 40

    cout << "\n--- full now, both ends should reject ---" << endl;
    d.InsertFront(99);
    d.InsertRear(99);
    d.Display();

    // the next two blocks use fresh deques, so each one is its own run
    cout << "\n--- run A: only value, delete from front ---" << endl;
    ArrayDeque a;
    a.InsertRear(7);
    a.DeleteFront();
    a.Display();
    a.DeleteFront();
    a.DeleteRear();

    cout << "\n--- run B: only value, delete from rear ---" << endl;
    ArrayDeque b;
    b.InsertFront(8);
    b.DeleteRear();
    b.Display();
    b.DeleteRear();
    b.DeleteFront();

    cout << "\n--- reuse after emptying (indices were reset) ---" << endl;
    b.InsertRear(9);
    b.Display();

    return 0;
}
