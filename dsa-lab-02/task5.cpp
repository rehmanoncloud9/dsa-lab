#include<iostream>
using namespace std;

int main(){
    int total;
    cout<<"Enter number of students (1-10): ";
    cin>>total;
    if(total<1 || total>10){
        cout << "Invalid n. Exiting." << endl;
        return 0;
    }

    int* list = new int[total];
    for(int i=0; i<total; i++){
        int mark;
        cout<<"Enter mark no. "<<i+1<<": ";
        cin>>mark;
        if(mark<0||mark>100){
            cout<<"Enter a valid mark between 0 and 100!!"<<endl;
            i--;
            continue;
        }
        *(list+i) = mark;
    }

    // bigger block, copy the old marks over into it
    int* bigger = new int[total+1];
    for(int i=0; i<total; i++) *(bigger+i) = *(list+i);

    int extra;
    cout << "Enter new student's mark: ";
    cin >> extra;
    while(extra<0 || extra>100){
        cout<<"Enter a valid mark between 0 and 100!!"<<endl;
        cout<<"Enter new student's mark: ";
        cin>>extra;
    }
    *(bigger+total) = extra;

    delete[] list;      // old block gone
    list = bigger;       // list now refers to the bigger block
    total = total+1;

    cout<<"The values you entered are: ";
    for(int i=0; i<total; i++) cout<<*(list+i)<<" ";
    cout << endl;

    delete[] list;
    list = nullptr;
}
