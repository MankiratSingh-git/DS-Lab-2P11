#include <iostream>
#include <string>
using namespace std;

int main() {
    string myString = "Naman Arora";
    string newString = "";
    cout << "Original string: " << myString << endl;
    for (int i = 0; i < myString.length(); i++) {
        char c = myString[i];
        if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u' &&
            c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U') 
        {
            newString += c;
        }
    }
    cout << "String without vowels: " << newString << endl;
    return 0;
}
