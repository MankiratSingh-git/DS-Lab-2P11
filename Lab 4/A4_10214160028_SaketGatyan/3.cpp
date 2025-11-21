#include <iostream>
using namespace std;

class Queue {
    int front, rear, capacity, *arr;
    public:
    Queue(int size){
        capacity=size;
        arr=new int[capacity];
        front=0;
        rear=-1;
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
};

int main(){
    int n;
    cin>>n;
    Queue q(n);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        q.enqueue(x);
    }
    int half=n/2;
    int *first=new int[half];
    for(int i=0;i<half;i++){
        first[i]=q.dequeue();
    }
    int *second=new int[half];
    for(int i=0;i<half;i++){
        second[i]=q.dequeue();
    }
    for(int i=0;i<half;i++){
        cout<<first[i]<<" "<<second[i]<<" ";
    }
    return 0;
}