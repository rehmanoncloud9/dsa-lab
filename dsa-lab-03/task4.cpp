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

// display function with const pointer since we're not modifying anything
void displayStudent(const Student* s) {
    if (s == nullptr) {
        cout << "No record to display." << endl;
        return;
    }
    cout << "Roll No: " << s->rollNo << endl;
    cout << "Name: " << s->name << endl;
    cout << "Marks: " << s->marks << endl;
}

// update function with regular pointer since we need to modify marks
void updateMarks(Student* s, float newMarks) {
    if (s == nullptr) {
        cout << "No record to update." << endl;
        return;
    }
    s->marks = newMarks;
    cout << "Marks updated to " << newMarks << endl;
}

int main() {
    Student* p = new Student{};

    // getting initial data
    cout << "Enter Roll Number: ";
    cin >> p->rollNo;
    cout << "Enter Full Name: ";
    getline(cin >> ws, p->name);
    cout << "Enter Marks (0-100): ";
    cin >> p->marks;

    cout << "\n--- Original Record ---" << endl;
    displayStudent(p);

    // updating marks
    float newMarks;
    cout << "\nEnter new marks: ";
    cin >> newMarks;
    updateMarks(p, newMarks);

    cout << "\n--- Updated Record ---" << endl;
    displayStudent(p);

    // releasing memory before program ends
    delete p;
    p = nullptr;

    return 0;
}