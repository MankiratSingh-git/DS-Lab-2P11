#include <iostream>
using namespace std;

int findMissingLinear(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        if (arr[i] != i + 1) return i + 1;
    }
    return -1;
}

int main() {
    int arr[] = {1, 2, 3, 5, 6};
    int n = 5;
    cout << "Missing number (Linear): " << findMissingLinear(arr, n);
    return 0;
}
