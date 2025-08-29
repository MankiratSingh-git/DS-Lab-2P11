#include<iostream>
using namespace std;

int linearsearch(int array[],int n){
	for(int i=0;i<n-1;i++){
		if(array[i]!=i+1)
		return i+1;
	}
	return n;
}

int binarysearch(int array[],int n){
	int left=0,right=n-2;
	
	while(left<=right){
		int mid=(left+right)/2;
		if(array[mid]==mid+1){
			left=mid+1;
		}else{
			right=mid-1;
		}
	}
	return left+1 ;
}

int main(){
	int array[]={1,3,4,5,6};
	int n=6;
	cout<<"Missing no.:"<<linearsearch(array,n)<<endl;
	cout<<"Missing no.: "<<binarysearch(array,n)<<endl;
	
	return 0;
}
