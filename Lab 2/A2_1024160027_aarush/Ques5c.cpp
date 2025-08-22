#include <iostream>
using namespace std;

int main() {
    int n,i,j;
    cout << "Enter the size of the square matrix: ";
    cin >> n;

    int arr[n][n];
    cout << "Enter the elements of the matrix: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "Element [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> arr[i][j];
        }
    }

    cout << "The matrix is: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    int arr1[n * n]; 
    int f = 0;
    for ( i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j || j == i + 1 || j == i + 2) {
                arr1[f] = arr[i][j];
                f++;
            }
        }
    }
    cout << "Array is: ";
    for (i = 0; i < f; i++) {
        cout << arr1[i] << " ";
    }
    system("pause");
    return 0;
}