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

// this function checks if pointer is valid before displaying
void displayIfExists(const Student* s) {
    if (s != nullptr) {
        cout << "Roll No: " << s->rollNo << endl;
        cout << "Name: " << s->name << endl;
        cout << "Marks: " << s->marks << endl;
    } else {
        cout << "No record available" << endl;
    }
}

int main() {
    Student* p = nullptr;  // starting with no record

    cout << "--- Before allocation ---" << endl;
    displayIfExists(p);  // should say no record

    // allocating and filling record
    p = new Student{};
    cout << "\nEnter Roll Number: ";
    cin >> p->rollNo;
    cout << "Enter Full Name: ";
    getline(cin >> ws, p->name);
    cout << "Enter Marks (0-100): ";
    cin >> p->marks;

    cout << "\n--- After allocation ---" << endl;
    displayIfExists(p);  // should show the record

    // deleting and resetting pointer
    delete p;
    p = nullptr;

    cout << "\n--- After deletion ---" << endl;
    displayIfExists(p);  // should say no record again

    return 0;
}