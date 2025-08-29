#include<iostream>
using namespace std;

class CircularQueue{
  protected:
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
    return ((rear + 1) % size == front);
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
      rear = (rear + 1) % size;
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

    front = (front + 1) % size;
    return temp;
  }

  void display(){
    if(isEmpty()){
      cout << "Queue is Empty" << endl;
      return;
    }
    int i = front;
    while(true){
      cout << "Element: " << arr[i] << endl;
      if(i == rear) break;
      i = (i + 1) % size;
    }
  }

  int peek(){
    if(!isEmpty()){
      return arr[front];
    }
    else return -1;
  }
};

int main(){

  int size;
  cout << "Initialization:\n Size: ";
  cin >> size;
  CircularQueue Q(size);

  while(true){
  cout << "MENU\n1.Enqueue\n2. Dequeue\n3. IsEmpty\n4. IsFull\n5. Display\n6. Peek\n 7. EXIT"<< endl;
  cout << "Enter Choice: ";
  int choice;
  cin >> choice;
  
  switch(choice){
    case 1:
    int x;
    cout << "Number: ";
    cin >> x;
    Q.enqueue(x);
    break;
    cout << Q.dequeue() << endl;
    break;
    case 3:
    cout << Q.isEmpty() << endl;
    break;
    case 4:
    cout << Q.isFull() << endl;
    break;
    case 5:
    Q.display();
    break;
    case 6:
    cout << Q.peek() << endl;
    break;
    case 7:
    exit(0);
    break;
    default:
    cout << "ENTER A VALID ARGUMENT" << endl;
    }
  } 
