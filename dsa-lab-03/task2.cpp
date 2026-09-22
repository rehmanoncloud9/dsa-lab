// Name: Abdul Rehman
// Registration No: 576841
// Section: BSCS-15E

#include <iostream>
#include <string>
using namespace std;

struct Student {
    int rollNo;
    string name;
    float marks;
};

int main() {
    Student s;
    Student* p = &s;  // p now points to our student variable

    // taking input using arrow operator since we're working with pointer
    cout << "Enter Roll Number: ";
    cin >> p->rollNo;

    cout << "Enter Full Name: ";
    getline(cin >> ws, p->name);

    cout << "Enter Marks (0-100): ";
    cin >> p->marks;

    // showing original record
    cout << "\n--- Original Record ---" << endl;
    cout << "Roll No: " << p->rollNo << endl;
    cout << "Name: " << p->name << endl;
    cout << "Marks: " << p->marks << endl;

    // updating marks
    float newMarks;
    cout << "\nEnter new marks: ";
    cin >> newMarks;
    p->marks = newMarks;  // changing through pointer

    // showing updated record
    cout << "\n--- Updated Record ---" << endl;
    cout << "Roll No: " << p->rollNo << endl;
    cout << "Name: " << p->name << endl;
    cout << "Marks: " << p->marks << endl;

    // no delete here since p points to local variable, not heap memory

    return 0;
}