#include<iostream>
using namespace std;

void missing_num(int arr[],int n)
{
    for (int i=0;i<n-1;i++)
    {
       if (arr[i]!=i+1)
       {
        cout <<"the missing number is "<<i+1;
        return;
       }
    }
     cout<<"no missing number"<<endl;
}

int main()
{
    int n=5;
    int arr[5]={1,2,3,5,6};
    missing_num(arr,n);
    return 0;
}