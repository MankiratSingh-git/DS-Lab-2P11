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
  

  Node* curr = cll.head;

  do{
    cout << curr->data << " ";
    curr = curr->next;
  } while(curr != cll.head);
  cout << cll.head->data << endl;

  return 0;
} 