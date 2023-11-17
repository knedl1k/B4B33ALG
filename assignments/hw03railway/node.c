// GNU General Public License v3.0
// @knedl1k
#include "node.h"

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

Node_t* create(void){
  Node_t *new_node=(Node_t *)malloc(sizeof(Node_t));
  new_node->value=0;
  new_node->right_depth=new_node->left_depth=0;
  new_node->left=new_node->right=NULL;
  return new_node;
}

void calculateDepth(Node_t *root){
  if(root==NULL)return;
  calculateDepth(root->left);  
  calculateDepth(root->right);
    
  if(root->left){
    root->left_depth=1+(root->left->left_depth > root->left->right_depth ? 
    root->left->left_depth : root->left->right_depth);
  }
  if(root->right){
    root->right_depth=1+(root->right->left_depth > root->right->right_depth ? 
    root->right->left_depth : root->right->right_depth);
  }
}

static void placeValue(Node_t *root,const size_t value){
  if(value<root->value){ //go left
    if(root->left==NULL){
      root->left=create();
      root->left->value=value;
      return;
    }else
      placeValue(root->left,value);
  }else{ //go right
    if(root->right==NULL){
      root->right=create();
      root->right->value=value;
      return;
    }else
      placeValue(root->right,value);
  }
}

void createTree(const size_t N,Node_t *root,const size_t *values){
  for(size_t i=1;i<N;++i)
    placeValue(root,values[i]);
}

void free_tree(Node_t *root){ //postorder free
  if(root==NULL)return;
  free_tree(root->left);
  free_tree(root->right);
  free(root);
}