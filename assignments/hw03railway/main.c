// GNU General Public License v3.0
// @knedl1k

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "node.h"

int main(void){
  size_t N;
  scanf("%zu",&N);
  size_t *values=malloc(sizeof(size_t)*N);
  for(size_t i=0;i<N;++i)
    scanf("%zu",&values[i]);

  Node_t *root=create();
  root->value=values[0];
  createTree(N,root,values);  
  free(values);

  calculateDepth(root);
  printf("%zu\n",root->speed_rail);
  free_tree(root);
  return EXIT_SUCCESS;
}