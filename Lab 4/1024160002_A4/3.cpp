#include<iostream>
using namespace std;

class CircularQueue{
  int size;
  int front = -1;
  int rear = -1;
  int *arr;
  public:
  CircularQueue (int n):  size(n), arr(new int[n]) {};
  ~CircularQueue() {delete[] arr;};

  bool isEmpty(){
    return (front == -1 &&  rear == -1);
  }

  bool isFull(){
    return (front == (rear+1)%size);
  }

  void enqueue(int x){

    if(isEmpty()){
      front = rear = 0;
      arr[rear] = x;
      return;
    }

    if(isFull()){
      cout << "Overflow" << endl;
      return;
    }


    else{
      rear++;
      arr[rear] = x;
    }
  }

  int dequeue(){
    if(isEmpty()){
      cout << "Underflow" << endl;
      return -1;
    }
    
    int temp = arr[front];

    if(front == rear){
      front = rear = -1;
      return temp;
    }

    front = (front+1)%size;
    return temp;

  }

  void display(){
    if(isEmpty()){
      cout << "Queue is Empty" << endl;
      return;
    }

    int i = front;
    while (true) {
      cout << arr[i] << " ";
      if (i == rear) break; 
      i = (i + 1) % size;       
    }
    cout << endl;
  }

  int peek(){
    if(!isEmpty()){
      return arr[front];
    }
    else return -1;
  }
};

int main(){
  
  int size = 6;
  CircularQueue Q(size);
  Q.enqueue(4);
  Q.enqueue(7);
  Q.enqueue(11);
  Q.enqueue(20);
  Q.enqueue(5);
  Q.enqueue(9);

  Q.display();

  CircularQueue Q1(size/2);
  CircularQueue Q2(size/2);

  int i = 0;
  for(i; i < size/2 ; i++){
    Q1.enqueue(Q.dequeue());
  }
  for(i ; i < size; i++){
    Q2.enqueue(Q.dequeue());
  }

  while(!Q1.isEmpty() && !Q2.isEmpty()){
    Q.enqueue(Q1.dequeue());
    Q.enqueue(Q2.dequeue());;
  }

  Q.display();
} 



