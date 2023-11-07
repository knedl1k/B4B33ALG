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
  
  size_t N=0,B=0;
  scanf("%zu %zu",&N,&B);
  size_t box_weight[B];
  for(size_t i=0;i<B;++i){
    scanf("%zu",&box_weight[i]);
  }
  size_t topology[N-1][3];
  for(size_t i=0;i<N-1;++i){
    scanf("%zu %zu %zu",&topology[i][0],&topology[i][1],&topology[i][2]);
  }
  
  Node_t *root=createTree(N,topology);








  preorderTraversal(root);
  printf("\n");
  postorderTraversal(root);
  printf("\n");
  inorderTraversal(root);
  printf("\n");


  free_tree(root);
	return 0;
}