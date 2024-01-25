//GNU General Public License v3.0
//@knedl1k

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

typedef struct Node{
  int color;
  int position;
  struct Node *left,*right;
}Node_t;

typedef struct{
  struct Node **data;
  int front,rear;
  int capacity;
}queue_t;

void enqueue(queue_t *q,Node_t *item);
Node_t *dequeue(queue_t *q);
bool isEmpty(queue_t q);
void initQueue(queue_t *q);
void free_queue(queue_t *q);
Node_t *getQueue(queue_t *q);

void free_tree(Node_t *root);
void pPrint(Node_t *root);

Node_t* create(void);
void createTree(const size_t N,Node_t *root,const int *corals);

int main(void){
  size_t N;
  scanf("%zu",&N);
  int *corals=malloc(sizeof(int)*N);
  for(size_t i=0;i<N;++i){
    scanf("%d",&corals[i]);
  }
  
  Node_t *root=create();
  int next=0;
  queue_t q;
  initQueue(&q);
  enqueue(&q,root);
  printf("%d\n",N);
  while(next < N){
    Node_t *curr=dequeue(&q);
    printf("next: %d %d\n",next,corals[next]);
    curr->color=corals[next];
    printf("next: %d\n",next);
    curr->position=next;
    ++next;
    if(curr->color < 2){
      curr->left=create();
      curr->right=create();
      enqueue(&q, curr->left);
      enqueue(&q, curr->right);
    }
  }
  //pPrint(root);










  free(corals);
  free_tree(root);
  return 0;
}


Node_t* create(void){
  Node_t *new_node=(Node_t *)malloc(sizeof(Node_t));
  new_node->color=0;
  new_node->left=new_node->right=NULL;
  return new_node;
}

void enqueue(queue_t *q,Node_t *item){
  if(isEmpty(*q))
    q->front=q->rear=0;
  else{
    if(q->rear == q->capacity-1){
      Node_t *tmp=realloc(q->data,sizeof(Node_t)*q->capacity*2);
      q->data=&tmp;
      q->capacity*=2;
    }
    q->rear++;
  }
  q->data[q->rear]=item;
}

Node_t *getQueue(queue_t *q){
  Node_t *item=q->data[q->front];
  return item;
}

Node_t *dequeue(queue_t *q){
  Node_t *item=q->data[q->front];
  if(q->front == q->rear)
    q->front=q->rear=-1;
  else
    q->front++;
  return item;
}

bool isEmpty(queue_t q){
  return q.front == -1;
}

void initQueue(queue_t *q){
  q->front=q->rear=-1;
  q->capacity=20;
  q->data=malloc(sizeof(queue_t) *q->capacity);
}

void free_queue(queue_t *q){
  free(q->data);
  q->front=0;
  q->rear=0;
  q->capacity=0;
  q->data=NULL;
}

void pPrint(Node_t *root){ //postorder print
  if(root==NULL) return;
  pPrint(root->left);
  pPrint(root->right);
  printf("%d ->",root->color);
}

void free_tree(Node_t *root){ //postorder free
  if(root==NULL) return;
  free_tree(root->left);
  free_tree(root->right);
  free(root);
}

