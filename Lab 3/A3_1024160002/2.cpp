#include<iostream>
#include<string>
using namespace std;

static const int MAX = 100;

class Stack{
  int top = -1;
  char arr[MAX];

  public:

  char pop(){
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

  char peek(){
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
  string s = "DataStructure";
  int n = s.length();
  Stack str;
  for(int i = 0 ; i < n ; i++){
    str.push(s[i]);
  }

  for(int i = 0 ; i < n ; i++){
    cout << str.pop();
  }
  cout << endl;
}