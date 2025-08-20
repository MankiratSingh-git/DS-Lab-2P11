#include<iostream>
using namespace std;

int main()
{
int i,j,k;
int n;
int arr[100];
cout<<"enter the size of array" <<endl;
cin>>n;

cout<<"enter the elements of array" <<endl;
for(i=0;i<n;i++)
{
    cin>>arr[i];    
}

for(i=0;i<n;i++){
    for(j=i+1;j<n;j++)
    {
        if(arr[i]==arr[j])
        {
            for(k=j;k<n-1;k++)
            {
                arr[k]=arr[k+1];
            }
            n--;
            j--;
        }
    }
}

for(i=0;i<n;i++)
{
    cout<<arr[i]<<" ";

}
}