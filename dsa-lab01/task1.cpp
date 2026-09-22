// Task 1 
#include<iostream>
using namespace std;

int main(){
    int numbers[] = {2,4,6,8,10}; // Array Declaration and Initialization

    // Displaying the array before the change

    cout<<"Array before the change: "<<endl;
    for(int i = 0; i<(sizeof(numbers))/sizeof(int);i++){
        cout<<numbers[i]<<" ";  // Output: 2 4 6 8 10
    }
    cout<<endl;

    numbers[2] = 7; // Changed third element (Index: 2) to 7

    // Displaying the array

    cout<<"Array after the change: "<<endl;
    for(int i = 0; i<(sizeof(numbers))/sizeof(int);i++){
        cout<<numbers[i]<<" ";  // Output: 2 4 7 8 10
    }

    return 0;
}