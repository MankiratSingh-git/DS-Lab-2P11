/*
Name:Bisman Singh Rai
Roll No: 1024160130
Program: Remove duplicate elements from an array so only unique elements remain
*/

#include <iostream>
using namespace std;

// REMOVE DUPLICATES
void removeDuplicates(int arr[], int &n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; ) {
            if (arr[i] == arr[j]) {
                for (int k = j; k < n - 1; k++) arr[k] = arr[k + 1];
                n--; // reduce size after deletion
            } else {
                j++; // move forward only if no deletion
            }
        }
    }
}

// DISPLAY ARRAY
void displayArray(int arr[], int n) {
    cout << "Array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";
}

int main() {
    int arr[100], n;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "\nOriginal ";
    displayArray(arr, n);

    removeDuplicates(arr, n);

    cout << "After removing duplicates ";
    displayArray(arr, n);

    return 0;
}
