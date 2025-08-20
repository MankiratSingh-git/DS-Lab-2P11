#include<iostream>
using namespace std;
//void removeduplicateelements()
//{
//	int arr[50],n;
//	cout<<"enter no of elementts in the array"<<endl;
//	cin>>n;
//	cout<<"enter the elements"<<endl;
//	for(int i=0;i<n:i++){
//		cin>>arr[i];
//		
//	}
//	cout<<"REMOVE THE DUPLICATES"<<endl;
//	for(int i=0;i<n;i++)
//	{
//		for(int j=i+1;j<n;j++)
//		{
//			if(arr[i]==arr[j])
//			{
//				while(j<n)
//				{
//					arr[j]=arr[j+1];
//					j++;
//					
//				}
//				--n;
//			}
//			else{
//				continue;
//			}
//		}
//	}
//	for(int i=0;i<n:i++)
//	{
//		cout<<arr[i]<<" ";
//	}
//}
//
//void arrange
int main(){
	int n;
	cout<<"enter the no of elements";
	cin>>n;
	
	int arr[50];
	cout<<"enter the elements";
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	
	cout<<"The original array is:"<<endl;
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(arr[j]>arr[j+1]){
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	
	
	cout<<"Sorted array";
	for(int i=1;i<n;i++){
		cout<<arr[i]<<" ";
	}
	
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(arr[i]==arr[j]){
				for(int k=j;k<n-1;k++){
					arr[k]=arr[k+1];
				}
				n--;
				j--;
			}
		}
	}
	cout<<"Array after removing duplicates:"<<endl;
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
		
	}
	return 0;			
	}
	
	

