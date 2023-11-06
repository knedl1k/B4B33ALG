// GNU General Public License v3.0
// @knedl1k
#include "node.h"

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


struct node* create(u2 value,u2 price_left,u2 price_right){
  struct node* new_node=malloc(sizeof(struct node));
  new_node->data=value;
  new_node->left=NULL;
  new_node->price_left=price_left;
  new_node->right=NULL;
  new_node->price_right=price_right;

  return new_node;
}

struct node* insertLeft(struct node* root, u2 value,u2 price_left, u2 price_right){
  root->left=create(value,price_left,price_right);
  return root->left;
}

struct node* insertRight(struct node* root, u2 value,u2 price_left, u2 price_right){
  root->right=create(value,price_left,price_right);
  return root->right;
}

void preorderTraversal(struct node* root){
  if (root == NULL) return;
  printf("%hd ->", root->data);
  preorderTraversal(root->left);
  preorderTraversal(root->right);
}

void postorderTraversal(struct node* root) {
  if (root == NULL) return;
  postorderTraversal(root->left);
  postorderTraversal(root->right);
  printf("%d ->", root->data);
}

void free_tree(struct node* root){
  if(root==NULL) return;
  free_tree(root->left);
  free_tree(root->right);
  free(root);
}