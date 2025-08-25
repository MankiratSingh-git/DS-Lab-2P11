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

  string eqn = "{}((a+b)*c)}";
  int n = eqn.length();
  
  Stack check;

  for(int i = 0 ; i < n ; i++){
    if(eqn[i] == '(' || eqn[i] == '[' || eqn[i] == '{'){
      check.push(eqn[i]);
    }
    if(eqn[i] == ')' || eqn[i] == ']' || eqn[i] == '}'){
      if(check.isEmpty()){
        check.push('0');
      }
      else{
        check.pop();
      }
    }
  }

  bool balaned = check.isEmpty();

  if(balaned){
    cout << "Balanced" << endl;
  }
  else{
    cout << "Unbalanced" << endl;
  }
}