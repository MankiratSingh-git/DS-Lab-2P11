#include<iostream>
using namespace std;

void sortArray(int arr[],int n)
{
    int temp=0;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}


void distinctNumbers (int arr[],int n)
{
    sortArray(arr,n);
    int count=1;
   
        for (int j=0;j<n-1;j++)
        {
            if (arr[j] != arr[j+1])
            {
                
                count++;
            }
        }
    
    cout<<"the number of distinct numbers are " <<count;
}


int main()
{
    int arr[]={1,4,3};
    int n=3;
    
    
    for (int i=0;i<n;i++)
    {
        cout<<endl<<arr[i]<<" ";
    };
    distinctNumbers(arr,n);
   
   
}