#include <iostream>
#include <vector> 
using namespace std;

int main() {
    char ch;
    int rows, columns;
    while (true) {
        cout << "Enter the size of the matrix : ";
        cin >> rows >> ch >> columns;
        if (rows != columns) {
            cout << "Error: The matrix must be a square matrix!" << endl;
            continue; 
        }
        int size = (rows * (rows + 1)) / 2;
        vector<int> upperTriangular(size);
        cout << "Enter " << size << " upper triangular elements in order: ";
        for (int i = 0; i < size; i++) {
            cin >> upperTriangular[i];
        }
        cout << "\nThe reconstructed Upper Triangular Matrix is:" << endl;
        int k = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (i <= j) {
                    cout << upperTriangular[k] << "\t";
                    k++;
                } else {
                    cout << "0\t";
                }
            }
            cout << endl;
        }
        break;
    }
    return 0;
}