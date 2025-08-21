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
    
    cout<<"\nTell us the place you want the number to be in the array ";
    cin>>j;
    
    cout<<"Tell us the number to be inserted ";
    cin>>k;
    
    n++;
    for(i=n-1;i>j-1;i--){
        arr[i]=arr[i-1];
    }
    arr[j-1]=k;
    cout<<"New array is ";
     for(i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
