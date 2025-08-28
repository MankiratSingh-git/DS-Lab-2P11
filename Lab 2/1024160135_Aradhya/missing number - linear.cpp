#include <iostream>
using namespace std;

int findMissingLinear(int arr[], int n) {
    int total = n * (n + 1) / 2;
    int sum = 0;
    for (int i = 0; i < n - 1; i++) {
        sum += arr[i];
    }
    return total - sum;
}

int main() {
    int arr[] = {1, 2, 3, 5, 6}; // Missing = 4
    int n = 6; // Actual size should be 6

    cout << "Missing number (Linear Method): " << findMissingLinear(arr, n) << endl;

    return 0;
}
