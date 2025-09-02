#include <iostream>
using namespace std;

class Queue {
    int front,rear,capacity,*arr;
    public:
    Queue(int size){
        capacity=size;
        arr=new int[capacity];
        front=0;rear=-1;
    }
    void enqueue(int x){
        arr[++rear]=x;
    }
    int dequeue(){
        return arr[front++];
    }
    bool isEmpty(){
        return front>rear;
    }
    int sizeQ(){
        return rear-front+1;
    }
};

class Stack {
    Queue *q;
    int size;
    public:
    Stack(int n){
        size=n;
        q=new Queue(size);
    }
    void push(int x){
        q->enqueue(x);
        for(int i=0;i<q->sizeQ()-1;i++){
            q->enqueue(q->dequeue());
        }
    }
    int pop(){
        return q->dequeue();
    }
    bool isEmpty(){
        return q->isEmpty();
    }
};

int main(){
    Stack s(10);
    s.push(1);
    s.push(2);
    s.push(3);
    cout<<s.pop()<<" ";
    cout<<s.pop()<<" ";
    return 0;
}
