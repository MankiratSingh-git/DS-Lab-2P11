#include<iostream>
using namespace std;
int main(){
	int n;
	cout<<"Enter size of matrix:";
	cin>>n;
	int elements=n*(n+1)/2;
	int mat[elements];
	cout<<"enter "<<elements<<" elements fot the matrix : ";
	for(int i=0;i<elements;i++){
		cin>>mat[i];
		
	}
	int k=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
		if(i>=j){
			cout<<mat[k]<<" ";
			k++;
		}else{
			int col=(j*(j+1)/2)+i;
			cout<<mat[col]<<" ";
		}
	}
	cout<<endl;
}
return 0;
}
		
