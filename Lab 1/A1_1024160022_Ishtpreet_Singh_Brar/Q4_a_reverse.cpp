#include <iostream>
using namespace std;

int main()
{

    int arr[6]= {1,2,3,4,5,6};
    int size= 6;

    cout<<"reverse "<<endl;
    for(int i= 0;i< size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    for(int i=0 ;i<=((size-1)/2);i++){
        int temp= arr[i];
        arr[i]=arr[size-1-i];
        arr[size-1-i]=temp;
    }
    
    for(int i= 0;i< size;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}