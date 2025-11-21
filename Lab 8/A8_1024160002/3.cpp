#include <iostream>
using namespace std;

struct Node{
  int data;
  Node* left;
  Node* right;

  Node(int data_) : data(data_), left(nullptr), right(nullptr) {}

};

Node* insertNode(Node* tree, int key){
  if(!tree){
    return new Node(key);
  }

  if(key > tree->data){
    tree->right = insertNode(tree->right, key);
  }
  
  if(key < tree->data){
    tree->left = insertNode(tree->left, key);
  }

  return tree;

}

Node* deleteNode(Node* tree, int key){
  if(!tree) return nullptr;

  if(key < tree->data) tree->left = deleteNode(tree->left, key);
  if(key > tree->data) tree->right = deleteNode(tree->right, key);

  if(key == tree->data){
    if(!tree->left){
      Node* del = tree;
      tree = tree->right;
      delete del;
    }
    if(!tree->right){
      Node* del = tree;
      tree = tree->left;
      delete del;
    }
    if(tree->left && tree->right){
      Node* IS = tree->right;
      while(IS->left) IS = IS->left;
      tree->data = IS->data;
      tree->right = deleteNode(tree->right, IS->data);
    }

    return tree;

  }
}


int maxDepth(Node* tree){
  if(!tree) return 0;
  if(!tree->left && !tree->right) return 1;

  int LDepth = maxDepth(tree->left);
  int RDepth = maxDepth(tree->right);
  
  return 1 + (LDepth > RDepth ? LDepth : RDepth);
}

int minDepth(Node* tree){
  if(!tree) return 0;
  if(!tree->left && !tree->right) return 1;

  int LDepth = tree->left ? minDepth(tree->left) : INT_MAX;
  int RDepth = tree->right ? minDepth(tree->right) : INT_MAX;
  
  return 1 + (LDepth < RDepth ? LDepth : RDepth);
}


int main(){
  
  return 0;
}