// GNU General Public License v3.0
// @knedl1k
#include "node.h"

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>


Node_t* create(int idx){
  Node_t *new_node=(Node_t *)malloc(sizeof(Node_t));
  new_node->idx=idx;
  new_node->value=0,new_node->number_boxes=0;
  new_node->left=NULL,new_node->right=NULL,new_node->parent=NULL;
  new_node->price_left=0,new_node->price_right=0;
  return new_node;
}

bool isBoxIn(Node_t *root){
  return (root->number_boxes)? 1:0;
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
  if(root==NULL)return;
  postorderTraverse(root->left,correct_place);
  postorderTraverse(root->right,correct_place);
  if(! isBoxIn(root))
    *correct_place=false;
}

static bool checkPath(Node_t *node){
  if(node->parent == NULL) //root
    return node->number_boxes == 0 ? true : false;
  
  if(node->parent->number_boxes != 0) //non-root
    return false;
  
  return checkPath(node->parent);
}

bool isPlaceOK(Node_t *root){
  bool correct_place=true;
  postorderTraverse(root->left,&correct_place);
  postorderTraverse(root->right,&correct_place);
  correct_place=checkPath(root);
  return correct_place;
}

int calculateWeight(Node_t *node){
  if(node==NULL)
    return 0;

  int left_diff=0, right_diff=0;

  if(node->left!=NULL){
    left_diff=abs(node->value - node->left->value);
    left_diff+=calculateWeight(node->left);
  }
  if(node->right != NULL){
    right_diff=abs(node->value - node->right->value);
    right_diff+=calculateWeight(node->right);
  }

  return left_diff+right_diff;
}

int calculateTime(Node_t *node){
  if (node == NULL) {
    return 0;
  }
    
  int time_left = (node->left != NULL) ? (node->left->number_boxes * node->price_left) : 0;
  int time_right = (node->right != NULL) ? (node->right->number_boxes * node->price_right) : 0;
    
  int time_total = time_left + time_right;
    
  int time_sub_left = calculateTime(node->left);
  int time_sub_right = calculateTime(node->right);

  return time_total + time_sub_left + time_sub_right;
}

void free_tree(Node_t *root){
  if(root==NULL)return;
  free_tree(root->left);
  free_tree(root->right);
  free(root);
}