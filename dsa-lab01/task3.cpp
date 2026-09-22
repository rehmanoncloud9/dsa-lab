// Task 3
#include<iostream>
using namespace std;

// Defining the class: Student
class Student{
  public:
    // Data Members
    int rollNumber;
    int marks;
    // Member function
    void display(){
      cout<<"Roll Number: "<<rollNumber<<endl;
      cout<<"Marks: "<<marks<<endl;
    }
};

int main(){
  // Instantiating Objects of class: Student
  Student s1;
  Student s2;

  // Assigning values using dot operator
  s1.rollNumber = 1;
  s1.marks = 75;

  s2.rollNumber = 2;
  s2.marks = 90;

  // Displaying information using the display() member function
  cout<<"Before changing s1.marks:\n";
  s1.display();
  s2.display();

  // Changing only s1's marks
  s1.marks = 80;

  // s2.marks stays 90 because s1 and s2 are separate objects,
  // each with its own copy of the data members. Changing s1
  // does not touch s2's memory at all.
  cout<<"\nAfter changing s1.marks to 80:\n";
  s1.display();
  s2.display();

  return 0;
}
