#include <iostream>
using namespace std;

int main()
{
    int  a, b;
    cout << "Enter order of Matrix{a b} :";
    cin >> a >> b;

    float array1[a][b], array1trans[b][a];

    cout << "Enter no.'s for Matrix  \n";
    for (int i = 0; i < a; i++)
    {
        cout << "Row" << i + 1 << endl;
        for (int j = 0; j < b; j++)
        {
            cout << "Coloum" << j + 1 << " : ";
            cin >> array1[i][j];
        }
    }

    cout << "Matrix \n";
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            cout << array1[i][j] << " ";
        }
        cout << "\n";
    }
    
    int sum_rows[a]={},sum_column[b]={};

    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
           sum_rows[i]=sum_rows[i]+array1[i][j];
        }
    }
    for (int j = 0; j < b; j++)
    {
        for (int i = 0; i < a; i++)
        {
            sum_column[j]=sum_column[j]+array1[i][j];
        }
    }
    for (int i = 0; i < a; i++)
    {
        cout<<"Row "<<i+1<<" Sum : "<<sum_rows[i]<<endl;
    }
    for (int j = 0; j < b; j++)
    {
        cout<<"Column "<<j+1<<" Sum : "<<sum_column[j]<<endl;
    }

    return 0;
}