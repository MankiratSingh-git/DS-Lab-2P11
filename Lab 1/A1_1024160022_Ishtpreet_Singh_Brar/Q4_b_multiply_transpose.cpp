#include <iostream>
using namespace std;

int main_Transpose();
int main_Multiply();

int main()
{
    char x;
    cout<<"Enter Char\nT = Transpose\nM = Multiply 2 Matrix\n";
    cin>>x;
    
    if (x == 'T'){
        main_Transpose();
    }
    else if (x == 'M')
    {
        main_Multiply();
    }
    else
    {
        cout<<"Invalid Input";
    }
}



int main_Transpose() //       Transpose matrix
{
    int i, j, a, b;
    cout<<"Enter order of Matrix{a b} :";
    cin>>a>> b;

    float array1[a][b], array1trans[b][a];

    cout<<"Enter no.'s for Matrix  \n";
    for (i = 0; i < a; i++)
    {
        cout<<"Row" <<i + 1<<endl;
        for (j = 0; j < b; j++)
        {
            cout<<"Coloum"<< j + 1<<" : ";
            cin>>array1[i][j];
        }
    }

    for (i = 0; i < a; i++)
    {
        for (j = 0; j < b; j++)
        {
            array1trans[j][i] = array1[i][j];
        }
    }
    cout<<"Matrix \n";
    for (i = 0; i < a; i++)
    {
        for (j = 0; j < b; j++)
        {
            cout<<array1[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"Matrix Trans\n";
    for (i = 0; i < b; i++)
    {
        for (j = 0; j < a; j++)
        {
            cout<<array1trans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

int main_Multiply() // { Multiply matrix} 
{
    int i, j, k, a, b, c, d;
    cout<<"Enter order of 1st Matrix{a b} :";
    cin>>a>> b;
    cout<<"Enter order of 2nd Matrix{c d} :";
    cin>>c>>d;
    if (c != b)
    {
        cout<<"Invalid Order , c!=b";
        return 0;
    }
    float array1[a][b], array2[c][d], array1Multi2[a][d], temp1 = 0, temp2 = 0;

    cout<<"Enter no.'s for Matrix 1 \n";
    for (i = 0; i < a; i++)
    {
        cout<<"Row "<<i + 1<<endl;
        for (j = 0; j < b; j++)
        {
            cout<<"Coloum "<< j + 1<<" : ";
            cin>>array1[i][j];
        }
    }
    cout<<"Enter no.'s for Matrix 2 \n";
    for (i = 0; i < c; i++)
    {
        cout<<"Row "<<endl<< i + 1;
        for (j = 0; j < d; j++)
        {
            cout<<"Coloum "<< j + 1<<" : ";
            cin>>array2[i][j];
        }
        
    }

    for (i = 0; i < a; i++)
    {
        for (j = 0; j < d; j++)
        {
            for (k = 0; k < c; k++)
            {
                temp2 = (array1[i][k] * array2[k][j]);
                temp1 = temp1 + temp2;
            }
            array1Multi2[i][j] = temp1;
            temp1 = 0;
        }
    }

    cout<<"Matrix 1 * Matrix 2\n";
    for (i = 0; i < a; i++)
    {
        for (j = 0; j < d; j++)
        {
            cout<<array1Multi2[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}