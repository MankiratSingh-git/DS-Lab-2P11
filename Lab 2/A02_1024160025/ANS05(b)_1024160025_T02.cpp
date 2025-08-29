#include<iostream>
using namespace std;
int main(){
	int n;
	cout<<"enter the size of matrix :";
	cin>>n;
	int elements=(3*n)-2;
	int mat[elements];
	cout<<"Enter "<<elements<<" elements :";
	for(int i=0;i<elements;i++){
		cin>>mat[i];
	}
	cout<<"Tridiagonal Matrix : "<<endl;
	int k=0;
	for (int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if((i==j)||(i==j+1)||(i+1==j)){
				cout<<mat[k++]<<" ";
			}
//			else if(i==j+1){
//				cout<<mat[k++]<<" ";
//			}
//			else if(i+1==j){
//			cout<<mat[k++]<<" ";
//			}
			else {
				cout<<"0 ";
			}
		}
		cout<<endl;
	}
}
	
			
			
		
