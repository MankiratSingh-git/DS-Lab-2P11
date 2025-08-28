#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter order of square Matrix (n n) : ";
    cin >> n;

    cout << "Enter Symmetric Matrix\n";

    float array1[n][n];
    float sym[(n * (n + 1)) / 2]; // store lower triangular (incl diagonal)
    int k = 0;

    for (int i = 0; i < n; i++) {
        cout << "Row " << i + 1 << endl;
        for (int j = 0; j < n; j++) {
            cout << "Coloum " << j + 1 << " : ";
            cin >> array1[i][j];

            if (i >= j) {
                sym[k++] = array1[i][j];
            }
        }
    }

    cout << "\nStored 1D array (Symmetric lower half): ";
    for (int i = 0; i < (n * (n + 1)) / 2; i++) {
        cout << sym[i] << " ";
    }
    cout << endl;

    cout << "\nReconstructed Symmetric Matrix:\n";
    k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= j) {
                cout << sym[(i * (i + 1)) / 2 + j] << " ";
            } else {
                cout << sym[(j * (j + 1)) / 2 + i] << " "; // mirror element
            }
        }
        cout << endl;
    }

    return 0;
}
