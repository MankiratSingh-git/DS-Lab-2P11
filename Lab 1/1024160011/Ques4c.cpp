#include <iostream>
#include <vector>
using namespace std;

int main() {
    int r, c;
    cout << "Enter rows and cols of matrix: ";
    cin >> r >> c;

    vector<vector<int>> mat(r, vector<int>(c));
    cout << "Enter elements:\n";
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> mat[i][j];

    cout << "Transpose:\n";
    for (int j = 0; j < c; j++) {
        for (int i = 0; i < r; i++) {
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
