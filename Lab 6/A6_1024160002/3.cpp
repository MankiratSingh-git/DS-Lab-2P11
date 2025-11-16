#include <iostream>
using namespace std;
#include"ll.h"

int main(){
  CircularLinkedList cll;
  cll.insertEnd(20);
  cll.insertEnd(100);
  cll.insertEnd(40);
  cll.insertEnd(80);
  cll.insertEnd(60);
  DoublyLinkedList dll;
  dll.insertEnd(20);
  dll.insertEnd(100);
  dll.insertEnd(40);
  dll.insertEnd(80);
  dll.insertEnd(60);

  int dllSize = 0;
  int cllSize = 0;

  Node* curr = cll.head;
  do{
    cllSize++;
    curr = curr->next;
  } while(curr != cll.head);

  curr = dll.head;
  while(curr){
    dllSize++;;
    curr = curr->next;
  }

  cout << "CLL: " << cllSize << endl;
  cout << "DLL: " << dllSize << endl;

  return 0;
}