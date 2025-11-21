#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

void BeginInsertLL(Node* &head, int val){
    Node *temp = new Node(val);
    temp->next = head;
    head = temp;
}


void EndInsertLL(Node* &head, int val){
    Node *newNode = new Node(val);

    if(head == NULL){
        head = newNode;
        return;
    }

    Node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}


void InsertMiddle(Node* &head, int pos, int val){
    if(pos == 1){
        BeginInsertLL(head, val);
        return;
    }

    Node *temp = head;
    for(int i = 1; i < pos - 1 && temp != NULL; i++){
        temp = temp->next;
    }

    if(temp == NULL){
        cout << "Position out of range\n";
        return;
    }

    Node *newNode = new Node(val);
    newNode->next = temp->next;
    temp->next = newNode;
}

void PrintLL(Node *head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}
void DeleteBegining(Node* &head){
    if(head==NULL){
        cout<<"Empty LL"<<endl;
    }else{
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}
void DeleteEnd(Node* &head){
    if(head==NULL){
        cout<<"Empty LL"<<endl;
    }else if(head->next==NULL)
    {
        Node *temp = head;
        delete temp;
        head = nullptr;
        cout<<"LL is empty now";
    }
    else{
        Node *prev = NULL;
        Node *temp = head;
        while(temp->next!=NULL){
        prev  = temp;
        temp = temp->next;
        }
        prev->next = NULL;
        delete temp;
    }
}

void DeleteNode(Node* &head,int pos)
{
    if(head==NULL||pos<0){
        return;
    }
    Node* prev = nullptr ;
    Node* curr =  head;
    if(pos==0){
        Node *temp = head;
        head = temp->next;
        delete temp;
    }
    while(pos){
        prev = curr;
        curr = curr->next;
        pos--;
    }
    if(curr==NULL){
        cout<<"Out of Bounds"<<endl;
    }
    Node *temp = curr;
    prev->next = curr->next;
    curr=nullptr;
    delete temp;
}
void countNode(Node* &head){
    int count = 0;
    Node *temp = head;
    while(temp!=NULL){
        temp=temp->next;
        count++;
    }
    cout<<"Number of nodes in the LL is "<<count<<endl;
    
}
int main(){
    Node *head = NULL;

    BeginInsertLL(head, 10);
    EndInsertLL(head, 20);
    BeginInsertLL(head, 5);
    InsertMiddle(head, 2, 15);

    PrintLL(head);
    cout<<"\n------Menu-----\n";
    cout<<"Enter your choice(0-8)";
    int x;
    cin>>x;
    cout<<"1.Insert at Beginning"<<endl;
    cout<<"2.Insert at End"<<endl;
    cout<<"3.Insert at Middle"<<endl;
    cout<<"4.Delete at Beginning"<<endl;
    cout<<"5.Delete at End"<<endl;
    cout<<"6.PrintLL"<<endl;
    cout<<"7.Delete Specific Node"<<endl;
    cout<<"8.Count the number of nodes"<<endl;
    switch(x){
        case 1:
            BeginInsertLL(head, 100);
            PrintLL(head);
            break;
        case 2:
            EndInsertLL(head, 200);
            PrintLL(head);
            break;
        case 3:
            InsertMiddle(head,2,400);
            PrintLL(head);
            break;
        case 4:
            DeleteBegining(head);
            PrintLL(head);
            break;
        case 5:
            DeleteEnd(head);
            PrintLL(head);
            break;
        case 6:
            PrintLL(head);
            break;
        case 7:
            DeleteNode(head,3);
            PrintLL(head);
            break;
        case 8:
            countNode(head);
            PrintLL(head);
            break;
            

    }

    return 0;
}
