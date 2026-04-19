#include <bits/stdc++.h>
using namespace std;

#define MAX 100

class Stack {
    char arr[MAX];
    int top_index;
public:
    Stack() { 
        top_index = -1; 
    }
    
    void push(char val) {
        arr[++top_index] = val;
    }
    
    char pop() {
        if (top_index == -1) return '\0';
        return arr[top_index--];
    }
    
    char top() {
        if (top_index == -1) return '\0';
        return arr[top_index];
    }
    
    bool isEmpty() {
        return top_index == -1;
    }
    
    string getStackContent() {
        string s = "";
        for (int i = 0; i <= top_index; i++) {
            s += arr[i];
        }
        return s;
    }
};

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return -1;
}

void infixToPostfix(string infix) {
    Stack s;
    string postfix = "";

    cout << "\n";
    cout << left << setw(18) << "Symbol Scanned" 
         << setw(15) << "Stack" 
         << "Postfix Expression" << "\n";
    cout << "---------------------------------------------------\n";

    for (int i = 0; i < infix.length(); i++) {
        char ch = infix[i];

        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
            postfix += ch;
        }
        else if (ch == '(') {
            s.push(ch);
        }
        else if (ch == ')') {
            while (!s.isEmpty() && s.top() != '(') {
                postfix += s.pop();
            }
            s.pop(); 
        }
        else {
            while (!s.isEmpty() && precedence(ch) <= precedence(s.top())) {
                postfix += s.pop();
            }
            s.push(ch);
        }

        cout << left << setw(18) << ch 
             << setw(15) << s.getStackContent() 
             << postfix << "\n";
    }

    while (!s.isEmpty()) {
        postfix += s.pop();
        cout << left << setw(18) << "End (Pop All)" 
             << setw(15) << s.getStackContent() 
             << postfix << "\n";
    }

    cout << "---------------------------------------------------\n";
    cout << "Final Postfix Expression: " << postfix << "\n\n";
}

int main() {
    string infix;
    
    cout << "Enter Infix Expression: ";
    cin >> infix; 
    
    infixToPostfix(infix);

    return 0;
}