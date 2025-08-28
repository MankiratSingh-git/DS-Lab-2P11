#include<iostream>
#include<string>
#include<cctype>
using namespace std;

static const int MAX = 100;

int precedence(char op) {
    if (op == '^')              return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return -1;
}

bool isRight(char op) {
    return (op == '^');
}

class Stack {
    int top = -1;
    char arr[MAX];

public:
    char pop() {
        if (top == -1) return -1;
        return arr[top--];
    }

    void push(char n) {
        if (top < MAX-1) arr[++top] = n;
    }

    char peek() {
        if (top == -1) return -1;
        return arr[top];
    }

    bool isEmpty() { return (top == -1); }
};

int main() {
    Stack temp;
    string eqn = "(a+b)*(c^(d+e))";
    string output = "";

    for (char c : eqn) {

        if (isalnum(c)) {
            output += c;
        }

        else if (c == '(') {
            temp.push(c);
        }

        else if (c == ')') {
            while (!temp.isEmpty() && temp.peek() != '(') {
                output += temp.pop();
            }
            if (!temp.isEmpty() && temp.peek() == '(') temp.pop();
        }
 
        else if (c=='+'||c=='-'||c=='*'||c=='/'||c=='^') {
            while (!temp.isEmpty() &&
                   ((precedence(temp.peek()) > precedence(c)) ||
                   (precedence(temp.peek()) == precedence(c) && !isRight(c))) &&
                   temp.peek() != '(') {
                output += temp.pop();
            }
            temp.push(c);
        }
    }

    while (!temp.isEmpty()) {
        output += temp.pop();
    }

    cout << output << endl;
    return 0;
}
