#include<iostream>
using namespace std;
int main(){
	int A[]={1,2,3,4,5};
	int n=sizeof(A)/4;
	for(int i=0;i<n;i++){
	cout<<A[i]<<" "	;
	
	}
	cout<<endl;
	int B[n];
	for(int i=0;i<n;i++){
		B[i]=A[n-1-i];
		
	}
	for(int i=0;i<n;i++){
		cout<<B[i]<<" ";
		
	}
	cout<<endl;
}
