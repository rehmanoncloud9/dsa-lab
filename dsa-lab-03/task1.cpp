// Name: Abdul Rehman
// Registration No: 576841
// Section: BSCS-15E

#include <iostream>
#include <string>
using namespace std;

// This is our Student structure, basically a template for student records
struct Student {
    int rollNo;
    string name;
    float marks;
};

int main() {
    Student s;  // creating one student variable

    // getting input from user
    cout << "Enter Roll Number: ";
    cin >> s.rollNo;

    cout << "Enter Full Name: ";
    getline(cin >> ws, s.name);  // using getline to capture spaces in names

    cout << "Enter Marks (0-100): ";
    cin >> s.marks;

    // displaying the details back
    cout << "\n--- Student Details ---" << endl;
    cout << "Roll No: " << s.rollNo << endl;
    cout << "Name: " << s.name << endl;
    cout << "Marks: " << s.marks << endl;

    return 0;
}