#include <iostream>
using namespace std;

class CircularQueue {
    int front, rear, capacity, *arr;
    public:
    CircularQueue(int size){
        capacity=size;
        arr=new int[capacity];
        front=-1;
        rear=-1;
    }
    void enqueue(int x){
        if(isFull()){
            cout<<"Queue Overflow\n";
            return;
        }
        if(front==-1) front=0;
        rear=(rear+1)%capacity;
        arr[rear]=x;
        cout<<"Element enqueued successfully!\n";
    }
    void dequeue(){
        if(isEmpty()){
            cout<<"Queue Underflow\n";
            return;
        }
        cout<<"Dequeued: "<<arr[front]<<"\n";
        if(front==rear){
            front=-1;
            rear=-1;
        }
        else front=(front+1)%capacity;
    }
    bool isEmpty(){
        return front==-1;
    }
    bool isFull(){
        return (front==0 && rear==capacity-1) || (front==rear+1);
    }
    void display(){
        if(isEmpty()){
            cout<<"Queue is empty\n";
            return;
        }
        int i=front;
        while(true){
            cout<<arr[i]<<" ";
            if(i==rear) break;
            i=(i+1)%capacity;
        }
        cout<<"\n";
    }
    void peek(){
        if(isEmpty()){
            cout<<"Queue is empty\n";
            return;
        }
        cout<<"Front element: "<<arr[front]<<"\n";
    }
};

int main(){
    int size;
    cout<<"Enter circular queue size: ";
    cin>>size;
    CircularQueue q(size);
    while(true){
        int choice;
        cout<<"1. ENQUEUE\n2. DEQUEUE\n3. isEmpty\n4. isFull\n5. DISPLAY\n6. PEEK\n7. EXIT\n> ";
        cin>>choice;
        if(choice==1){
            int val;
            cout<<"Enter element: ";
            cin>>val;
            q.enqueue(val);
        }
        else if(choice==2){
            q.dequeue();
        }
        else if(choice==3){
            cout<<(q.isEmpty()?"True\n":"False\n");
        }
        else if(choice==4){
            cout<<(q.isFull()?"True\n":"False\n");
        }
        else if(choice==5){
            q.display();
        }
        else if(choice==6){
            q.peek();
        }
        else if(choice==7){
            break;
        }
        else{
            cout<<"Invalid input\n";
        }
    }
    return 0;
}