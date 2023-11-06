// GNU General Public License v3.0
// @knedl1k
#ifndef __NODE_H__
#define __NODE_H__

#define u2 unsigned short

struct node{
  u2 data;
  struct node *left;
  u2 price_left;
  struct node *right;
  u2 price_right;
};

struct node* create(u2 value,u2 price_left,u2 price_right);
struct node* insertRight(struct node* root,u2 value,u2 price_left,u2 price_right);
struct node* insertLeft(struct node* root,u2 value,u2 price_left,u2 price_right);

void free_tree(struct node* root);

void preorderTraversal(struct node* root);
void postorderTraversal(struct node* root);

#endif