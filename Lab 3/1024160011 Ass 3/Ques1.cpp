#include <iostream>
using namespace std;


class Stack {
    int arr[5];
    int top;
public:
    Stack() { top = -1; }

    void push(int x) {
        if (isFull()) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = x;
        cout << x << " pushed into stack\n";
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return;
        }
        cout << arr[top--] << " popped from stack\n";
    }

    bool isEmpty() { return top == -1; }
    bool isFull() { return top == 4; }

    void display() {
        if (isEmpty()) {
            cout << "Stack is Empty\n";
            return;
        }
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--)
            cout << arr[i] << " ";
        cout << endl;
    }

    void peek() {
        if (isEmpty()) cout << "Stack is Empty\n";
        else cout << "Top element: " << arr[top] << endl;
    }
};

int main() {
    Stack s;
    int choice, val;

    do {
        cout << "\n--- Menu ---\n";
        cout << "1. Push\n2. Pop\n3. isEmpty\n4. isFull\n5. Display\n6. Peek\n7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1: cout << "Enter value: "; cin >> val; s.push(val); break;
            case 2: s.pop(); break;
            case 3: cout << (s.isEmpty() ? "Stack is Empty\n" : "Stack is not Empty\n"); break;
            case 4: cout << (s.isFull() ? "Stack is Full\n" : "Stack is not Full\n"); break;
            case 5: s.display(); break;
            case 6: s.peek(); break;
        }
    } while(choice != 7);

    return 0;
}
