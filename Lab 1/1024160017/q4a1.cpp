#include <iostream>
using namespace std;

int main() {

	int i,j,k,n;

	cout << "What is the legnth of the array ";
	cin >> n;
	int arr[n];
	cout << "Tell us the elements of array ";
	for(i=0; i<n; i++) {
		cout<<i+1<<" ";
		cin>>arr[i];
	}
	cout<<"Your array is ";
    for(i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    
    cout<<"\nReversed array is ";
    int arr2[n];
    for(i=0;i<n;i++){
        arr2[n-i-1]=arr[i];
    }
    for(i=0;i<n;i++){
        cout<<arr2[i]<<" ";
    }
}
