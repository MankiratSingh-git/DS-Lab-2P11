#include <iostream>
using namespace std;

int main() {
    int arr[] = {10, 30, 10, 50, 20, 10, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    int distinctCount = 0;
    cout << "The array is: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        bool isFoundBefore = false;
        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                isFoundBefore = true;
                break; 
            }
        }
        if (!isFoundBefore) {
            distinctCount++;
        }
    }
    cout << "\nTotal number of distinct elements: " << distinctCount << endl;
    return 0;
}
