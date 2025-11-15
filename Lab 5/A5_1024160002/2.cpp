#include <iostream>
#include"ll.h"

int main(){
  LinkedList list;
  list.insertEnd(1);
  list.insertEnd(2);
  list.insertEnd(1);
  list.insertEnd(2);
  list.insertEnd(1);
  list.insertEnd(3);
  list.insertEnd(1);


  Node* curr = list.head;
  Node* prev = curr;
  
  int data = 1;
  int count = 0;

  while(curr){
    if(curr->data == data){
      count++;
      if(list.head == curr){
        list.head = list.head->next;
        Node* temp = curr;
        curr = list.head;
        prev = curr;
        delete temp;
      }
      else{
        prev->next = prev->next->next;
        Node* temp = curr;
        curr = prev->next;
        delete temp;
      }
    }
    else{
      prev = curr;
      curr = curr->next;
    }
  }


  cout << count << endl;

  Node* temp = list.head;
  
  while(temp){
    cout << temp->data << " ";
    temp = temp->next;
  }
}