// GNU General Public License v3.0
// @knedl1k

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct{
  char op;
  size_t key;
}action_t;

typedef struct{
  action_t *data;
  int front,rear;
  int cap;
}queue_t;

void loadInput(queue_t *q, size_t N);

void enqueue(queue_t *q,action_t item);
action_t dequeue(queue_t *q);
bool isEmpty(queue_t q);
void initQueue(queue_t *q,size_t cap);
void free_queue(queue_t *q);

int main(void){
  size_t K=0, N=0;
  scanf("%zu %zu",&K,&N);
  queue_t queue;
  initQueue(&queue,N);
  loadInput(&queue, N);
  


  free_queue(&queue);
  return 0;
}



void loadInput(queue_t *q, size_t N){
  for(size_t i=0;i<N;++i){
    action_t action;
    scanf(" %c %zu",&action.op, &action.key);
    enqueue(q, action);
  }
  for(size_t i=0;i<N;++i){
    action_t action;
    action=dequeue(q);
    printf("%c %zu\n",action.op,action.key);
  }
}

void enqueue(queue_t *q,action_t item){
  if(isEmpty(*q))
    q->front=q->rear=0;
  else{
    /*
    if(q->rear == q->cap-1){
      action_t *tmp=realloc(q->data,sizeof(action_t)*q->cap*2);
      q->data=tmp;
      q->cap*=2;
    }
    */
    q->rear++;
  }
  q->data[q->rear]=item;
}

action_t dequeue(queue_t *q){
  action_t item=q->data[q->front];
  if(q->front == q->rear)
    q->front=q->rear=-1;
  else
    q->front++;
  return item;
}

bool isEmpty(queue_t q){
  return q.front==-1;
}

void initQueue(queue_t *q,size_t cap){
  q->front=q->rear=-1;
  q->cap=cap;
  q->data=malloc(sizeof(queue_t) *cap);
}

void free_queue(queue_t *q){
  free(q->data);
  q->front=0;
  q->rear=0;
  q->cap=0;
  q->data=NULL;
}