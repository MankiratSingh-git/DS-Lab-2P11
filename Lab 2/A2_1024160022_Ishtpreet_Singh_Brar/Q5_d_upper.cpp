#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter order of square Matrix (n n) : ";
    cin >> n;

    cout << "Enter Upper Triangular Matrix\n";

    float array1[n][n];
    float upper[(n * (n + 1)) / 2]; 
    int k = 0;

    for (int i = 0; i < n; i++)
    {
        cout << "Row " << i + 1 << endl;
        for (int j = 0; j < n; j++)
        {
            cout << "Coloum " << j + 1 << " : ";
            cin >> array1[i][j];

            if (i <= j)
            {
                upper[k++] = array1[i][j];
            }
        }
    }

    cout << "\nStored 1D array (Upper triangular): ";
    for (int i = 0; i < (n * (n + 1)) / 2; i++)
    {
        cout << upper[i] << " ";
    }
    cout << endl;

    cout << "\nReconstructed Upper Triangular Matrix:\n";
    k = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i <= j)
            {
                cout << upper[k++] << " ";
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
