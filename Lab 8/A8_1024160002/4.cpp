#include <iostream>
using namespace std;

struct Node{
  int data;
  Node* left;
  Node* right;

  Node(int data_) : data(data_), left(nullptr), right(nullptr) {}

};


Node* prev = nullptr;
bool isBST(Node* tree){
  if(!tree) return true;
  
  if(!isBST(tree->left)) return false;
  if(::prev && ::prev->data > tree->data) return false;
  ::prev = tree;
  if(!isBST(tree->right)) return false;
  return true;

}

int main(){
  
  return 0;
}