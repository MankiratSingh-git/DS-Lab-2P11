#include <iostream>
#include <string>
const int size_max = 20;

class Stack {
public:
    int arr[size_max];
    int top = -1;

    void push(int value) {
        if (isFull()) {
            std::cout << "Stack is full\n";
            return;
        }
        arr[++top] = value;
    }

    int pop() {
        if (isEmpty()) {
            std::cout << "Stack is Empty\n";
            return 0;
        }
        return arr[top--];
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == size_max - 1;
    }
};

void Postfix_Eval(Stack &S, std::string expr) {

    for (char c : expr) {

        if (isdigit(c)) {
            S.push(c - '0');   // convert char digit to int
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/') {

            int first = S.pop();     // right operand
            int second = S.pop();    // left operand
            int result = 0;

            switch(c) {
                case '+': result = second + first; break;
                case '-': result = second - first; break;
                case '*': result = second * first; break;
                case '/': result = second / first; break;
            }

            S.push(result);
        }
    }

    std::cout << "Result = " << S.pop() << "\n";
}
int main(){
    Stack S;
    std::string expr = "1245-+*";
    Postfix_Eval(S,expr);
}