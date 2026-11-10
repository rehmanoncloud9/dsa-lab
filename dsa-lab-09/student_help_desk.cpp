// Name: Abdul Rehman
// Registration No: 576841
// Section: BSCS-15E

// Student Help Desk System

/*
 * Design:
 * 1) Singly linked list for students. The number of students is not fixed,
 *    and we only add at the end, search and display so a list fits well
 *    with no resizing or full check.
 * 2) Linked queue for help requests. Requests must be served in the order
 *    they arrived, which is exactly what a FIFO queue gives.
 *
 * Worst-case time complexity (n = number of students):
 *   Add student: O(n), the duplicate roll check scans the whole list.
 *   Search: O(n), the roll may be at the last node or missing.
 *
 * Alternative: a BST keyed on roll number gives O(log n) average search
 * and insert, though a sorted insert order degrades it to O(n).
 */

#include <iostream>
#include <string>
using namespace std;

struct Student {
    int roll;
    string name;
    Student* next;
};

struct Request {
    int roll;
    Request* next;
};

Student* listHead = NULL;
Student* listTail = NULL;
Request* queueFront = NULL;
Request* queueRear = NULL;

Student* findStudent(int roll) {
    Student* cur = listHead;
    while (cur != NULL) {
        if (cur->roll == roll) {
            return cur;
        }
        cur = cur->next;
    }
    return NULL;
}

bool addStudent(int roll, string name) {
    if (findStudent(roll) != NULL) {
        return false;
    }
    Student* node = new Student;
    node->roll = roll;
    node->name = name;
    node->next = NULL;

    if (listHead == NULL) {
        listHead = node;
    } else {
        listTail->next = node;
    }
    listTail = node;
    return true;
}

void showAllStudents() {
    if (listHead == NULL) {
        cout << "No students have been added yet.\n";
        return;
    }
    cout << "\nRoll No    Name\n";
    cout << "-----------------------------\n";
    for (Student* cur = listHead; cur != NULL; cur = cur->next) {
        cout << cur->roll << "\t   " << cur->name << "\n";
    }
}

void enqueueRequest(int roll) {
    Request* node = new Request;
    node->roll = roll;
    node->next = NULL;

    if (queueRear == NULL) {
        queueFront = node;
    } else {
        queueRear->next = node;
    }
    queueRear = node;
}

bool dequeueRequest(int& roll) {
    if (queueFront == NULL) {
        return false;
    }
    Request* old = queueFront;
    roll = old->roll;
    queueFront = queueFront->next;
    if (queueFront == NULL) {
        queueRear = NULL;
    }
    delete old;
    return true;
}

void showWaitingRequests() {
    if (queueFront == NULL) {
        cout << "No requests are waiting.\n";
        return;
    }
    cout << "Waiting (earliest first): ";
    for (Request* cur = queueFront; cur != NULL; cur = cur->next) {
        cout << cur->roll;
        if (cur->next != NULL) {
            cout << " -> ";
        }
    }
    cout << "\n";
}

void addStudentOption() {
    int roll;
    string name;

    cout << "Enter roll number: ";
    cin >> roll;
    cin.ignore(1000, '\n');
    cout << "Enter name: ";
    getline(cin, name);

    if (addStudent(roll, name)) {
        cout << "Student added.\n";
    } else {
        cout << "Error: roll number " << roll << " already exists.\n";
    }
}

void searchOption() {
    int roll;
    cout << "Enter roll number to search: ";
    cin >> roll;

    Student* found = findStudent(roll);
    if (found == NULL) {
        cout << "No student found with roll number " << roll << ".\n";
    } else {
        cout << "Found: " << found->roll << " - " << found->name << "\n";
    }
}

void helpDeskOption() {
    int choice;
    cout << "\n  1. Add a help request\n";
    cout << "  2. Serve the next request\n";
    cout << "  3. Show waiting requests\n";
    cout << "  Choice: ";
    cin >> choice;

    if (choice == 1) {
        int roll;
        cout << "Enter roll number asking for help: ";
        cin >> roll;
        Student* s = findStudent(roll);
        if (s == NULL) {
            cout << "Rejected: roll number " << roll << " is not registered.\n";
        } else {
            enqueueRequest(roll);
            cout << "Request added for " << s->name << ".\n";
        }
    } else if (choice == 2) {
        int roll;
        if (dequeueRequest(roll)) {
            Student* s = findStudent(roll);
            if (s != NULL) {
                cout << "Now serving: " << roll << " - " << s->name << "\n";
            } else {
                cout << "Now serving: " << roll << "\n";
            }
        } else {
            cout << "The queue is empty, nobody to serve.\n";
        }
    } else if (choice == 3) {
        showWaitingRequests();
    } else {
        cout << "Invalid choice.\n";
    }
}

void cleanUp() {
    while (listHead != NULL) {
        Student* temp = listHead;
        listHead = listHead->next;
        delete temp;
    }
    listTail = NULL;

    while (queueFront != NULL) {
        Request* temp = queueFront;
        queueFront = queueFront->next;
        delete temp;
    }
    queueRear = NULL;
}

int main() {
    int choice;

    do {
        cout << "\n===== Student Help Desk =====\n";
        cout << "1. Add a student\n";
        cout << "2. Search by roll number\n";
        cout << "3. Display all students\n";
        cout << "4. Help requests (queue)\n";
        cout << "5. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudentOption(); break;
            case 2: searchOption(); break;
            case 3: showAllStudents(); break;
            case 4: helpDeskOption(); break;
            case 5: cout << "Goodbye.\n"; break;
            default: cout << "Please pick a number from 1 to 5.\n";
        }
    } while (choice != 5);

    cleanUp();
    return 0;
}
