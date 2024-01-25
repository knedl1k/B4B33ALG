// GNU General Public License v3.0
//@knedl1k
#include <iostream>
#include <queue>
#include <vector>
#include <stdlib.h>

/*
 * input is as BFS would go through it
 * blues(num.2) are only on the leaves
 * find the largest path between 2 blues with a rule that you cannot cross 3 same colors
 */

struct node_t{
  int pos=-1,color=-1;
  node_t *right=NULL,*left=NULL;
};

struct path_t{
  size_t size=0;
  int longest1=0,longest2=-1;
};

path_t solve(node_t *node,int size,size_t *longest);

int main(void){
  size_t N;
  std::cin >> N;

  std::vector<size_t> corals(N);

  for(size_t i=0;i<N;++i)
    std::cin >> corals[i];
  
  std::queue<node_t *> tree_q; //pruchod stromem do sirky?

  node_t *root=new node_t();
  tree_q.push(root);
  size_t next=0;
  while(next < N){
    node_t *child=tree_q.front();
    child->pos=next;
    child->color=corals[next];
    ++next;

    tree_q.pop();

    if(child->color != 2){ //can continue,prepare childs
      child->left=new node_t();
      tree_q.push(child->left);
      child->right=new node_t();
      tree_q.push(child->right);
    }
  }

  size_t solution=0;
  solve(root,0,&solution);
  printf("%zu\n",solution);

  /*no time to free the tree :D*/
  return 0;
}

path_t solve(node_t *node,int size,size_t *longest){
  if(node->color == 2){ //end of recursion; return what you got
    path_t final={.longest1=1};//started on this coral
    return final;
  }
  
  path_t right_path=solve(node->right,size,longest);
  path_t left_path=solve(node->left,size,longest);

  if(node->right->color == node->color && right_path.size > 1){;
    right_path.longest1=right_path.longest2;
    right_path.size=1;
  }
  if(node->left->color == node->color  && left_path.size > 1){
    left_path.longest1=left_path.longest2;
    left_path.size=1;
  }
  if(left_path.longest1 == -1 && right_path.longest1 == -1){
    path_t final={.longest1=-1};
    return final;
  }

  if(node->color != node->right->color || node->color != node->left->color){
    size_t total_len=right_path.longest1 + left_path.longest1;
    if(right_path.longest1 > 0 && left_path.longest1 > 0 ){
      if(++total_len > *longest)
        *longest=total_len;
    }
  }

  path_t final;
  final.size=(right_path.longest1 > left_path.longest1)? ((node->color == node->right->color)? (++right_path.size) : 1) : ((node->color == node->left->color)? (++left_path.size) : 1); 
  final.longest1=(right_path.longest1 > left_path.longest1)? ++right_path.longest1 : ++left_path.longest1;

  if(right_path.longest1 > left_path.longest1){
    if(left_path.longest1 != -1)
      final.longest2=++left_path.longest1;
    else
      final.longest2=-1;
  }else{
    if(right_path.longest1!=-1)
      final.longest2=++right_path.longest1;
    else
      final.longest2=-1;
  }
  
  return final;
}
