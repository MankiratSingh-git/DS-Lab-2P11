#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string s1 = "Hello", s2 = "World";
    
    // (a) Concatenate
    cout << "Concatenated: " << s1 + s2 << endl;

    // (b) Reverse
    reverse(s1.begin(), s1.end());
    cout << "Reversed: " << s1 << endl;

    // (c) Delete vowels
    string str = "Programming";
    string noVowels = "";
    for (char c : str) {
        if (!(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||
              c=='A'||c=='E'||c=='I'||c=='O'||c=='U')) 
            noVowels += c;
    }
    cout << "Without vowels: " << noVowels << endl;

    // (d) Sort strings
    string arr[] = {"banana","apple","mango","cherry"};
    int n = 4;
    sort(arr, arr + n);
    cout << "Sorted strings: ";
    for (string x : arr) cout << x << " ";
    cout << endl;

    // (e) Uppercase to lowercase
    char c = 'A';
    c = tolower(c);
    cout << "Lowercase: " << c << endl;

    return 0;
}
