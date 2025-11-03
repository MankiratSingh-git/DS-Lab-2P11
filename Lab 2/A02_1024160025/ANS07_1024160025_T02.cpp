#include<iostream>
using namespace std;
int main(){
	int A[]={2,4,1,3,5};
	int n=sizeof(A)/sizeof(A[0]);
	int invcount=0;
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(A[i]>A[j]){
				invcount++;
			}
		}
	}
	
	cout<<"The total no. of inversions: "<<invcount<<endl;
	return 0;
}

