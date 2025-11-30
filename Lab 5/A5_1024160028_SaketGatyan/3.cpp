// middle of LL
#include<iostream>
#include "1.h"
using namespace std;
// Node class definition is assumed to be in "1.h", so it is removed here to avoid redefinition and type mismatch.

void findMiddle(Node* &head){
    Node *fast = head;
    Node *slow = head;
    while(fast!=NULL &&fast->next!=NULL){
        slow = slow->next;
        fast= fast->next->next;
    }
    cout<<slow->data;
}
int main()
{
    Node *head = new Node(20);
    BeginInsertLL(head,21);
    EndInsertLL(head,45);
    PrintLL(head);
    return 0;
}