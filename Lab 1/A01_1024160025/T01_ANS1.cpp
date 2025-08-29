#include<iostream>
using namespace std;
int main(){
	int arr[50];
	int n;
	cout<<"enter no of elements in an array:";
	cin>>n;
	cout<<"enter all the elements of given array:";
	
	for(int i=0;i<n;i++){
		cin>>arr[i];	
	}
	
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";	
	}
	
	int inx;
	cout<<"Enter index of new element you want to enter: ";
	cin>>inx;
	int ele;
	cout<<"Enter the new element:";
	cin>>ele;
	if(inx>=0 && inx<=n && n<50){
		for(int i=n;i>inx;--i){
			arr[i]=arr[i-1];
		}
		arr[inx]=ele;
		n++;
		cout<<"New array";
		for(int i=0;i<n;++i)
			cout<<arr[i]<<" ";
			cout<<"\n";
		}else{
			cout<<"Invalid index.";
		}
		
		int del_ele;
		int delinx;
		cout<<"enter the index on which you want to delete the element";
		cin>>delinx;
		if(delinx>=0 && delinx<n){
			for(int i=delinx;i<n-1;++i){
				arr[i]==arr[i+1];
			}
		
			n--;
			cout<<"array after deletion";
			for(int i=0;i<n;++i)
			cout<<arr[i]<<" ";
			cout<<"\n";
			}else{
				cout<<"invalid index";
			}
			
			int key;
			cout<<"enter the element for binary search";
			cin>>key;
			int low=0,high=n-1,found=-1;
			while(low<=high){
				int mid=low+(high-low)/2;
				if(arr[mid]==key){
					found=mid;
					break;
				}
				else if(arr[mid]<key){
					low=mid+1;
				}else{
					high=mid-1;
				}
			}
			if(found!=-1){
				cout<<"found at index"<<found<<endl;
			}
			else{
				cout<<"not found";
			}
			return 0;
		}
			
