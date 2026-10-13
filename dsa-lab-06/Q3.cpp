// Name: Abdul Rehman
// Registration Number: 576841
// Section: BSCS-15E
// Task 3: Reversing a word using a stack
#include <iostream>
#include <string>
using namespace std;

const int MAX = 20;
char stackArr[MAX];
int top = -1;

void push(char c) {
    if (top == MAX - 1) {
        cout << "Stack overflow." << endl;
        return;
    }
    stackArr[++top] = c;
}

char pop() {
    if (top == -1) {
        cout << "Stack underflow." << endl;
        return '\0';
    }
    return stackArr[top--];
}

int main() {
    string word;
    cout << "Enter one word (up to 20 characters): ";
    cin >> word;

    // Check the input length before pushing
    if (word.length() > MAX) {
        cout << "Word is too long (" << word.length() << " characters). Maximum is " << MAX << "." << endl;
        return 0;
    }

    for (size_t i = 0; i < word.length(); i++)
        push(word[i]);

    cout << "Reversed: ";
    while (top != -1)
        cout << pop();
    cout << endl;
    return 0;
}
