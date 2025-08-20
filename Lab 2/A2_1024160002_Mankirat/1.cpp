#include<iostream>
using namespace std;

void bubble_sort(int arr[], int n);
void exchange(int& a, int& b);


int main(){
  int arr[] = {5, 4, 3, 2, 1};
  int n = sizeof(arr)/sizeof(int);
  bubble_sort(arr, n);
  
  for(int i = 0 ; i < n ; i++){
    cout << arr[i] << endl;
  }
}

void exchange(int& a, int& b){
  int temp;
  temp = b;
  b = a;
  a = temp;
}

void bubble_sort(int arr[], int n){
  bool flag;
  for(int i = 1 ; i < n; i++){
    flag = 1;
    for(int j=0 ; j < n - i ; j++){
      if(arr[j] > arr[j+1]){
        flag = 0;
        exchange(arr[j], arr[j+1]);
      }
    }
     if (flag == 1){
        break;
     }
  }
}


