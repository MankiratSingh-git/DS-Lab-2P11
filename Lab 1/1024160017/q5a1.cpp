#include <iostream>
#include <vector>
using namespace std;

int main() {
    int r, c;
    cout << "Enter rows and columns: ";
    cin >> r >> c;

    vector<vector<int>> mat(r, vector<int>(c));
    cout << "Enter elements:\n";
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> mat[i][j];

  
    cout << "Sum of each row:\n";
    for (int i = 0; i < r; i++) {
        int sum = 0;
        for (int j = 0; j < c; j++)
            sum += mat[i][j];
        cout << "Row " << i + 1 << ": " << sum << "\n";
    }

    cout << "Sum of each column:\n";
    for (int j = 0; j < c; j++) {
        int sum = 0;
        for (int i = 0; i < r; i++)
            sum += mat[i][j];
        cout << "Col " << j + 1 << ": " << sum << "\n";
    }

    return 0;
}