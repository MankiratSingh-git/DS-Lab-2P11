#include<iostream>
using namespace std;

void concatenate(string s1, string s2) {
    string s3; 
    for (int i = 0; i < s1.length(); i++) {
        s3 += s1[i]; 
    }
    for (int j = 0; j < s2.length(); j++) {
        s3 += s2[j]; 
    }
    cout << s3 << endl;
}

int main() { 
    string s1 = "Naman"; 
    string s2 = " Arora";
    concatenate(s1, s2);
    return 0;
}