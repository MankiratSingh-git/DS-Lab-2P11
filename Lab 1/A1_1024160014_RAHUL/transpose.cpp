#include<iostream>
using namespace std;
int main()
{
    int i,j,arr[100][100],rows,cols;
    cout<<"enter the number of rows and columns for the matrix: ";
    cin>>rows >> cols;
    cout<<"enter the elemnts of the array"<<endl;
    for (i=0;i<rows;i++)
    {
        for(j=0;j<cols;j++)
        {
            cin>>arr[i][j];    
        }
    }

    for(i=0;i<rows;i++)
    {
        for (j=0;j<cols;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    cout <<"the transpose of the matrix as follows"<<endl;

    for (i=0;i<cols;i++)
    {
        for (j=0;j<rows;j++)
        {
            cout<<arr[j][i]<<" ";
        }
        cout<<endl;
    }
}