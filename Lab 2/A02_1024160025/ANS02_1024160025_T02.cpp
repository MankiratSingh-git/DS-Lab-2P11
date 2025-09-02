#include<iostream>
using namespace std;
void bubblesort(int array[],int n){
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-1-i;j++){
			if (array[j]>array[j+1]){
			int temp=array[j];
			array[j]=array[j+1];
			array[j+1]=temp;}
		}
	}
}

int main(){
	int array[]={64,34,25,12,22,11,90};
	int n=sizeof(array)/sizeof(array[0]);
	cout<<"initial-";
	for(int i=0;i<n;i++)
	cout<<array[i]<<" ";
	cout<<endl;
	cout<<"sorted array-";
	bubblesort(array,n);
	for(int i=0;i<n;i++)
	cout<<array[i]<<" ";
	cout<<endl;
	return 0;
	}
