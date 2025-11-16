// reverse an array using stack
#include<iostream>
const int size_max = 5; 
class Stack{
    private:
        int arr[size_max];
    public: 
        int top = -1;
        int len = 0;

        void push(int value){
            if(isFull()){
                std::cout<<"Stack is full";
                std::cout<<"\n";
                return;
            }
            top = top+1;
            arr[top] = value;
            len++;
        }
        int pop(){
            if(top==-1){
                std::cout<<"Stack is Empty";
                return -1;
            }
            int element = arr[top];
            top = top-1;
            len--;
            std::cout<<"The element poped is "<<element;
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
        int peek(){
           int element = arr[top];
           return element; 
        }
};
int main(){
    Stack S1;
    S1.push(5);
    S1.push(2);
    S1.push(10);
    S1.push(100);
    S1.push(200);
    S1.display();
    S1.pop();
    S1.display();
    

    //S1.push(100);
    std::cout<<S1.peek();
    //S1.display();

    
}