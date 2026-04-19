
#include <bits/stdc++.h>
using namespace std;

#define MAX 50

struct Stack {
    int data[MAX];
    int top;
};

void initStack(Stack &s) {
    s.top = -1;
}
void push(Stack &s, int x) {
    if (s.top == MAX - 1) {
        cout << "Stack Overflow\n";
        return;
    }
    s.data[++s.top] = x;
}

int pop(Stack &s) {
    if (s.top == -1) {
        cout << "Stack Underflow\n";
        return -1;
    }
    return s.data[s.top--];
}

int main() {
    Stack S;
    initStack(S);

    string token;

    cout << "Enter postfix (space separated, end with =):\n";

    while (cin >> token && token != "=") {

        // If operator
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            int A = pop(S);
            int B = pop(S);

            if (token == "+") push(S, B + A);
            else if (token == "-") push(S, B - A);
            else if (token == "*") push(S, B * A);
            else if (token == "/") push(S, B / A);
        }
        // Else number
        else {
            push(S, stoi(token)); // converts string → int
        }

        // Print stack
        for (int i=0; i <= S.top;i++) {
            cout << S.data[i] << " ";
        }
        cout << endl;
    }
    cout << "VALUE = " << pop(S) << endl;

  

    return 0;
}