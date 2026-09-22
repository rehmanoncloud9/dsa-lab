#include<iostream>
using namespace std;

int main(){
    int count;
    cout<<"Enter number of students (1-10): ";
    cin>>count;
    if(count<1 || count>10){
        cout << "Invalid n. Exiting." << endl;
        return 0;
    }

    int* scores = new int[count];
    for(int s=0; s<count; s++){
        int mark;
        cout<<"Enter mark (0-100) no. "<<s+1<<": ";
        cin>>mark;
        while(mark<0 || mark>100){
            cout << "Enter a valid mark between 0 and 100!!" << endl;
            cout<<"Enter mark (0-100) no. "<<s+1<<": ";
            cin>>mark;
        }
        *(scores+s) = mark;
    }

    cout << "Marks: ";
    for(int s=0; s<count; s++) cout<<*(scores+s)<<" ";
    cout<<endl;

    int sum=0, passed=0;
    for(int s=0; s<count; s++){
        sum += *(scores+s);
        if(*(scores+s)>=50) passed++;
    }
    double average = (double)sum / count; // dont want to lose the decimal here

    cout<<"The total is: "<<sum<<endl;
    cout << "The average is: " << average << endl;
    cout<<"The pass count is: "<<passed<<endl;

    delete[] scores;
    scores = nullptr;
}
