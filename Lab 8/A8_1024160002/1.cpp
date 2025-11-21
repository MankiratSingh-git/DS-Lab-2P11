#include <iostream>
using namespace std;

struct Node{
  int data;
  Node* left;
  Node* right;

  Node(int data_) : data(data_), left(nullptr), right(nullptr) {}

};

void inOrder(Node* tree){ // Left->Root->Right
  if(tree == nullptr) return;
  inOrder(tree->left);
  cout << tree-> data << " ";
  inOrder(tree->right);
}

void preOrder(Node* tree){ // Root->Left->Right
  if(tree == nullptr) return; 
  cout << tree->data << " ";
  preOrder(tree->left);
  preOrder(tree->right);
}

void postOrder(Node* tree){ // Left->Right->Root
  if(tree == nullptr) return;
  postOrder(tree->left);
  postOrder(tree->right);
  cout << tree->data << " ";
}



int main(){
  
  return 0;
}