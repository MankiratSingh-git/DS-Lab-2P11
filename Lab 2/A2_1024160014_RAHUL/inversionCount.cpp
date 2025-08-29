#include<iostream>
using namespace std;

void inversionCount(int arr[],int n)
{
    int count=0;
    for (int i=0;i<n;i++)
    {
        for (int j=i+1;j<n;j++)
        {
            if (arr[i]>arr[j])
            {
                count++;
                cout<<"("<<arr[i]<<","<<arr[j]<< ")  is an inversion"<<endl;
            }
            
        }
        
    }
    cout<<count<<endl;
    
}

int main()
{ int n=5;
    int arr[]= {1,2,0,5,6};
    inversionCount(arr,n);
}