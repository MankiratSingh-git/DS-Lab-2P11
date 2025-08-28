#include<iostream>
using namespace std;

static const int MAX = 10;

class Stack{
  int top = -1;
  int arr[MAX];

  public:

  int pop(){
    if(top == -1){
      cout << "Stack Underflow" << endl;
      return -1;
    }
    else{
      top--;
      return arr[top+1];
    }
  }

  void push(int n){
    if(top == MAX-1){
      cout << "Stack Overflow" << endl;
    }

    else{
      top++;
      arr[top] = n;
    }
  }

  int peek(){
    if(top==-1){
      cout << "Stack is empty" << endl;
      return -1;
    }
    else{
      return arr[top];
    }
  }

  bool isFull(){
    return (top == (MAX-1));
  }

  bool isEmpty(){
    return (top == -1);
  }

  void display(){
    if(top == -1){
      cout << "Stack is empty" << endl;
    }
    else{
      for(int i = 0 ; i <= top ; i++){
        cout << arr[i] << endl;
      }
    }
  }
};

int main(){
  Stack s;
  s.peek();
  s.push(4);
  s.display();
  int i = s.pop();
  s.push(i);
  cout << s.isEmpty() << endl;
 
}