#include<iostream>
using namespace std;

int main(){
    int count = 3;
    int* data = new int[count];   // fixed loop below so this stays in bounds

    for(int i=0; i<count; i++){
        int val;
        cout << "Enter value no. " << i+1 << ": ";
        cin>>val;
        data[i] = val;
    }

    cout<<"The values you entered are: ";
    for(int i=0; i<count; i++) cout << data[i] << " ";
    cout<<endl;

    delete[] data;   // array delete, not plain delete
    data = nullptr;
}
