#include<iostream>
using namespace std;

int main(){
    int students, subjects;
    cout << "Enter number of students (1-10): ";
    cin>>students;
    cout<<"Enter number of subjects (1-10): ";
    cin >> subjects;
    if(students<1||students>10||subjects<1||subjects>10){
        cout<<"Invalid dimensions. Exiting."<<endl;
        return 0;
    }

    // row pointers first, then each row gets its own block
    int** grid = new int*[students];
    for(int s=0; s<students; s++) grid[s] = new int[subjects];

    for(int s=0; s<students; s++){
        for(int sub=0; sub<subjects; sub++){
            int mark;
            cout << "Enter Student "<<s+1<<" Subject "<<sub+1<<" mark (0-100): ";
            cin>>mark;
            if(mark<0 || mark>100){
                cout<<"Enter a valid mark between 0 and 100!!"<<endl;
                sub--;
                continue;
            }
            *(*(grid+s)+sub) = mark;
        }
    }

    cout<<"The matrix you entered is: "<<endl;
    for(int s=0; s<students; s++){
        for(int sub=0; sub<subjects; sub++) cout<<*(*(grid+s)+sub)<<" ";
        cout << endl;
    }

    int topTotal = 0;
    for(int sub=0; sub<subjects; sub++) topTotal += grid[0][sub];
    int topStudent = 1;

    for(int s=0; s<students; s++){
        int total=0;
        for(int sub=0; sub<subjects; sub++) total += grid[s][sub];
        cout<<"Student "<<s+1<<" total is: "<<total<<endl;
        if(total > topTotal){   // strict > so ties stick with the first student
            topTotal = total;
            topStudent = s+1;
        }
    }

    cout << "The top student is: " << topStudent << " with total " << topTotal << endl;

    for(int s=0; s<students; s++) delete[] grid[s];
    delete[] grid;
    grid = nullptr;
}
