#include <iostream>
#include <string>
using namespace std;

class Queue {
    int front, rear, capacity;
    char *arr;
    public:
    Queue(int size){
        capacity=size;
        arr=new char[capacity];
        front=0;
        rear=-1;
    }
    void enqueue(char c){
        arr[++rear]=c;
    }
    char dequeue(){
        return arr[front++];
    }
    bool isEmpty(){
        return front>rear;
    }
    char peek(){
        return arr[front];
    }
};

int main(){
    string s;
    cin>>s;
    Queue q(s.length());
    int freq[256]={0};
    for(int i=0;i<s.length();i++){
        freq[s[i]]++;
        q.enqueue(s[i]);
        while(!q.isEmpty() && freq[q.peek()]>1){
            q.dequeue();
        }
        if(q.isEmpty()) cout<<"-1 ";
        else cout<<q.peek()<<" ";
    }
    return 0;
}
