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
    
    
    cout<<"\nTell us the number to be deleted ";
    
    cin>>k;
    
    int flag=0;
    
    for(i=0;i<n;i++){
        if(arr[i]==k){
            flag=1;
            j=i;
        }else{
            continue;
        }
    }
    if(flag==0){
        cout<<"Number not found ";
    }else{
        for(i=j;i<n;i++){
            arr[i]=arr[i+1];
        }
    }
    n--;
    cout<<"Your array is ";
    for(i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    
}
