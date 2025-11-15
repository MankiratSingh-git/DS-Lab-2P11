#include <iostream>
using namespace std;
#include"ll.h"
int main(){
  
  LinkedList list;
  list.insertEnd(1);
  list.insertEnd(2);
  list.insertEnd(3);
  list.insertEnd(4);
  list.insertEnd(5);
  


  Node* curr = list.head;
  Node* prev = nullptr;
  Node* next = nullptr;
  
  while(curr){
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }

  list.head = prev;

  Node* temp = list.head;
  while(temp){
    cout << temp->data << " ";
    temp = temp->next;
  }
  return 0;
}