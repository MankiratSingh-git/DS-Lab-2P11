#include <iostream>
#include<vector>
using namespace std;

void bubbleSort(int arr[], int n){
  bool isSwap;
  for(int i = 0 ; i < n-1; i++){
    isSwap = false;
    for(int j=0 ; j < n-i-1 ; j++){
      if(arr[j] > arr[j+1]){
        isSwap = true;
        swap(arr[j], arr[j+1]);
      }
    }
    if (!isSwap){
        break;
    }
  }
}

void insertionSort(int arr[], int n){
  for(int i = 1 ; i < n ; i++){
    int temp = arr[i];
    int j = i-1;
    while(j >= 0 && arr[j] > temp){
      arr[j+1] = arr[j];
      j--;
    }
    arr[j+1] = temp;
  }
}

void selectionSort(int arr[], int n){
  for(int i = 0 ; i < n-1 ; i++){
    int SI = i;
    for(int j = i+1 ; j < n ; j++){
      if(arr[j] < arr[SI]){
        swap(arr[j], arr[SI]);
      }
    }
  }
}

void merge(int arr[], int start, int mid, int end){
  vector<int> temp;
  int i = start;
  int j = mid+1;

  while(i<=mid && j <=end){
    if(arr[i]<=arr[j]){
      temp.push_back(arr[i]);
      i++;
    }
    else{
      temp.push_back(arr[j]);
      j++;
    }
  }
  while(i<=mid){
    temp.push_back(arr[i]);
    i++;
  }
  while(j<=end){
    temp.push_back(arr[j]);
    j++;
  }

  for(int idx = 0 ; idx < temp.size(); idx++){
    arr[idx+start] = temp[idx];
  }
}
void mergeSort(int arr[], int start, int end){
  if(start<end){
    int mid = (start+end)/2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid+1, end);
    merge(arr,start, mid, end);
  }
}

int partition(int arr[], int start, int end){
  int pivot = arr[end];
  int idx = start-1;
  for(int j = start; j < end; j++){
    if(arr[j] <= pivot){
      idx++;
      swap(arr[j], arr[idx]);
    }
  }
  idx++;
  swap(arr[idx],arr[end]);
  return idx;
}
void quickSort(int arr[], int start, int end){
  if(start<end){
    int pvtIdx = partition(arr, start, end);
    quickSort(arr, start, pvtIdx-1);
    quickSort(arr, pvtIdx+1, end);
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
  quickSort(arr, 0, 4);
  printArr(arr, 5);
  return 0;
}