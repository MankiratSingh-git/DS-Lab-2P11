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

void countAndDelete(LinkedList &list, int key){
    int count = 0;
    while(list.head != nullptr && list.head->data == key){
        Node *t = list.head;
        list.head = list.head->next;
        delete t;
        count++;
    }
    Node *temp = list.head;
    Node *prev = nullptr;
    while(temp != nullptr){
        if (temp->data == key){
            Node *t = temp;
            prev->next = temp->next;
            temp = temp->next;
            delete t;
            count++;
        } else {
            prev = temp;
            temp = temp->next;
        }
    }
    cout << "Count: " << count << " , Updated Linked List: ";
    temp = list.head;
    while(temp != nullptr){
        cout << temp->data;
        if (temp->next != nullptr) cout << "->";
        temp = temp->next;
    }
    cout << endl;
}

int main(){
    LinkedList list;
    int arr[] = {1,2,1,2,1,3,1};
    for(int i=0;i<7;i++) insertEnd(list,arr[i]);
    countAndDelete(list,1);
    return 0;
}
