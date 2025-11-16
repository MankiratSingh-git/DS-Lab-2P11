#include <iostream>
using namespace std;
#include"ll.h"

bool isPaliindrome(DoublyLinkedList dll){
  Node* front = dll.head;
  Node* rear = dll.head;
  while(rear->next){
    rear = rear->next;
  }

  while(front != rear && front->prev != rear){
    if(front->data != rear->data){
      return false;
    }
    else{
      front = front->next;
      rear = rear->prev;
    }
  }
  return true;

}

int main(){
  DoublyLinkedList dll;
  dll.insertEnd(1);
  dll.insertEnd(2);
  dll.insertEnd(3);
  dll.insertEnd(3);
  dll.insertEnd(2);
  dll.insertEnd(1);

  cout << isPaliindrome(dll) << endl;
  return 0;
}