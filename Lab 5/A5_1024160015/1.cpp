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

void insertBeginning(LinkedList &list, int num){
    Node *t = new Node(num);
    t->next = list.head;
    list.head = t;
}

void insertEnd(LinkedList &list, int num){
    Node *t = new Node(num);
    if (list.head == nullptr) list.head = t;
    else{
        Node *temp = list.head;
        while(temp->next != nullptr) temp = temp->next;
        temp->next = t;
    }
}

void insertBefore(LinkedList &list, int num, int value){
    if (list.head == nullptr) return;
    if (list.head->data == value){
        insertBeginning(list, num);
        return;
    }
    Node *temp = list.head;
    Node *prev = nullptr;
    while(temp != nullptr && temp->data != value){
        prev = temp;
        temp = temp->next;
    }
    if (temp == nullptr) return;
    Node *t = new Node(num);
    t->next = temp;
    prev->next = t;
}

void insertAfter(LinkedList &list, int num, int value){
    Node *temp = list.head;
    while(temp != nullptr && temp->data != value){
        temp = temp->next;
    }
    if (temp == nullptr) return;
    Node *t = new Node(num);
    t->next = temp->next;
    temp->next = t;
}

void deleteBeginning(LinkedList &list){
    if (list.head == nullptr) return;
    Node *t = list.head;
    list.head = list.head->next;
    delete t;
}

void deleteEnd(LinkedList &list){
    if (list.head == nullptr) return;
    if (list.head->next == nullptr){
        delete list.head;
        list.head = nullptr;
        return;
    }
    Node *temp = list.head;
    while(temp->next->next != nullptr) temp = temp->next;
    delete temp->next;
    temp->next = nullptr;
}

void deleteSpecific(LinkedList &list, int num){
    if (list.head == nullptr) return;
    if (list.head->data == num){
        Node *t = list.head;
        list.head = list.head->next;
        delete t;
        return;
    }
    Node *temp = list.head;
    Node *prev = nullptr;
    while(temp != nullptr && temp->data != num){
        prev = temp;
        temp = temp->next;
    }
    if (temp == nullptr) return;
    prev->next = temp->next;
    delete temp;
}

void search(LinkedList &list, int num){
    Node *temp = list.head;
    int pos = 1;
    while(temp != nullptr){
        if (temp->data == num){
            cout << "Found at position " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Not found" << endl;
}

void display(LinkedList &list){
    Node *temp = list.head;
    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main(){
    LinkedList list;
    int ch, num, val;
    while(true){
        cout << "1.Insert Beg 2.Insert End 3.Insert Before 4.Insert After 5.Del Beg 6.Del End 7.Del Specific 8.Search 9.Display 10.Exit" << endl;
        cin >> ch;
        if (ch==10) break;
        switch(ch){
            case 1: cin >> num; insertBeginning(list,num); break;
            case 2: cin >> num; insertEnd(list,num); break;
            case 3: cin >> num >> val; insertBefore(list,num,val); break;
            case 4: cin >> num >> val; insertAfter(list,num,val); break;
            case 5: deleteBeginning(list); break;
            case 6: deleteEnd(list); break;
            case 7: cin >> num; deleteSpecific(list,num); break;
            case 8: cin >> num; search(list,num); break;
            case 9: display(list); break;
        }
    }
    return 0;
}
