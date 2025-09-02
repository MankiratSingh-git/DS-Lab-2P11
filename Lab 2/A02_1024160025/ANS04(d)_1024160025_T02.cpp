#include<iostream>
#include<cstring>
using namespace std;
void sortstrings(string array[],int n){
	for(int i=0;i<n-1;++i){
		for(int j=0;j<n-1-i;++j){
			if(array[j]>array[j+1]){
				string temp=array[j];
				array[j]=array[j+1];
				array[j+1]=temp;
			}
		}
	}
}

int main(){
	string str[]={"orange","apple","mango","banana","grape"};
	int n=sizeof(str)/sizeof(str[0]);
	cout<<"initial strings : "<<endl;
	for(int i=0;i<n;i++){
		cout<<str[i]<<" ";
	}
	cout<<endl;
	sortstrings(str,n);
	
	cout<<"sorted string :"<<endl;
	for(int i=0;i<n;i++){
		cout<<str[i]<<" ";
	}
	cout<<endl;
	return 0;
	}
	
