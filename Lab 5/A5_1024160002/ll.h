#include <iostream>
using namespace std;

class Node{
  public:
  int data;
  Node* next = NULL;
};

class LinkedList{
  public:
  Node* head = NULL;

  public:

  void insertBeginning(){
    Node* newNode = new Node;
    cout << "Data: ";
    cin >> newNode->data;

    newNode->next = head;
    head = newNode;


  }

  void insertBeginning(int n){
    Node* newNode = new Node;
    newNode->data = n;

    newNode->next = head;
    head = newNode;


  }

  void insertEnd(){
    Node* newNode = new Node;
    cout << "Data: ";
    cin >> newNode->data;

    if(!head){
      head = newNode;
      return;
    }

    Node* current = head;
    while(current->next){
      current = current->next;
    }

    current->next = newNode;
  }

    void insertEnd(int n){
    Node* newNode = new Node;
    newNode->data = n;

    if(!head){
      head = newNode;
      return;
    }

    Node* current = head;
    while(current->next){
      current = current->next;
    }

    current->next = newNode;
  }

  void insertValue(){

    if(!head){
      cout << "List is empty" << endl;
      return;
    }

    int data;
    cout << "Data to search: ";
    cin >> data;

    Node* newNode = new Node;
    cout << "Data: ";
    cin >> newNode->data;
    Node* current = head;

    while(current && current->data != data){
      current = current->next;
    }

      if(current->data != data){
        cout << "Data not found!" << endl;
        delete newNode;
        return;
      }

      else{
        newNode->next = current->next;
        current->next = newNode;
        return;
      }


  }

  void insertPosition(){
    int position;
    int size = 0;
    
    Node* current = head;

    while(current){
      current = current->next;
      size++;
    }

    current = head;
    cout << "SIZE = " << size << endl;
    cout << "Position: ";
    cin >> position;

    if(position < 0 || position >= size){
      cout << "Enter a valid position" << endl;
      return;
    }

    Node* newNode = new Node;
    cout << "Data: ";
    cin >> newNode->data;

    if(position == 0){
      newNode->next = head;
      head = newNode;
      return;
    }

    for(int i = 0 ; i < position - 1 ; i++){
      current = current->next;
    }
    
    newNode->next = current->next;
    current->next = newNode;

  }


  void deleteStart(){

    if(!head){
      cout << "List is already empty" << endl;
      return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;

  }

  void deleteEnd(){

    if(!head){
      cout << "List is already empty" << endl;
      return;
    }
    
    Node* current = head;
    Node* prev = head;

    if(!head->next){
      head = NULL;
      delete current;
      return;
    }

    while(current->next){
      prev = current;
      current = current->next;
    }

    prev->next = NULL;
    delete current;
  }

  void deleteValue(){
    int data;
    cout << "Data to delete: ";
    cin >> data;

    if(!head){
      cout << "List is empty" << endl;
      return;
    }

    Node* current = head;
    Node* prev = head;

    while(current && current->data != data){
      prev = current;
      current = current->next;
    }

    if(!current){
      cout << "Data not found" << endl;
      return;
    }

    if(current == head){
      head = head->next;
      delete current;
      return;
    }

    prev->next = current->next;
    delete current;
  }

    void deletePosition(){
    int position;
    int size = 0;
    
    Node* current = head;
    Node* prev = head;

    while(current){
      current = current->next;
      size++;
    }

    current = head;
    cout << "SIZE = " << size << endl;
    cout << "Position: ";
    cin >> position;

    if(position < 0 || position >= size){
      cout << "Enter a valid position" << endl;
      return;
    }


    if(position == 0){
      head = head->next;
      delete current;
      return;
    }

    for(int i = 0 ; i < position ; i++){
      prev = current;
      current = current->next;
    }
    
    prev->next = current->next;
    delete current;

  }


  ~LinkedList() {
    Node* current = head;
    while(current) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
  }


};


