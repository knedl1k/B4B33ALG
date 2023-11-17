// GNU General Public License v3.0
// @knedl1k
#include "node.h"

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

Node_t* create(void){
  Node_t *new_node=(Node_t *)malloc(sizeof(Node_t));
  new_node->value=0;
  new_node->right_depth=new_node->left_depth=0;
  new_node->left=new_node->right=new_node->parent=NULL;
  return new_node;
}

static void preorderTraverse(Node_t *root, size_t value){
  //printf("root value:%zu\nvalue:%zu\n",root->value,value);
  if(value<root->value){ //go left
    if(root->left == NULL){
      root->left=create();
      root->left->value=value;
      return;
    }else{
      preorderTraverse(root->left, value);
    }
    
  }else{ //go right
    if(root->right == NULL){
      root->right=create();
      root->right->value=value;
      return;
    }else{
      preorderTraverse(root->right,value);
    }
    
  }
}

void createTree(size_t N,Node_t *root,size_t *values){
  
  for(size_t i=1;i<N;++i){
    preorderTraverse(root, values[i]);
  }

}

void free_tree(Node_t *root){ //postorder free
  if(root==NULL) return;
  free_tree(root->left);
  free_tree(root->right);
  free(root);
}