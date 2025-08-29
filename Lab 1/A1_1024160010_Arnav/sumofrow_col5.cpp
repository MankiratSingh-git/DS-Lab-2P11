#include <iostream>
using namespace std;
int main() {
    int mat[10][10], rows, cols;
    cout << "enter rows and columns: ";
    cin >> rows >> cols;
    cout << "enter matrix elements: ";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> mat[i][j];
        }
    }
    // row sums
    for (int i = 0; i < rows; i++) {
        int sumRow = 0;
        for (int j = 0; j < cols; j++) {
            sumRow += mat[i][j];
        }
        cout << "sum of row " << i + 1 << " = " << sumRow << "\n";
    }
    // column sums
    for (int j = 0; j < cols; j++) {
        int sumCol = 0;
        for (int i = 0; i < rows; i++) {
            sumCol += mat[i][j];
        }
        cout << "sum of col " << j + 1 << " = " << sumCol << "\n";
    }
    return 0;
}