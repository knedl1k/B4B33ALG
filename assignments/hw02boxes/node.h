// GNU General Public License v3.0
// @knedl1k
#ifndef __NODE_H__
#define __NODE_H__

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
  int value,number_boxes;
  int price;
  struct Node *left,*right,*parent;
}Node_t;

Node_t* create();

void placeBox(Node_t *root, int value);
void removeBox(Node_t *root,int value);

bool isPlaceOK(Node_t *root);
int calculateWeight(Node_t *node);
int calculateTime(Node_t *node);

void free_tree(Node_t* root);

#endif