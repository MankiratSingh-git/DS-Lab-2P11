#include<iostream>
using namespace std;


int binary_search(int arr[], int n);

int main(){
  int arr[5] = {1, 2, 3, 5}; 
  int size = sizeof(arr)/sizeof(arr[0]);
}

int binary_search(int arr[], int n){
  int l = 0;
  int r = n-2;

  while(l < r){
    int middle = (l + r)/2;
    if(arr[middle] == middle+1){
      l = middle;
    }
    else{
      r = middle;
    }
  }
}