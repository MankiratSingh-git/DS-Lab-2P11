#include <iostream>
using namespace std;

int arr[5], n=5;

//create array
void create() {
    cout<<"Enter 5 elements\n";
    for(int i=0;i<5;i++){
        cin>>arr[i];
    }
}
//display array
void display() {
    cout<<"Your array is ";
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

//delete duplicates
void del_dup(){
    for(int i=0; i<5; i++){
        for(int j=i+1;j<n;){
            if(arr[i]==arr[j]){
                for(int k=j;k<n-1;k++){
             arr[k]=arr[k+1];
                }
                n--;
            }
            else j++;
        }
    }
}
//display new array
void display_new() {
    cout<<"Your new array is ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int main() {
    create();
    display();
    del_dup();
    display_new();

    return 0;
}
