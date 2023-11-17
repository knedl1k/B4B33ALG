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
  struct Node *left,*right,*parent;
}Node_t;

Node_t* create(void);
void createTree(size_t N,Node_t *nodes,size_t *values);

int calculateWeight(Node_t *node);
int calculateTime(Node_t *node);

void free_tree(Node_t* root);

#endif