#include <iostream>
using namespace std;

class Node
{
  int data;
  Node *next;
  Node *prev;
  friend class CircularLinkedList;
  friend class DoublyLinkedList;
};

class CircularLinkedList
{
  Node *head = NULL;

public:
  void insertBeginning(int data)
  {
    Node *newNode = new Node;
    newNode->data = data;

    if (!head)
    {
      head = newNode;
      newNode->next = head;
      return;
    }

    Node *current = head;

    while (current->next != head)
    {
      current = current->next;
    }

    newNode->next = head;
    head = newNode;
    current->next = newNode;
  }

  void insertEnd(int data)
  {
    Node *newNode = new Node;
    newNode->data = data;

    if (!head)
    {
      head = newNode;
      head->next = head;
      return;
    }

    Node *current = head;

    while (current->next != head)
    {
      current = current->next;
    }

    current->next = newNode;
    newNode->next = head;
  }

  void insertValue(int data, int value)
  {

    if (!head)
    {
      cout << "Linked list is empty" << endl;
      return;
    }

    Node *current = head;

    while (current->next != head && current->data != value)
    {
      current = current->next;
    }

    if (current->data != value)
    {
      cout << "Value not found!" << endl;
      return;
    }

    Node *newNode = new Node;
    newNode->data = data;

    if (current == head)
    {
      delete newNode;
      insertBeginning(data);
      return;
    }

    if (current->next == head)
    {
      current->next = newNode;
      newNode->next = head;
      return;
    }

    newNode->next = current->next;
    current->next = newNode;
    return;
  }

  void deleteStart()
  {
    if (!head)
    {
      cout << "List is empty" << endl;
      return;
    }

    if (head->next == head)
    {
      delete head;
      head = NULL;
      return;
    }

    Node *current = head;
    while (current->next != head)
    {
      current = current->next;
    }

    Node *temp = head;
    head = head->next;
    current->next = head;
    delete temp;
  }

  void deleteEnd()
  {
    if (!head)
    {
      cout << "List is empty" << endl;
      return;
    }

    if (head == head->next)
    {
      delete head;
      head = NULL;
      return;
    }

    Node *current = head;
    Node *previous = head;
    while (current->next != head)
      ;
    {
      previous = current;
      current = current->next;
    }

    previous->next = head;
    delete current;
  }

  void deleteValue(int value)
  {
    if (!head)
    {
      cout << "List is empty" << endl;
      return;
    }

    Node *current = head;
    Node *previous = head;

    while (current->next != head && current->data != value)
    {
      previous = current;
      current = current->next;
    }

    if (current->data != value)
    {
      cout << "Value not found" << endl;
      return;
    }

    if (current == head)
    {
      deleteStart();
      return;
    }

    if (current->next == head)
    {
      previous->next = head;
      delete current;
      return;
    }

    previous->next = current->next;
    delete current;
    return;
  }

  void display()
  {
    if (!head)
    {
      cout << "List is empty" << endl;
      return;
    }
    Node *current = head;
    do
    {
      cout << current->data << " ";
      current = current->next;
    } while (current != head);
    cout << endl;
  }

  ~CircularLinkedList()
  {
    while (head)
    {
      deleteStart();
    }
  }
};

class DoublyLinkedList
{
  Node *head = NULL;

public:
  void insertBeginning(int data)
  {
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (!head)
    {
      head = newNode;
      return;
    }

    newNode->next = head;
    head->prev = newNode;
    head = newNode;
  }

  void insertEnd(int data)
  {
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (!head)
    {
      head = newNode;
      return;
    }

    Node *current = head;
    while (current->next)
    {
      current = current->next;
    }

    current->next = newNode;
    newNode->prev = current;
  }

  void insertValue(int data, int value)
  {
    if (!head)
    {
      cout << "Linked list is empty" << endl;
      return;
    }

    Node *current = head;

    while (current->next && current->data != value)
    {
      current = current->next;
    }

    if (current->data != value)
    {
      cout << "Value not found!" << endl;
      return;
    }

    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (current == head)
    {
      delete newNode;
      insertBeginning(data);
      return;
    }

    if (!current->next)
    {
      current->next = newNode;
      newNode->prev = current;
      return;
    }

    newNode->next = current->next;
    newNode->prev = current;
    current->next->prev = newNode;
    current->next = newNode;
  }

  void deleteStart()
  {
    if (!head)
    {
      cout << "List is empty" << endl;
      return;
    }

    if (!head->next)
    {
      delete head;
      head = NULL;
      return;
    }

    Node *temp = head;
    head = head->next;
    head->prev = NULL;
    delete temp;
  }

  void deleteEnd()
  {
    if (!head)
    {
      cout << "List is empty" << endl;
      return;
    }

    if (!head->next)
    {
      delete head;
      head = NULL;
      return;
    }

    Node *current = head;
    Node *previous = head;

    while (current->next)
    {
      previous = current;
      current = current->next;
    }

    previous->next = NULL;
    delete current;
  }

  void deleteValue(int value)
  {
    if (!head)
    {
      cout << "List is empty" << endl;
      return;
    }

    Node *current = head;
    Node *previous = head;

    while (current->next && current->data != value)
    {
      previous = current;
      current = current->next;
    }

    if (current->data != value)
    {
      cout << "Value not found" << endl;
      return;
    }

    if (current == head)
    {
      deleteStart();
      return;
    }

    if (!current->next)
    {
      deleteEnd();
      return;
    }

    previous->next = current->next;
    current->next->prev = previous;
    delete current;
  }

  void display()
  {
    if (!head)
    {
      cout << "List is empty" << endl;
      return;
    }

    Node *current = head;
    while (current)
    {
      cout << current->data << " ";
      current = current->next;
    }
    cout << endl;
  }

  ~DoublyLinkedList()
  {
    while (head)
    {
      deleteStart();
    }
  }
};

int main()
{
  CircularLinkedList cll;
  DoublyLinkedList dll;
  return 0;
}
