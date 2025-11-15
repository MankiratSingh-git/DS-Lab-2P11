//with stl
#include <iostream>
#include <vector>
#include <algorithm>  

using namespace std;

int main() {
    int n;
    cout << "Enter number of strings: ";
    cin >> n;

    vector<string> words(n);

    cout << "Enter " << n << " strings:\n";
    for (int i = 0; i < n; ++i) {
        cin >> words[i];
    }

    // Sort in alphabetical order
    sort(words.begin(), words.end());

    cout << "\nStrings in alphabetical order:\n";
    for (const string& word : words) {
        cout << word << endl;
    }

    return 0;
}

// without stl
#include <iostream>
#include <string.h>  // using this for strcmp and strcpy

using namespace std;

int main() {
    int n;
    cout << "Enter number of strings: ";
    cin >> n;

    char str[n][100]; 

    cout << "Enter " << n << " strings:\n";
    for (int i = 0; i < n; i++) {
        cin >> str[i];
    }

    
    char temp[100];
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(str[i], str[j]) > 0) {
                strcpy(temp, str[i]);
                strcpy(str[i], str[j]);
                strcpy(str[j], temp);
            }
        }
    }

    cout << "\nStrings in alphabetical order:\n";
    for (int i = 0; i < n; i++) {
        cout << str[i] << endl;
    }

    return 0;
}
