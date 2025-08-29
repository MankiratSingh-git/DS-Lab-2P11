#include<iostream>

using namespace std;


int main (){
    int i,j,k,l,m,n;
    int arr[n]={64,34,25,12,22,11,90};
    n=sizeof(arr)/sizeof(arr[0]);
    cout << "Unsorted array: ";
    for(i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    cout << "Sorted array: ";
    for(i=0; i<n; i++) {    
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}