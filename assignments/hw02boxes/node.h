// GNU General Public License v3.0
// @knedl1k
#ifndef __NODE_H__
#define __NODE_H__

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct Node{
  size_t value;
  size_t price_left,price_right;
  struct Node *left,*right;
}Node_t;

Node_t* create(size_t value);
Node_t* createTree(size_t n,size_t topology[][3]);


void preorderTraversal(Node_t* root);
void postorderTraversal(Node_t* root);
void inorderTraversal(Node_t* root);

_Bool isBoxIn(Node_t *root);
void placeBox(Node_t *root, size_t value);
void removeBox(Node_t *root,size_t value);

void free_tree(Node_t* root);

#endif