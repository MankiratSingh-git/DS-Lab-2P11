#include<iostream>

using namespace std;


int main (){
    int i,low,high,mid,target,j,n;
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
    
    cout<<"\nTell us the number we need to find ";
    
    cin>>target;
    int flag=0;
    high=n;
    low=0;
    
    while(low<=high){
        mid=(low+high)/2;
        if(arr[mid]==target){
            flag=1;
            break;
        }else if(arr[mid]>target){
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    if(flag==1){
        cout<<"Number found at "<<mid+1<<" ";
        
    }else{
        cout<<"Number not found";
    }
    
    system("pause");
    
    return 0;
}