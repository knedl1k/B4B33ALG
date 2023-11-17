// GNU General Public License v3.0
// @knedl1k

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "node.h"


void postorderTraversal(Node_t* root) {
  if (root == NULL) return;
  postorderTraversal(root->left);
  postorderTraversal(root->right);
  printf("%zu ", root->value);
}

int main(void){
  size_t N;
  scanf("%zu",&N);
  size_t *values=(size_t *)malloc(sizeof(size_t)*N);
  for(size_t i=0;i<N;++i){
		scanf("%zu",&values[i]);
	}
  Node_t *root=create();
  root->value=values[0];
  createTree(N,root,values);  
  postorderTraversal(root);

  free_tree(root);
  free(values);
	return EXIT_SUCCESS;
}
