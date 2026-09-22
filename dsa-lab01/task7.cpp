// Task 7
#include<iostream>
using namespace std;
int main(){
  int numbers[10];
  int uniqueCount = 0; // number of distinct values found so far

  // Reading user input into the array
  for(int i = 0; i<(sizeof(numbers))/sizeof(int);i++){
    cout<<"Enter digit at "<<i<<" index: ";
    cin>>numbers[i];
  }
  // Moving the first occurrence of each distinct value to the front
  for(int i = 0; i<(sizeof(numbers))/sizeof(int);i++){
    bool isDuplicate = false;
    for(int j = 0; j<uniqueCount; j++){
      if(numbers[j]==numbers[i]){
        isDuplicate = true;
        break;
      }
    }
    if(!isDuplicate){
      numbers[uniqueCount] = numbers[i];
      uniqueCount++;
    }
  }
  // Displaying the unique values
  cout<<"Unique values: ";
  for(int i = 0; i<uniqueCount; i++){
    cout<<numbers[i]<<" ";
  }
  cout<<"\nCount: "<<uniqueCount<<endl;

  return 0;
}
