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
    // allocating memory on heap using new
    Student* p = new Student{};

    // taking input through pointer
    cout << "Enter Roll Number: ";
    cin >> p->rollNo;

    cout << "Enter Full Name: ";
    getline(cin >> ws, p->name);

    cout << "Enter Marks (0-100): ";
    cin >> p->marks;

    // displaying the record
    cout << "\n--- Student Details ---" << endl;
    cout << "Roll No: " << p->rollNo << endl;
    cout << "Name: " << p->name << endl;
    cout << "Marks: " << p->marks << endl;

    // cleaning up heap memory
    delete p;
    p = nullptr;  // good practice to set to nullptr after delete

    return 0;
}