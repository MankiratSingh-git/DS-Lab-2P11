#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter order of square Matrix (n n) : ";
    cin >> n;

    float array1[n][n];
    float tri[3 * n - 2]; // store tri-diagonal elements
    int k = 0;

    cout << "Enter no.'s for Matrix \n";
    for (int i = 0; i < n; i++) {
        cout << "Row " << i + 1 << endl;
        for (int j = 0; j < n; j++) {
            cout << "Coloum " << j + 1 << " : ";
            cin >> array1[i][j];

            if (i == j || i == j + 1 || i + 1 == j) {
                tri[k++] = array1[i][j];
            }
        }
    }

    cout << "\nStored 1D array (Tri-diagonal): ";
    for (int i = 0; i < 3 * n - 2; i++) {
        cout << tri[i] << " ";
    }
    cout << endl;

    cout << "\nReconstructed Tri-diagonal Matrix:\n";
    k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j || i == j + 1 || i + 1 == j) {
                cout << tri[k++] << " ";
            } else {
                cout << 0 << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
