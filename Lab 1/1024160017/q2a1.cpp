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
    
    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
        }
    }
    cout<<"\nNew array is ";
    
    for(i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    int m=n;
    for(i=0;i<m-1;i++){
        if(arr[i]==arr[i+1]){
            for(j=i+1;j<m-1;j++){
                arr[j]=arr[j+1];
            }
            m--;
            i--;
        }else{
            continue;
        }
    }
    cout<<"\nNew array is ";
    
    for(i=0;i<m;i++){
        cout<<arr[i]<<" ";
    }
}
