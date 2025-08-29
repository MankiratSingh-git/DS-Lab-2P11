#include <iostream>

using namespace std;

int main()
{
    int m, n;
    cout << "Enter the size of the sparse matrix: ";
    cin >> n;
    cout << "Enter the number of non zero elements: ";
    cin >> m;
    if (m > (n * n) / 2)
    {
        cout << "Number of non-zero elements cannot exceed half of the total elements in a sparse matrix." << endl;
        return 1;
    }
    int arrrow1[m], arrcolumn1[m], arrvalue1[m];
    cout << "Enter the row column and value of the non zero element of matrix 1:\n";
    for (int i = 0; i < m; i++)
    {
        cout << "Element [" << i + 1 << "]: ";
        cin >> arrrow1[i] >> arrcolumn1[i] >> arrvalue1[i];
        arrrow1[i]--;
        arrcolumn1[i]--;
        if (arrrow1[i] < 0 || arrrow1[i] > n || arrcolumn1[i] < 0 || arrcolumn1[i] > n)
        {
            cout << "Row and column indices must be between 1 and " << n << ".\n";
            return 1;
        }
    }
    cout << "The sparse matrix 1 is:\n";
    cout << "Row\tColumn\tValue\n";
    for (int i = 0; i < m; i++)
    {
        cout << arrrow1[i] + 1 << "\t" << arrcolumn1[i] + 1 << "\t" << arrvalue1[i] << endl;
    }

    int arrrow2[m], arrcolumn2[m], arrvalue2[m];
    cout << "Enter the row column and value of the non zero element of matrix 2:\n";
    for (int i = 0; i < m; i++)
    {
        cout << "Element [" << i + 1 << "]: ";
        cin >> arrrow2[i] >> arrcolumn2[i] >> arrvalue2[i];
        arrrow2[i]--;
        arrcolumn2[i]--;
        if (arrrow2[i] < 0 || arrrow2[i] > n || arrcolumn2[i] < 0 || arrcolumn2[i] > n)
        {
            cout << "Row and column indices must be between 1 and " << n<< ".\n";
            return 1;
        }
    }
    cout << "The sparse matrix 2 is:\n";
    cout << "Row\tColumn\tValue\n";
    for (int i = 0; i < m; i++)
    {
        cout << arrrow2[i] + 1 << "\t" << arrcolumn2[i] + 1 << "\t" << arrvalue2[i] + 1 << endl;
    }
    int arrrow[m], arrcolumn[m], arrvalue[m];
    int k = 0;
    for (int i = 0; i < m; i++)
    {
        bool found = false;
        for (int j = 0; j < m; j++)
        {
            if (arrrow1[i] == arrrow2[j] && arrcolumn1[i] == arrcolumn2[j])
            {
                arrrow[k] = arrrow1[i];
                arrcolumn[k] = arrcolumn1[i];
                arrvalue[k] = arrvalue1[i] + arrvalue2[j];
                found = true;
                k++;
            }
        }

        if (!found)
        {
            arrrow[k] = arrrow1[i];
            arrcolumn[k] = arrcolumn1[i];
            arrvalue[k] = arrvalue1[i];
            k++;
        }
    }
    for (int j = 0; j < m; j++)
    {
        bool exists = false;
        for (int i = 0; i < m; i++)
        {
            if (arrrow2[j] == arrrow1[i] && arrcolumn2[j] == arrcolumn1[i])
            {
                exists = true;

            }
        }
        if (!exists)
        {
            arrrow[k] = arrrow2[j];
            arrcolumn[k] = arrcolumn2[j];
            arrvalue[k] = arrvalue2[j];
            k++;
        }
    }
    cout << "Resultant matrix after addition:\n";
    cout << "Row\tColumn\tValue\n";
    for (int i = 0; i < k; i++)
    {
        cout << arrrow[i] + 1 << "\t" << arrcolumn[i] + 1 << "\t" << arrvalue[i] << endl;
    }

    system("pause");
    return 0;
}
