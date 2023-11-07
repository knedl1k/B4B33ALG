// GNU General Public License v3.0
// @knedl1k
#include "node.h"

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>


Node_t* create(size_t value){
  Node_t *new_node=(Node_t *)malloc(sizeof(Node_t));
  new_node->value=value;
  new_node->left=NULL;
  new_node->price_left=0;
  new_node->right=NULL;
  new_node->price_right=0;
  return new_node;
}
/*
Node_t* insertLeft(Node_t *root, size_t value){
  root->left=create(value);
  return root->left;
}

Node_t* insertRight(Node_t *root, size_t value){
  root->right=create(value);
  return root->right;
}
*/

Node_t* createTree(size_t N, size_t topology[][3]){
  Node_t *nodes[N];
  for(size_t i=0;i<N;++i){
    nodes[i]=create(i);
  }
  for(size_t i=0;i<N-1;++i){
    size_t parent,child,price;
    parent=topology[i][0];
    child=topology[i][1];
    price=topology[i][2];
    if(nodes[parent]->left == NULL){
      nodes[parent]->left=nodes[child];
      nodes[parent]->price_left=price;

    }else{
      nodes[parent]->right=nodes[child];
      nodes[parent]->price_right=price;
    }
  }
  return nodes[0];
}

void preorderTraversal(Node_t *root){
  if(root == NULL)return;
  printf("%zu ->", root->value);
  preorderTraversal(root->left);
  preorderTraversal(root->right);
}

void postorderTraversal(Node_t *root){
  if(root == NULL)return;
  postorderTraversal(root->left);
  postorderTraversal(root->right);
  printf("%zu ->", root->value);
}


void inorderTraversal(Node_t* root){
  if (root == NULL) return;
  inorderTraversal(root->left);
  printf("%zu ->", root->value);
  inorderTraversal(root->right);
}

bool isBoxIn(Node_t *root){
  return (root->value)? 1:0;
}

void placeBox(Node_t *root,size_t value){
  root->value=value;
}

void removeBox(Node_t *root,size_t value){
  root->value-=value;
}

void free_tree(Node_t *root){
  if(root==NULL)return;
  free_tree(root->left);
  free_tree(root->right);
  free(root);
}