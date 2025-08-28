#include <iostream>
using namespace std;

int main() {
    const int rows = 4, cols = 4;

    int matrix[rows][cols] = {
        {0, 0, 4, 0},
        {3, 0, 0, 0},
        {0, 5, 0, 0},
        {0, 0, 0, 7}
    };

    cout << "Original Matrix:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) cout << matrix[i][j] << " ";
        cout << "\n";
    }

    // Build triplet: [row, col, val]
    int triplet[20][3];
    int k = 1;
    triplet[0][0] = rows; triplet[0][1] = cols; triplet[0][2] = 0;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (matrix[i][j] != 0) {
                triplet[k][0] = i;
                triplet[k][1] = j;
                triplet[k][2] = matrix[i][j];
                k++; triplet[0][2]++;
            }

    cout << "\nOriginal (sparse):\n";
    for (int i = 0; i <= triplet[0][2]; i++)
        cout << triplet[i][0] << " " << triplet[i][1] << " " << triplet[i][2] << "\n";

    // Transpose triplet (column-wise scan keeps rows sorted)
    int transpose[20][3];
    transpose[0][0] = triplet[0][1];
    transpose[0][1] = triplet[0][0];
    transpose[0][2] = triplet[0][2];

    int t = 1;
    for (int col = 0; col < cols; col++)
        for (int i = 1; i <= triplet[0][2]; i++)
            if (triplet[i][1] == col) {
                transpose[t][0] = triplet[i][1];
                transpose[t][1] = triplet[i][0];
                transpose[t][2] = triplet[i][2];
                t++;
            }

    cout << "\nTranspose (sparse):\n";
    for (int i = 0; i <= transpose[0][2]; i++)
        cout << transpose[i][0] << " " << transpose[i][1] << " " << transpose[i][2] << "\n";

    // Reconstruct and print transpose as normal matrix
    int transMat[rows][cols] = {0};
    for (int i = 1; i <= transpose[0][2]; i++)
        transMat[transpose[i][0]][transpose[i][1]] = transpose[i][2];

    cout << "\nTranspose Matrix:\n";
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) cout << transMat[i][j] << " ";
        cout << "\n";
    }

    return 0;
}
