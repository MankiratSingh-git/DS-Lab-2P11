#include <iostream>
using namespace std;

int findMissingBinary(int arr[], int n) {
    int left = 0, right = n - 2; // because array has n-1 elements

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] != mid + 1) {
            // mismatch found ? missing is in left half
            if (mid == 0 || arr[mid - 1] == mid)
                return mid + 1;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return n; // If missing is the last element
}

int main() {
    int arr[] = {1, 2, 3, 5, 6}; // Missing = 4
    int n = 6;

    cout << "Missing number (Binary Search): " << findMissingBinary(arr, n) << endl;

    return 0;
}
