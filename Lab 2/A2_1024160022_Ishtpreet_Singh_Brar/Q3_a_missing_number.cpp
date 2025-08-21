/*3) Design the Logic to Find a Missing Number in a Sorted Array.
 Given an array of n-1
distinct integers in the range of 1 to n, find the missing number
 in it in a Sorted Array
(a) Linear time
(b) Using binary search.*/

#include <iostream>
using namespace std;

int main()
{
    int arr[] = {1, 3, 5, 7, 8,10,15};
    int size = sizeof(arr)/sizeof(arr[0]);
    int last=arr[size-1];

    cout<<endl;

    cout<<"Missing nums :"<<endl;
    
    for (int i = 0 ,j=0; j < last;j++)
    {
        if(arr[i]!=j+1){
            cout<<j+1<<" ";
        }
        else{
            i++;
        }
        
    }
    cout<<endl;
    cout<<endl;

    return 0;
}