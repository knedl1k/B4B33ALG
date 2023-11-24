// GNU General Public License v3.0
// @knedl1k

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct{
  int x,y;
  int color;
  int lenght;
}status_t;

typedef struct{
  status_t *data;
  int front,rear;
  int capacity;
}queue_t;

void initQueue(queue_t *q);
bool isEmpty(queue_t q);
void enqueue(queue_t *q,status_t item);
status_t dequeue(queue_t *q);
void free_queue(queue_t *q);

bool **all_sets(size_t M, size_t N);
void free_sets(size_t M, size_t C, bool ***sets);
int bfs(size_t M,size_t N, int (*board)[N], size_t C);

void pPrint(size_t M,size_t N,int (*board)[N]);

int dx[4]={0,1,0,-1};
int dy[4]={-1,0,1,0};

int main(void){
  size_t M,N;
  size_t C;
  scanf("%zu %zu %zu",&M,&N,&C);

  int (*board)[N]=malloc(M*sizeof(*board));

  for(size_t i=0;i<M;++i)
    for(size_t j=0;j<N;++j)
      scanf("%d",&board[i][j]);
  
  int b=bfs(M,N,board, C);
  
  printf("%d\n",b);
  free(board);
	return EXIT_SUCCESS;
}

int bfs(size_t M,size_t N,int (*board)[N], size_t C){
  int shortest_path=-1;
  queue_t q;
  initQueue(&q);
  bool ***sets=malloc(sizeof(bool**)*(C+1));
  for(size_t i=0;i<C+1;++i)
    sets[i]=all_sets(M, N);
  
  status_t root={.x=M-1,.y=0,.color=0,.lenght=0};
  enqueue(&q, root);
  sets[root.color][root.x][root.y]=true;

  while(! isEmpty(q)){
    status_t v=dequeue(&q);
    if(v.x==0 && v.y==N-1){ //got to the end
      shortest_path=v.lenght;
      break;
    }
    for(size_t i=0; i<4;++i){
      int x=v.x + dx[i];
      int y=v.y + dy[i];
      if(x>=0 && x<M && y>=0 && y<N && (board[x][y]== v.color || board[x][y]<=0)){
        status_t element={.x=x, .y=y, .color=(board[x][y]<0)? abs(board[x][y]) : v.color, .lenght=v.lenght+1};
        if(! sets[element.color][x][y]){
          enqueue(&q, element);
          sets[element.color][x][y]=true;
        }
      }
    }
  }
  free_queue(&q);
  free_sets(M, C, sets);
  return shortest_path;
}

bool **all_sets(size_t M, size_t N){
  bool **set=calloc(sizeof(bool*),M);
  for(size_t i=0;i<M;++i){
    set[i]=calloc(sizeof(bool),N);
  }
  return set;
}

void free_sets(size_t M, size_t C, bool ***sets){
  for(size_t i=0;i<C+1;++i){
    for(size_t j=0;j<M;++j)
      free(sets[i][j]);
    free(sets[i]);
  }
  free(sets);
}

bool isEmpty(queue_t q){
  return q.front == -1;
}

void enqueue(queue_t *q,status_t item){
  if(isEmpty(*q))
    q->front=q->rear=0;
  else{
    if(q->rear == q->capacity-1){
      status_t *tmp=realloc(q->data,sizeof(status_t)*q->capacity*2);
      q->data=tmp;
      q->capacity*=2;
    }
    q->rear++;
  }
  q->data[q->rear]=item;
}

status_t dequeue(queue_t *q){
  status_t item=q->data[q->front];
  if(q->front == q->rear)
    q->front=q->rear=-1;
  else
    q->front++;
  return item;
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