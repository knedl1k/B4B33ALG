// GNU General Public License v3.0
// @knedl1k
#ifndef __NODE_H__
#define __NODE_H__

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
  size_t value;
  size_t left_depth,right_depth;
  struct Node *left,*right;
}Node_t;

Node_t* create(void);
void createTree(const size_t N,Node_t *root, const size_t *values);
void calculateDepth(Node_t *root);

void free_tree(Node_t* root);

#endif