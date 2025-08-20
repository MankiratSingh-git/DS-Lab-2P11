/*
Name: Bisman Singh Rai
Roll No: 1024160130
Program: 
a) Reverse elements of an array
b) Matrix multiplication
c) Transpose of a matrix
*/

#include <iostream>
using namespace std;

// a) REVERSE ARRAY
void reverseArray(int arr[], int n) {
    for (int i = 0; i < n / 2; i++)
        swap(arr[i], arr[n - i - 1]);
}

// b) MATRIX MULTIPLICATION
void multiplyMatrices(int a[10][10], int b[10][10], int res[10][10], int r1, int c1, int r2, int c2) {
    if (c1 != r2) { cout << "Multiplication not possible.\n"; return; }
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++) {
            res[i][j] = 0;
            for (int k = 0; k < c1; k++)
                res[i][j] += a[i][k] * b[k][j];
        }
}

// c) TRANSPOSE MATRIX
void transposeMatrix(int mat[10][10], int rows, int cols) {
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++)
            cout << mat[j][i] << " ";
        cout << "\n";
    }
}

int main() {
    // Part a: Reverse array
    int arr[5] = {1, 2, 3, 4, 5};
    reverseArray(arr, 5);
    cout << "Reversed Array: ";
    for (int i = 0; i < 5; i++) cout << arr[i] << " ";
    cout << "\n\n";

    // Part b: Matrix multiplication
    int a[10][10] = {{1, 2}, {3, 4}};
    int b[10][10] = {{5, 6}, {7, 8}};
    int res[10][10];
    multiplyMatrices(a, b, res, 2, 2, 2, 2);
    cout << "Matrix Multiplication Result:\n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++)
            cout << res[i][j] << " ";
        cout << "\n";
    }
    cout << "\n";

    // Part c: Transpose
    cout << "Transpose of First Matrix:\n";
    transposeMatrix(a, 2, 2);

    return 0;
}
