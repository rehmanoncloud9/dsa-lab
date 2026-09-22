#include<iostream>
using namespace std;

int main(){
  int sales[5];
  int *p = sales;
  for(int idx=0; idx<5; idx++){
    int val;
    cout << "Enter (non-negative) value no. " << idx << " index: ";
    cin >> val;
    if(val < 0){
        cout<<"Enter non-negative value!!"<<endl;
        idx--;
        continue;
    }
    *(p+idx) = val;
  }

  cout << "The values you entered are: "; // Showing the entered values
  for(int idx=0; idx<5; idx++)
    cout<<*(p+idx)<<" ";

  int sum = 0;
  for(int idx=0; idx<5; idx++) sum += *(p+idx);
  cout << "The total is: " << sum;

  // Adding 2 to third day value
  *(p+2) += 2;

  cout << "\nValue after adding 3 to third day's value: ";
  for(int idx=0; idx<5; idx++)
    cout << *(p+idx) << " ";

  int newSum = 0;
  for(int idx=0; idx<5; idx++){
    newSum += *(p+idx);
  }
  cout<<"The updated total is: "<<newSum<<endl;
}
