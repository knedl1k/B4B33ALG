// GNU General Public License v3.0
// @knedl1k
#include "node.h"

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

Node_t* create(){
  Node_t *new_node=(Node_t *)malloc(sizeof(Node_t));
  new_node->value=0,new_node->number_boxes=0;
  new_node->price=0;
  new_node->left=NULL,new_node->right=NULL,new_node->parent=NULL;
  return new_node;
}

static bool isBoxIn(Node_t *root){
  return(root->number_boxes)? 1:0;
}

void placeBox(Node_t *root,int value){
  root->value+=value;
  root->number_boxes++;
}

void removeBox(Node_t *root,int value){
  root->value-=value;
  root->number_boxes--;
}

static void postorderTraverse(Node_t *root,bool *correct_place){
  if(root==NULL) return;
  postorderTraverse(root->left,correct_place);
  postorderTraverse(root->right,correct_place);
  if(! isBoxIn(root)) *correct_place=false;
}

static bool checkPath(Node_t *node){
  if(node->number_boxes>0) return false;
  if(node->parent) return checkPath(node->parent);
  return true;
}

bool isPlaceOK(Node_t *node){
  bool correct_path=true;
  postorderTraverse(node->left, &correct_path);
  postorderTraverse(node->right, &correct_path);
  return ((!node->parent || checkPath(node->parent)) && correct_path);
}

int calculateWeight(Node_t *node){
  if(node==NULL) return 0;
  int left_diff=0, right_diff=0;
  if(node->left!=NULL){
    left_diff=abs(node->value - node->left->value);
    left_diff+=calculateWeight(node->left);
  }
  if(node->right!=NULL){
    right_diff=abs(node->value - node->right->value);
    right_diff+=calculateWeight(node->right);
  }
  return left_diff+right_diff;
}

void calculateTime(Node_t *node, int *time){
  if(node==NULL) return;
  calculateTime(node->left,time);
  calculateTime(node->right,time);
  *time+=node->price * node->number_boxes;
}

void free_tree(Node_t *root){
  if(root==NULL) return;
  free_tree(root->left);
  free_tree(root->right);
  free(root);
}