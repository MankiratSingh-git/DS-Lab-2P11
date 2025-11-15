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
  


  Node* slow = list.head;
  Node* fast = list.head;

  while(fast && fast->next){
    slow = slow->next;
    fast = fast->next->next;
  }

  cout << slow->data;
  return 0;
}