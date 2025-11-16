#include<iostream>
using std::cout;
int countDistinct(int size,int arr[]){
    int distinct_element = 0 ;
    for(int i=0;i<size;i++){
        int count = 0; 
        for(int j=i;j<size;j++){
            if(arr[j]==arr[i]){
                count+=1;
            }else{
                continue;
            }
        }
        if(count==1||count<0){
            distinct_element = distinct_element+1;
        }
    }
    return distinct_element;
}
int main(){
    int A[] ={1,5,6,7,9,9,9}; // i have taken a array
    // count distinct elements
    int size = sizeof(A)/sizeof(int);
    int numb = countDistinct(size,A);
    cout<<numb;
}