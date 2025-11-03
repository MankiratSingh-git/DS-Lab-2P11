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

void middle(LinkedList &list){
    Node *slow = list.head;
    Node *fast = list.head;
    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << slow->data << endl;
}

int main(){
    LinkedList list;
    for(int i=1;i<=5;i++) insertEnd(list,i);
    middle(list);
    return 0;
}
