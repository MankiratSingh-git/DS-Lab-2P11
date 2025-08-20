#include <iostream>
#include <algorithm>
using namespace std;

int countDistinctSort(int arr[], int n) {
    sort(arr, arr + n);
    int count = 1; // first element is always distinct
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[i - 1])
            count++;
    }
    return count;
}

int main() {
    int arr[] = {1, 2, 2, 3, 4, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Total distinct elements: " << countDistinctSort(arr, n) << endl;
    return 0;
}
