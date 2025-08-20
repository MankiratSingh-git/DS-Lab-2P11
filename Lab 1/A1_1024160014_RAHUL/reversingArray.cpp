#include<iostream>
using namespace std;    
int main()

{
    int n,i;
    cout<<"enter the size of array" <<endl;
    cin>>n;
    int arr[n];
    cout<<"enter the elements of array" <<endl;
    for(i=0;i<n;i++)
    {
        cin>>arr[i];        }

        for(i=0;i<n/2;i++)
        {
            int temp=arr[i];
            arr[i]=arr[n-i-1];
            arr[n-i-1]=temp;
        }
    cout<<"the elements of array after reversing are" <<endl;
    for(i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";  
    }
}