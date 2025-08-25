#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter order of square Matrix (n n) : ";
    cin >> n;

    cout << "Enter Lower Triangular Matrix\n";

    float array1[n][n];
    float lower[(n * (n + 1)) / 2]; 
    int k = 0;

    for (int i = 0; i < n; i++)
    {
        cout << "Row " << i + 1 << endl;
        for (int j = 0; j < n; j++)
        {
            cout << "Coloum " << j + 1 << " : ";
            cin >> array1[i][j];

            if (i >= j)
            {
                lower[k++] = array1[i][j];
            }
        }
    }

    cout << "\nStored 1D array (Lower triangular): ";
    for (int i = 0; i < (n * (n + 1)) / 2; i++)
    {
        cout << lower[i] << " ";
    }
    cout << endl;

    cout << "\nReconstructed Lower Triangular Matrix:\n";
    k = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i >= j)
            {
                cout << lower[k++] << " ";
            }
            else
            {
                cout << 0 << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
