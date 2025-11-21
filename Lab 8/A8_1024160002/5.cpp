#include <iostream>
#include<initializer_list>
using namespace std;

struct Heap{
  int size;
  int* A;

  Heap(initializer_list<int> list){
    size = list.size();
    A = new int[size];
    int i = 0;
    for(auto l : list){
      A[i++] = l;
    }
  }

  ~Heap(){
      delete[] A;
    }


    void maxHeapify(int i){
      int left = 2*i+1;
      int right = 2*i+2;

      int largest = i;

      if(left <  size && A[left] > A[largest]){
        largest = left;
      }

      if(right < size && A[right] > A[largest]){
        largest = right;
      }

      if(largest != i){
        swap(A[i], A[largest]);
        maxHeapify(largest);
      }
    }

    void minHeapify(int i){
      int left = 2*i+1;
      int right = 2*i+2;

      int smallest = i;

      if(left < size && A[left] < A[smallest]){
        smallest = left;
      }

      if(right < size && A[right] < A[smallest]){
        smallest = right;
      }

      if(smallest != i){
        swap(A[i], A[smallest]);
        minHeapify(smallest);
      }
    }

    void printHeap(){
      for(int i = 0 ; i < size ; i++){
        cout << A[i] << " ";
      }
      cout << endl;
    }

    void maxHeap(){
      for(int i = size/2 - 1 ; i >= 0 ; i--){
        maxHeapify(i);
      }
    }

    void minHeap(){
      for(int i = size/2 - 1 ; i >= 0 ; i--){
        minHeapify(i);
      }
    }

    void heapSortA(){
      int s = size;
      maxHeap();
      for(int i = size - 1 ; i >= 0 ; i--){
        swap(A[0], A[i]);
        size--;
        maxHeapify(0);
      }
      size = s;
    }

    void HeapSortD(){
      int s = size;
      minHeap();
      for(int i = size - 1 ; i >=0 ; i--){
        swap(A[0], A[i]);
        size--;
        minHeapify(0);
      }
      size = s;
    }

};
int main(){
  
  Heap sort = {5, 4, 3, 2, 1};
  sort.printHeap();
  sort.heapSortA();
  sort.printHeap();
  sort.HeapSortD();
  sort.printHeap();
  return 0;
}