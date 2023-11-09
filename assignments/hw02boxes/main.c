// GNU General Public License v3.0
// @knedl1k

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <limits.h>

#include "node.h"

typedef struct Result{
  int time;
  int weight;
}Result_t;

/*
 * N .. number of rooms, N>=2
 * B .. number of boxes, B<=15
 * boxes[] .. weight of boxes in order they are stored
 *
 *
 */

 void printPP(Node_t *root){
  if(root==NULL)return;
  printPP(root->left);
  printPP(root->right);
  printf("idx%d:pocet%d:hodnota%d -> ",root->idx,root->number_boxes,root->value);
}

void run(int box_idx, const int B, const int boxes[], const int N, Node_t *nodes[], int *weight, int *time);

int weight=INT_MAX,price=INT_MAX;
int main(void){
  
  int N,B;
  scanf("%d %d",&N,&B);

  int boxes[B];
  for(int i=0;i<B;++i)
    scanf("%d",&boxes[i]);
  
  int topology[N-1][3];
  for(int i=0;i<N-1;++i)
    scanf("%d %d %d",&topology[i][0],&topology[i][1],&topology[i][2]);
  

  Node_t *nodes[N];
  for(int i=0;i<N;++i)
    nodes[i]=create(i);
  
  for(int i=0;i<N-1;++i){
    int parent,child,price;
    parent=topology[i][0];
    child=topology[i][1];
    price=topology[i][2];
    if(nodes[parent]->left == NULL){
      nodes[parent]->left=nodes[child];
      nodes[parent]->price_left=price;
    }else{
      nodes[parent]->right=nodes[child];
      nodes[parent]->price_right=price;
    }
    if(i!=0)
      nodes[child]->parent=nodes[parent];
    
  }

  int time=INT_MAX, weight=INT_MAX;

  run(0,B,boxes,N,nodes,&weight,&time);

  printf("%d %d\n",weight,time);

  free_tree(nodes[0]);
	return 0;
}

void run(int box_idx, const int B, const int boxes[], const int N, Node_t *nodes[], int *weight, int *time){
  if(box_idx >= B){
    int local_weight=calculateWeight(nodes[0]);
    int local_time=calculateTime(nodes[0]);
    
    if((local_weight < *weight) || (local_weight == *weight && local_time < *time)){
      *weight=local_weight;
      *time=local_time;
    }
    if(local_weight==40){
      printPP(nodes[0]);
      printf("\n");
    }
    return;
  }

  for(int i=0;i<N;++i){
    if(isPlaceOK(nodes[i])){
      placeBox(nodes[i], boxes[box_idx]);
      run(box_idx+1,B,boxes,N,nodes,weight,time);
      removeBox(nodes[i], boxes[box_idx]);
    }
  }

}

