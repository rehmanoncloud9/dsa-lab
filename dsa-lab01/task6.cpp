// Task 6
#include<iostream>
using namespace std;
int main(){
  int numbers[6];
  // Reading user input into the array
  for(int i = 0; i<(sizeof(numbers))/sizeof(int);i++){
    cout<<"Enter digit at "<<i<<" index: ";
    cin>>numbers[i];
  }

  // Displaying original array
  cout<<"Original array: ";
  for(int i = 0; i<(sizeof(numbers))/sizeof(int);i++){
    cout<<numbers[i]<<" ";
  }
  cout<<endl;

  // Reversing the array without using another array
  int start = 0;
  int end = (sizeof(numbers))/sizeof(int) - 1;

  while(start<end){
    int temp = numbers[start];
    numbers[start] = numbers[end];
    numbers[end] = temp;
    start++;
    end--;
  }

  // Displaying reversed array
  cout<<"Reversed array: ";
  for(int i = 0; i<(sizeof(numbers))/sizeof(int);i++){
    cout<<numbers[i]<<" ";
  }
  cout<<endl;

  return 0;
}
