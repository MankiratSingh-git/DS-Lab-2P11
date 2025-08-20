#include<iostream>
using namespace std;

void bubblesort(int arr[],int n)
{
   int itr_count=0;
    for (int i =0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
    {
        if(arr[j]>arr[j+1])
        {
            int temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
        }
        itr_count++;
    }
    }
    cout<<"Number of iterations: "<<itr_count<<endl;
}

int main()
{
    int arr[]={5,4,3,2,1};
    int n= sizeof(arr)/sizeof(arr[0]);
    bubblesort(arr,n);
    cout<<"Sorted array is: ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";              
    }  
   
    return 0;
}