#include<iostream>
using namespace std;
int inversion(int size,int arr[]){
    int count_inversion = 0;
    for(int i=0;i<size-1;i++){
        for(int j=i+1;j<size;j++){
            if(arr[i]>arr[j] && i<j){
                count_inversion++;
            }
        }
    }
    return count_inversion;
}
int main(){
    int A[5] = {12,4,96,78,67};
    int invet = inversion(5,A);
    cout<<invet;
    return 0;
}