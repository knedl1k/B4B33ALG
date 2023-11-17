  // GNU General Public License v3.0
  // @knedl1k

  #include <stdio.h>
  #include <stdint.h>
  #include <stdlib.h>

  #include "node.h"

  void pPrint(Node_t* root) {
  if(root==NULL)return;
  pPrint(root->left);
  pPrint(root->right);
  printf("%zu-> hl L:%zu hl P:%zu\n", root->value,root->left_depth,root->right_depth);
}

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
  pPrint(root);

  free_tree(root);
  return EXIT_SUCCESS;
}