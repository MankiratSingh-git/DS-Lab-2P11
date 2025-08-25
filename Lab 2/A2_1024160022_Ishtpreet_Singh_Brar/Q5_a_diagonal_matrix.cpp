#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cout << "Enter order of Matrix {a b} : ";
    cin >> a >> b;

    float array1[a][b];
    float diagonal[min(a, b)];

    cout << "Enter no.'s for Matrix \n";
    for (int i = 0; i < a; i++)
    {
        cout << "Row " << i + 1 << endl;
        for (int j = 0; j < b; j++)
        {
            cout << "Coloum " << j + 1 << " : ";
            cin >> array1[i][j];
            if (i == j)
            {
                diagonal[i] = array1[i][j];
            }
        }
    }

    cout << "\nDiagonal stored in 1D array: ";
    for (int i = 0; i < min(a, b); i++)
    {
        cout << diagonal[i] << " ";
    }
    cout << endl;

    cout << "\nReconstructed Diagonal Matrix:\n";
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            if (i == j)
                cout << diagonal[i] << " ";
            else
                cout << 0 << " ";
        }
        cout << endl;
    }

    return 0;
}
