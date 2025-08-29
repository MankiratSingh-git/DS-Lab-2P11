#include<iostream>
using namespace std;

class Queue{
  protected:
  int size;
  int front = -1;
  int rear = -1;
  int *arr;
  public:
  Queue (int n):  size(n), arr(new int[n]) {};
  ~Queue() {delete[] arr;};

  bool isEmpty(){
    return (front == -1 &&  rear == -1);
  }

  bool isFull(){
    return (rear == size - 1);
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

    front++;
    return temp;

  }

  void display(){
    if(isEmpty()){
      cout << "Queue is Empty" << endl;
      return;
    }

    for(int i = front ; i <= rear ; i++){
      cout << "Element " << i+1 << ": " << arr[i] << endl;
    }
  }

  int peek(){
    if(!isEmpty()){
      return arr[front];
    }
    else return -1;
  }
};

class SingilarQueueStack: public Queue{
  public:
  SingilarQueueStack(int n): Queue(n) {}
  void push(int x){
   enqueue(x);
   int n = rear-front + 1;
   for(int i = 0 ; i < n-1 ; i++){
    enqueue(dequeue());
   }
  }

  int pop(){
    return dequeue();
  }

  int top(){
    return peek();
  }
};

class DoubleQueueStack: public SingilarQueueStack{
  Queue *Q;
  public:
  DoubleQueueStack(int n): SingilarQueueStack(n), Q(new Queue(n)) {};
  ~DoubleQueueStack(){delete Q;}

  void push(int x){
    while(!isEmpty()){
      Q->enqueue(dequeue());
    }
    enqueue(x);
    while(!Q->isEmpty()){
      enqueue(Q->dequeue());
    }
  }
};

int main(){
  SingilarQueueStack s(5);

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top: " << s.top() << endl; // 30
    cout << "Pop: " << s.pop() << endl; // 30
    cout << "Top: " << s.top() << endl; // 20
} 

