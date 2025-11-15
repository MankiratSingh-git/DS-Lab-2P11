#include <iostream>
#include <string>
const int size_max = 20;

class Stack {
private:
    char arr[size_max];
public:
    int top = -1;

    void push(char value) {
        if (top == size_max - 1) {
            std::cout << "Stack full\n";
            return;
        }
        arr[++top] = value;
    }

    char pop() {
        if (top == -1) {
            std::cout << "Stack empty\n";
            return '\0';
        }
        return arr[top--];
    }

    char peek() {
        if (top == -1) return '\0';
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }
};
int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}
void infix_to_postfix(Stack &S, std::string expr) {
    std::string postfix;

    for (char c : expr) {

        
        if (isalnum(c)) {
            postfix += c;
        }

        
        else if (c == '(') {
            S.push(c);
        }

        
        else if (c == ')') {
            while (!S.isEmpty() && S.peek() != '(') {
                postfix += S.pop();
            }
            S.pop(); 
        }

        
        else {
            while (!S.isEmpty() && precedence(S.peek()) >= precedence(c)) {
                postfix += S.pop();
            }
            S.push(c);
        }
    }

    
    while (!S.isEmpty()) {
        postfix += S.pop();
    }

    std::cout << "Original Expression: " << expr << "\n";
    std::cout << "Postfix Expression:  " << postfix << "\n";
}
int main(){
    Stack S;
    std::string expr = "10-54+45*67";
    infix_to_postfix(S,expr);
}