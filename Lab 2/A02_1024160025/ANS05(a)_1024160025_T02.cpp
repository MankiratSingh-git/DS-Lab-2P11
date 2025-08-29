#include<iostream>
using namespace std;
int main(){
	int n;
	cout<<"Enter size of the matrix :";
	cin>>n;
	int Mat[n];
	cout<<"Enter "<<n<<" elements for diagnol: ";
	for(int i=0;i<n;i++){
		cin>>Mat[i];
	}
	cout<<"Required diagnol matrix :"<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i==j)
			cout<<Mat[i]<<" ";
			else
			cout<<"0 ";
			}
			cout<<endl;
			}
			return 0;
			}
