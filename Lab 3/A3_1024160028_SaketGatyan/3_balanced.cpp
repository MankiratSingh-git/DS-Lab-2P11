//Contranits : only works for a expr of size 5 or less.
// can be overcome by changing value of size_max ie. array of stack;

//O(T) = n ; O(S) = n

#include<iostream>
using namespace std;
const int size_max = 5; 

class Stack{
    private:
        char arr[size_max];
    public: 
        int top = -1;
        int len = 0;

        void push(char value){
            if(isFull()){
                std::cout<<"Stack is full";
                std::cout<<"\n";
                return;
            }
            top = top+1;
            arr[top] = value;
            len++;
        }
        char pop(){
            if(top==-1){
                std::cout<<"Stack is Empty";
                return '\0';
            }
            char element = arr[top];
            top = top-1;
            len--;
            std::cout<<"The element popped is "<<element;
            std::cout<<"\n";
            return element;
        }
        bool isEmpty(){
            if(top==-1){
                return true;
            }else{
                return false;
            }
        }
        bool isFull(){
            if(len==size_max){
                return true;
            }
            else{
                return false;
            }
        }
        void display(){
            for(int i=0;i<=top;i++){
                std::cout<<arr[i]<<" ";
            }
            std::cout<<"\n";
        }
        char peek(){
           char element = arr[top];
           return element; 
        }
};

void CheckBalanced(Stack &S,std::string expr){
    int length = expr.length();
    for(int i=0;i<length;i++){
        if(expr[i]=='{' || expr[i]=='[' || expr[i]=='('){
            S.push(expr[i]);
        }else if(expr[i]=='}' || expr[i]==']' || expr[i]==')'){
            if(S.isEmpty())
            {
                cout<<"Stack is not balanced"<<endl;
                return;
            }
            char compared = S.peek();
            if(compared=='{' && expr[i]=='}' || compared=='[' && expr[i]==']' || compared=='(' && expr[i]==')'){
                
                S.pop();

            }else{
                std::cout<<"Not Balanced"<<endl;
            }
        }
    }
    if(S.isEmpty()){
        std::cout<<"Balanced"<<endl;
    }else{
        std::cout<<"Not balanced"<<endl;
    }

}
int main(){
    Stack S1;
    string name = "{()}";
    CheckBalanced(S1,name);
    
}
