#include<iostream>
using namespace std;    

int main()
{
int n,i,j,arr[100][100],rows,cols;


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
for (i=0;i<rows;i++)
{
    for (j=0;j<cols;j++)
    {
        cout<<arr[i][j]<<" ";
    }
    cout<<endl;
    
}


int row_sum=0;
int col_sum=0;
for (i=0;i<rows;i++)
{
    for (int j=0;j<cols;j++)
    {
        row_sum +=arr[i][j];
    }
    cout<<"the sum of row "<<i+1<<" is "<<row_sum<<endl;
    row_sum = 0; 
}
for (i=0;i<cols;i++)
{
    for (int j=0;j<rows;j++)
    {
        col_sum +=arr[j][i];
    }
    cout<<"the sum of column "<<i+1<<" is "<<col_sum<<endl;
    col_sum = 0; 
}
return 0;
}