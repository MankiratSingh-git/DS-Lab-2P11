#include <iostream>
using namespace std;
int main() {
    int mat[10][10], trans[10][10];
    int rows, cols;
    cout << "enter rows and columns: ";
    cin >> rows >> cols;
    cout << "enter matrix elements: ";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> mat[i][j];
        }
    }
    // transpose operation
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            trans[j][i] = mat[i][j];
        }
    }
    cout << "transpose matrix:\n";
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            cout << trans[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}