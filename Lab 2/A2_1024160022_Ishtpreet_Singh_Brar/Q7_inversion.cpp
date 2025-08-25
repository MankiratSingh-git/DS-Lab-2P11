#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int A[n];
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int sum = 0; // counter for inversions

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (A[i] > A[j]) {
                sum++;
                cout << "Inversion: (" << A[i] << ", " << A[j] << ")\n";
            }
        }
    }

    cout << "Total number of inversions: " << sum << endl;

    return 0;
}
