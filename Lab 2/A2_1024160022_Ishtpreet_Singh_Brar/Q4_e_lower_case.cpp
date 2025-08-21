#include <iostream>
using namespace std;

int main() {
    char ch;
    cout << "Enter an uppercase character: ";
    cin >> ch;

    if (ch >= 'A' && ch <= 'Z') {
        ch = ch + ('a' - 'A');  // convert to lowercase
    }

    cout << "Lowercase: " << ch << endl;
    return 0;
}
