//Implementing BinarySearch on array . Check Comments for TC & SC

#include<bits/stdc++.h>
using namespace std;
int max_size = 5;


int BinarySearch(int size,int low, int high,int arr[],int element){

    if(low>high) return -1; // out of bounds
    
    int middleTerm = (low+high)/2;
    if(arr[middleTerm]==element){
        return middleTerm;
    }
    else if(arr[middleTerm]>element){
        return BinarySearch(size,low,middleTerm-1,arr,element);
    }else if(arr[middleTerm]<element){
        return BinarySearch(size,middleTerm+1,high,arr,element);
    }
    
}
int main(){
    // Creating and Entering Data into Array Dynamically iteratively
    int arr[max_size];
    cout<<"Array is been Created...."<<"\n";
    cout<<"Array of size "<<max_size<<" is created"<<endl;
    
    
    int count=0;
    char choicy ;
    cout<<"Do you want to enter a element?"<<"\n";
    cin>>choicy;
    while(choicy != 'n' && choicy!= 'N' && count!=max_size ){ 
        cout<<"Enter the integer element you want to add.."<<endl;

        int element;
        cin>>element;arr[count] = element ;
        count++;

        // rewriting the choicy code...
        cout<<"Do you want to enter a element?"<<"\n";
        cin>>choicy;
        
    }

    sort(arr, arr + count);

    cout << "\nSorted array: ";
    for (int i = 0; i < count; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    int add = BinarySearch(5,0,4,arr,5);

    cout<<"element found at "<<add+1<<" position";
}

/* TC and SC for the algorithum BinarySearch



Explanation : The array is divided into 2 halfs each time till for k reducing the searching location.
T(n) = T(n/2)+T(1) 

(I)TC = log2n 

SC = logn 

Each call adds a constant amount of extra space (for parameters + local variables).

Depth of recursion = number of halving steps = log2n
⁡ 
*/