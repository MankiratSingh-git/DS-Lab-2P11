#include <iostream>
using namespace std;

int main() {
    int arr[] = {8, 4, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int inversionCount = 0;
    cout << "The array is: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                inversionCount++;
                cout << "Found an inversion: (" << arr[i] << ", " << arr[j] << ")" << endl;
            }
        }
    }
    cout << "\nTotal number of inversions: " << inversionCount << endl;
    return 0;
}
