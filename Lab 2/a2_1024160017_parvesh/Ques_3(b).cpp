#include <iostream>
using namespace std;

int findMissingBinary(int arr[], int n) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] != mid + 1) high = mid - 1;
        else low = mid + 1;
    }
    return low + 1;
}

int main() {
    int arr[] = {1, 2, 3, 5, 6};
    int n = 5;
    cout << "Missing number (Binary): " << findMissingBinary(arr, n);
    return 0;
}
