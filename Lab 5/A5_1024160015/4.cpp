#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node *next;
    Node(int num){
        data = num;
        next = nullptr;
    }
};

class LinkedList {
    public:
    Node *head;
    LinkedList(){
        head = nullptr;
    }
};

void insertEnd(LinkedList &list, int num){
    Node *t = new Node(num);
    if (list.head == nullptr) list.head = t;
    else{
        Node *temp = list.head;
        while(temp->next != nullptr) temp = temp->next;
        temp->next = t;
    }
}

void reverse(LinkedList &list){
    Node *prev = nullptr;
    Node *curr = list.head;
    Node *next = nullptr;
    while(curr != nullptr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    list.head = prev;
    Node *temp = list.head;
    while(temp != nullptr){
        cout << temp->data;
        if (temp->next != nullptr) cout << "->";
        temp = temp->next;
    }
    cout << "->NULL" << endl;
}

int main(){
    LinkedList list;
    for(int i=1;i<=4;i++) insertEnd(list,i);
    reverse(list);
    return 0;
}
