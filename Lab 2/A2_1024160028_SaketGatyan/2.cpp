#include<iostream>
using std::cout;
void bubbleSort(int size,int arr[]){
    for(int i=0;i<size-1;i++){
        int swaps =0;
        for(int j=0;j<size-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swaps +=1;
            }
        }if(swaps==0){ // optismed bs
            cout<<"runs";
            return;
        }
        
    } 
};
int main(){
    int A[]={64,34,25,12,22,11,90};
    int B[] ={1,2,3,4,5};
    int size = sizeof(B)/sizeof(int);
    bubbleSort(size,B);
    for(int i = 0 ;i<size;i++){
        cout<<B[i]<<" ";

    }

}
// TC : n^2 SC : n
// best case : TC : n
