#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> s;
    int choice, value;
    const int MAX = 7;  
    int count = 0;      

    do {
        cout << "\n--- Menu ---\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek (Top)\n";
        cout << "4. isEmpty\n";
        cout << "5. isFull\n";
        cout << "6. Display (top to bottom)\n";
        cout << "0. Exit\n";
        cout << "Enter : ";
        cin >> choice;

        switch (choice) {
        case 1: 
            if (count == MAX) {
                cout << "Stack is Full! Cannot push.\n";
            } else {
                cout << "Enter value to push: ";
                cin >> value;
                s.push(value);
                count++;
                cout << value << " pushed into stack.\n";
            }
            break;

        case 2: 
            if (s.empty()) {
                cout << "Stack is empty! Cannot pop.\n";
            } else {
                cout << s.top() << " popped from stack.\n";
                s.pop();
                count--;
            }
            break;

        case 3: 
            if (s.empty()) {
                cout << "Stack is empty.\n";
            } else {
                cout << "Top element: " << s.top() << endl;
            }
            break;

        case 4: 
            if (s.empty())
                cout << "Stack is Empty\n";
            else
                cout << "Stack is not Empty\n";
            break;

        case 5: 
            if (count == MAX)
                cout << "Stack is Full\n";
            else
                cout << "Stack is not Full\n";
            break;

        case 6: // Display
            if (s.empty()) {
                cout << "Stack is empty.\n";
            } else {
                cout << "Stack elements (top to bottom): ";
                stack<int> temp = s; // copy stack
                while (!temp.empty()) {
                    cout << temp.top() << " ";
                    temp.pop();
                }
                cout << endl;
            }
            break;

        case 0:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 0);

    return 0;
}
