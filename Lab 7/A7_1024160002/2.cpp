#include <iostream>
using namespace std;

void selectionSort(int arr[], int n){

  int i = 0, j = n - 1;

  for (i = 0; i < j; i++, j--){
    int SI = i;
    int LI = j;

    for (int k = i; k <= j; k++){
      if (arr[k] < arr[SI]){
        SI = k;
      }
      if (arr[k] > arr[LI]){
        LI = k;
      }
    }

    swap(arr[i], arr[SI]);
    if (LI == i){
      LI = SI;
    }
    swap(arr[j], arr[LI]);
  }
  
}


void printArr(int arr[], int n){
  for(int i = 0 ; i < n ; i++){
    cout << arr[i] << " ";
  }
  cout << endl;
}


int main(){
  int arr[] = {5, 4, 3, 2, 1};
  printArr(arr, 5);
  selectionSort(arr, 5);
  printArr(arr, 5);
  return 0;
}