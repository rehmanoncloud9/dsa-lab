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

// reusing display function from earlier tasks
void displayStudent(const Student* s) {
    if (s == nullptr) {
        cout << "No record available." << endl;
        return;
    }
    cout << "Roll No: " << s->rollNo << endl;
    cout << "Name: " << s->name << endl;
    cout << "Marks: " << s->marks << endl;
}

// reusing update function from earlier tasks
void updateMarks(Student* s, float newMarks) {
    if (s == nullptr) {
        cout << "No record to update." << endl;
        return;
    }
    s->marks = newMarks;
    cout << "Marks updated successfully." << endl;
}

int main() {
    Student* p = nullptr;  // only managing one record at a time
    int choice;

    // menu loop runs until user chooses to exit
    do {
        cout << "\n===== Student Record Menu =====" << endl;
        cout << "1. Create Record" << endl;
        cout << "2. Display Record" << endl;
        cout << "3. Update Marks" << endl;
        cout << "4. Delete Record" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:  // create new record
                if (p != nullptr) {
                    cout << "A record already exists. Delete it first." << endl;
                } else {
                    p = new Student{};
                    cout << "Enter Roll Number: ";
                    cin >> p->rollNo;
                    cout << "Enter Full Name: ";
                    getline(cin >> ws, p->name);
                    cout << "Enter Marks (0-100): ";
                    cin >> p->marks;
                    cout << "Record created successfully." << endl;
                }
                break;

            case 2:  // display current record
                displayStudent(p);
                break;

            case 3:  // update marks
                if (p == nullptr) {
                    cout << "No record available to update." << endl;
                } else {
                    float newMarks;
                    cout << "Enter new marks (0-100): ";
                    cin >> newMarks;
                    updateMarks(p, newMarks);
                }
                break;

            case 4:  // delete record
                if (p == nullptr) {
                    cout << "No record to delete." << endl;
                } else {
                    delete p;
                    p = nullptr;
                    cout << "Record deleted successfully." << endl;
                }
                break;

            case 5:  // exit program
                if (p != nullptr) {
                    delete p;
                    p = nullptr;
                    cout << "Remaining record cleaned up." << endl;
                }
                cout << "Exiting program. Goodbye!" << endl;
                break;

            default:  // invalid choice
                cout << "Invalid choice. Please enter 1-5." << endl;
                break;
        }
    } while (choice != 5);

    return 0;
}