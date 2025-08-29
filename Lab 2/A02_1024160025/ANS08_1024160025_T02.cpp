#include<iostream>
using namespace std;
int main(){
	int arr[]={1,2,3,2,1,4,5,6};
	int n=sizeof(arr)/sizeof(arr[0]);
	int discount=0;
	for(int i=0;i<n;i++){
		bool distinct=true;
		for(int j=0;j<i;j++){
			if( arr[i]==arr[j]){
					distinct=false;
					break;
				}
			}
			if(distinct){
				discount++;
			}
		}
		
		cout<<"The total number of distinct elements :"<<discount<<endl;
		return 0;
	}

			
