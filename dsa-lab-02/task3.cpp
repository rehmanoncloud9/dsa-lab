#include<iostream>
using namespace std;

int main(){
    int record[2][3];
    int (*ptr)[3] = record;  // points to a row of 3, not a plain int*

    for(int branch=0; branch<2; branch++){
        for(int day=0; day<3; day++){
            int val;
            cout<<"Enter Branch "<<branch+1<<" Day "<<day+1<<" (non-negative) value: ";
            cin>>val;
            if(val<0){
                cout << "Enter non-negative value!!" << endl;
                day--;
                continue;
            }
            *(*(ptr+branch)+day) = val;
        }
    }

    cout<<"The values you entered are: "<<endl;
    for(int branch=0; branch<2; branch++){
        for(int day=0; day<3; day++)
            cout<<*(*(ptr+branch)+day)<<" ";
        cout<<endl;
    }

    // sum up each branch across its 3 days
    for(int branch=0; branch<2; branch++){
        int branchSum=0;
        for(int day=0; day<3; day++) branchSum += *(*(ptr+branch)+day);
        cout << "Branch " << branch+1 << " total is: " << branchSum << endl;
    }

    // sum up each day across both branches
    for(int day=0; day<3; day++){
        int daySum = 0;
        for(int branch=0; branch<2; branch++){
            daySum += *(*(ptr+branch)+day);
        }
        cout<<"Day "<<day+1<<" total is: "<<daySum<<endl;
    }
}
