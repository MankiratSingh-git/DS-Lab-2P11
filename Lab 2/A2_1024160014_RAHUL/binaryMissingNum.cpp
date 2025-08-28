#include<iostream>
using namespace std;

int binaryMissingNum(int arr[],int n)
{
    int left=0,right=n-2;
   

    while(left<=right)
    {
        int mid=(left+right)/2;
        if(arr[mid]==mid+1)
        {
            left=mid+1;
        }
        else
        {
            right=mid-1;
        }
    }
    return left+1;
}

int main()
{
    int arr[5]={1,2,4,5,6};
    int n=5;
    cout<<binaryMissingNum(arr,n);
}