#include<iostream>
#include<string>
#include<cctype>
#include<cmath>

using namespace std;

static const int MAX = 100;

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

int num(string s){
  int l = s.length();
  int n = 0;
  int i = 0;
  for(char c : s){
    int digit = c - '0';
    n = (n*10) + digit;
  }
  return n;
}

int main(){
  string postfix = "56 21 / 5 7 9 + - *";
  Stack evaluate;
  string n;
  for(char c : postfix){

    if(isalnum(c)){
      n += c;
    }
    else if(c == ' ' && n.length() > 0){
      evaluate.push(num(n));
      n.clear();
    }
    else if(c == '+' || c == '-' || c == '*' || c == '/' || c == '%'){
      int b = evaluate.pop();
      int a= evaluate.pop();
      switch (c){
        case '+': evaluate.push(a+b); break;
        case '-': evaluate.push(a-b); break;
        case '*': evaluate.push(a*b); break;
        case '/': evaluate.push(a/b); break;
        case '%': evaluate.push(a%b); break;
      }

    }

  }
    cout << evaluate.pop() << endl;

}