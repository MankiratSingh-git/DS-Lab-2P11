#include<iostream>
#include "2.h"
using namespace std;
ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL){
            return NULL;
        }
        ListNode* curr = head;
        while(curr&&curr->next!=NULL)
        {
            if(curr->val!=curr->next->val)
            {
                curr=curr->next;
            }else
            {   
                
                ListNode* temp = curr->next;
                curr->next = curr->next->next;
                delete temp;

                
                
            }
            
        }
        curr = head;
        return head;
    }
int main(){
    ListNode* head = new ListNode(1);
    BeginInsertLL(head,2);
    EndInsertLL(head,3);
    EndInsertLL(head,3);
    PrintLL(head);
    cout<<"\n";
    deleteDuplicates(head);
    PrintLL(head);

    return 0;
}