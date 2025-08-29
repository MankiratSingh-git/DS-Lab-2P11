#include <iostream>
#include <cctype>
using namespace std;

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    for (int i = 0; i < str.length(); i++) {
        str[i] = tolower(str[i]); // convert each char
    }

    cout << "Lowercase string: " << str << endl;
    return 0;
}
