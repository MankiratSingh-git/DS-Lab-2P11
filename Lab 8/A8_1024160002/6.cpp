#include <iostream>
#include<initializer_list>
#include<climits> 
using namespace std;

struct PriorityQueue{
  int Maxsize = 10;
  int size;
  int* A;

  PriorityQueue(initializer_list<int> list){
    size = list.size();
    A = new int[Maxsize];
    int i = 0;
    for(auto l : list){
      A[i++] = l;
    }
    maxHeap();
  }

  ~PriorityQueue(){
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

    void maxHeap(){
      for(int i = size/2 - 1 ; i >= 0 ; i--){
        maxHeapify(i);
      }
    }

    int parent(int i){
    return (i - 1) / 2;
    }

    int max(){
      return A[0];
    }

    int extractMax(){
      if(size == 0){
        cout << "Heap UnderFlow" << endl;
        return -1;
      }
      int max = A[0];
      swap(A[0], A[--size]);
      maxHeapify(0);  
      return max;
    }

    void increaseKey(int i, int k){
      if(k <= A[i]){cout << "Invalid key" << endl; return;}

      A[i] = k;

      while(i > 0 && A[i] > A[parent(i)]){
        swap(A[i], A[parent(i)]);
        i = parent(i);
      }
    }

    void insert(int k){
      if(size == Maxsize){
        cout << "Heap Overflow" << endl;
        return;
      }

      A[size++] = -INT_MAX;
      increaseKey(size-1, k);
    } 

    void printQueue(){
      for(int i = 0 ; i < size ; i++){
        cout << A[i] << " ";
      }
      cout << endl;
    }

};
int main(){
  PriorityQueue q = {1, 2, 3, 4, 5};
  q.printQueue();
  q.insert(6);
  q.insert(7);
  q.insert(8);
  q.insert(9);
  q.insert(0);
  q.printQueue();
  int m = q.extractMax();
  cout << m << endl;
  q.printQueue();
  
  return 0;
}