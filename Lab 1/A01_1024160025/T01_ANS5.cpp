#include<iostream>
using namespace std;
int main(){
	int r,c;
	cout<<"enter the no. of rows";
	cin>>r;
	cout<<"enter the no. of coloumns";
	cin>>c;
	
	int arr[50][50];
	cout<<"Enter elements of array:";
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cin>>arr[i][j];
		}
	}
	
	cout<<"FINAL MATRIX"<<endl;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	
	for(int i=0;i<r;i++){
		int sumofrow=0;
		for(int j=0;j<c;j++){
			sumofrow+=arr[i][j];
		}

		cout<<sumofrow<<" is the sum of row- "<<i+1<<endl;
	}
	
	for(int j=0;j<c;j++){
		int sumofcol=0;
		for(int i=0;i<r;i++){
			sumofcol+=arr[i][j];
			
		}
		cout<<endl;
		cout<<sumofcol<<" is the sum of col- "<<j+1<<endl;
	}
	
	return 0;
}
