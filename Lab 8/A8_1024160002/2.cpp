#include <iostream>
using namespace std;

struct Node{
  int data;
  Node* left;
  Node* right;

  Node(int data_) : data(data_), left(nullptr), right(nullptr) {}

};

int recursiveSearch(Node* tree, int key){
  if (!tree) return -1;

  if (tree->data == key) return tree->data;
  else if (key < tree->data) return recursiveSearch(tree->left, key);
  else return recursiveSearch(tree->right, key);
}

int iterativeSearch(Node* tree, int key){

  while(tree && tree->data != key){
    if(key < tree->data) tree = tree->left;
    if(key > tree->data) tree = tree->right;
  }
  if(!tree) return -1;
  else return tree->data;
}



Node* max(Node* tree){
  while(tree->left) tree = tree->left;
  return tree;
}

Node* min(Node* tree){
  while(tree->right) tree = tree->right;
  return tree;
}

Node* parent(Node* tree, int key){
  if(!tree || tree->data == key) return nullptr;

  if((tree->left && tree->left->data == key) || (tree->right && tree->right->data == key)) return tree;
  if(key < tree->data) return parent(tree->left, key);
  if(key > tree->data) return parent(tree->right, key);

  return nullptr;
}

Node* IS(Node* tree, Node* subtree){
  if(subtree->right) return min(subtree->right);

  Node* succ = nullptr;
  while(true){
    if(subtree->data < tree->data){
      succ = tree;
      tree = tree->left;
    }
    else if(subtree->data > tree->data){
      tree = tree->right;
    }
    else break;
  }
  return succ;
}

Node* IS_Parent(Node* tree, Node* subtree){
  if(subtree->right) return min(subtree->right);

  Node* p = parent(tree, subtree->data);
  while(p && subtree == p->right){
    subtree = p;
    p = parent(tree, p->data);
  }
  return p;
}


Node* IP(Node* tree, Node* subtree){
  if(subtree->left) return max(subtree->left);

  Node* succ = nullptr;
  while(true){
    if(subtree->data < tree->data){
      tree = tree->left;
    }
    else if(subtree->data > tree->data){
      succ = tree;
      tree = tree->right;
    }
    else break;
  }
  return succ;
}

Node* IP_Parent(Node* tree, Node* subtree){
  if(subtree->left) return max(subtree->left);

  Node* p = parent(tree, subtree->data);

  while(p && p->left == subtree){
    subtree = p;
    p = parent(tree, p->data);
  }
  return p;
}

int main(){
  
  return 0;
}