#include <iostream>
using namespace std;
int main() {
    int mat1[10][10], mat2[10][10], result[10][10];
    int r1, c1, r2, c2;
    cout << "enter rows and cols of first matrix: ";
    cin >> r1 >> c1;
    cout << "enter elements of first matrix: ";
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            cin >> mat1[i][j];
        }
    }
    cout << "enter rows and cols of second matrix: ";
    cin >> r2 >> c2;

    cout << "enter elements of second matrix: ";
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            cin >> mat2[i][j];
        }
    }
    if (c1 != r2) {
        cout << "multiplication not possible\n";
        return 0;
    }
    // initialize result matrix
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;
        }
    }
    // multiplication
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            for (int k = 0; k < c1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    cout << "result matrix:\n";
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}