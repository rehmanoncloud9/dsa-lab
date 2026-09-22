// Task 4
#include<iostream>
using namespace std;

int main(){
  // Declaration of variables
  int numbers[8]; // Array declaration
  int largest, smallest; // to store largest and smallest values
  int largestIndex = 0, smallestIndex = 0; // to store their indices
  bool reported[8] = {false}; // to avoid reporting same value twice
  bool foundDuplicate = false;

  // Reading user input into the array
  for(int i = 0; i<(sizeof(numbers))/sizeof(int);i++){
    cout<<"Enter digit at "<<i<<" index: ";
    cin>>numbers[i];
  }

  // Checking for duplicates and reporting first occurrence
  cout<<"\nDuplicate check:\n";

  for(int i = 0; i<(sizeof(numbers))/sizeof(int);i++){
    if(reported[i]) continue;

    int count = 1;
    for(int j = i+1; j<(sizeof(numbers))/sizeof(int);j++){
      if(numbers[j]==numbers[i]){
        count++;
        reported[j] = true;
      }
    }

    if(count>1){
      cout<<"Value "<<numbers[i]<<" occurs "<<count<<" times, first at index "<<i<<"\n";
      foundDuplicate = true;
    }
  }

  if(!foundDuplicate){
    cout<<"No duplicates found\n";
  }

  // Finding largest and smallest values
  largest = numbers[0];
  smallest = numbers[0];

  for(int i = 1; i<(sizeof(numbers))/sizeof(int);i++){
    if(numbers[i]>largest){
      largest = numbers[i];
      largestIndex = i;
    }
    if(numbers[i]<smallest){
      smallest = numbers[i];
      smallestIndex = i;
    }
  }

  // Displaying the output
  cout<<"\nLargest value: "<<largest<<" at index "<<largestIndex;
  cout<<"\nSmallest value: "<<smallest<<" at index "<<smallestIndex;

  return 0;
}