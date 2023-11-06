// GNU General Public License v3.0
// @knedl1k

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "node.h"


/*
 * N .. number of rooms, N>=2
 * B .. number of boxes, B<=15
 * box_weight[] .. weight of boxes in order they are stored
 *
 *
 */

int main(void){
  
  u2 N=0,B=0;
  scanf("%hu %hu",&N,&B);
  u2 box_weight[B];
  for(u2 i=0;i<B;++i)
    scanf("%hu",&box_weight[i]);
  struct node* root = create(0,0,0);
  struct node* currentL=root;
  struct node* currentR=root;
  for(u2 i=0;i<N-1;++i){
    u2 root1=0,root2=0,nodeL=0,nodeR=0,priceL=0,priceR=0;
    scanf("%hu %hu %hu",&root1,&nodeL,&priceL);
    root->price_left=priceL;

    insertLeft(root, nodeL, unsigned short price_left, unsigned short price_right);
  }

  //free_tree(current);

/*
  struct node* root = create(0,10,20);
  insertLeft(root, 1,30,40);
  insertRight(root, 2,0,50);
  struct node* current=root->left;
  insertLeft(current, 3,0,0);
  insertRight(current, 4,0,0);s
  current=root->right;
  insertLeft(current, 5,0,20);
  //insertLeft(current->right, 6, 0, 0);
  //insertRight(root->right, 33);
*/
  preorderTraversal(root);
  printf("\n");
  postorderTraversal(root);



  free_tree(root);

	return 0;
}

