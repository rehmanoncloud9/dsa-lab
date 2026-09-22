// Task 2
#include<iostream>
using namespace std;

int main(){
  // Delaration of variables
  int numbers[5]; // Array declaration
  int total = 0; // to store the sum

  // Reading user input into the array
  for(int i = 0; i<(sizeof(numbers))/sizeof(int);i++){
    cout<<"Enter digit at "<<i<<" index: ";
    cin>>numbers[i];
  }

  // Feeding array numbers into total
  for(int i = 0; i<(sizeof(numbers))/sizeof(int);i++){
    total = total + numbers[i];
  }

  // Displaying the output
  cout<<"Numbers you entered: ";
  for(int i = 0; i<(sizeof(numbers))/sizeof(int);i++){
        cout<<numbers[i]<<" ";
    }
  cout<<"\nTotal: "<<total;
}