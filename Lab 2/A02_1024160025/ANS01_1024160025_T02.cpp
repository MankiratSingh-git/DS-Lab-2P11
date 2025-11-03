#include<iostream>
using namespace std;
int binarysearch(int array[],int n,int element){
	int left=0,right=n-1;
	while(left<=right){
		int mid=(left+right)/2;
		if(array[mid] == element){
			return mid;
		}
		else if(array[mid]<element){
			left=mid+1;
		}
		else{
			right=mid-1;
		}
	}
	return -1;
}

int main(){
	int n,element;
	cout<<"Enter no. of elemnts in an array-";
	cin>>n;
	int array[n];
	cout<<"Enter the elements-";
	for(int i=0;i<n;i++){
		cin >> array[i];
	}
	
	cout<<"Enter the element that needs to be found-";
	cin>>element;
	
	int result=binarysearch(array,n,element);
	if(result !=-1)
	cout<<"Element found at index-"<< result <<endl;
	else
	cout<<"Element does not exist in this array."<<endl;
	return 0;
}
