#include<iostream>

using namespace std;


int main (){
    int i,low,high,mid,target,j,n;
    cout << "What is the legnth of the array ";
	cin >> n;
	int arr[n];
	cout << "Tell us the elements of the sorted array ";
	for(i=0; i<n; i++) {
		cout<<i+1<<" ";
		cin>>arr[i];
	}
	cout<<"Your array is ";
    for(i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    for(i=0;i<n;i++){
        if(arr[i]+1!=arr[i+1]){
            cout<<"The number missing in the array is "<<i+2<< endl;
            break;
        }else{
            continue;
        }
    }
    system("pause");
    return 0;
}