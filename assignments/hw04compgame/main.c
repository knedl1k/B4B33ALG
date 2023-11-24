// GNU General Public License v3.0
// @knedl1k

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

size_t setCap=1000;

typedef struct{
  int x,y;
  int color;
  int lenght;
}status_t;

typedef struct{
  status_t *data;
  size_t size;
}set_t;

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

bool isInSet(set_t *set,status_t element);
bool addToSet(set_t *set,status_t element);
void initializeSet(set_t *set);

int bfs(int M,int N,int board[M][N], int C);

void pPrint(int M,int N,int board[M][N]);

int dx[4]={0,1,0,-1};
int dy[4]={-1,0,1,0};

int main(void){
  set_t my_set;
  initializeSet(&my_set);

  queue_t queue;
  initQueue(&queue);
  
  int M,N;
  int C;
  scanf("%d %d %d",&M,&N,&C);
  int board[M][N];
  for(size_t i=0;i<M;++i)
    for(size_t j=0;j<N;++j)
      scanf("%d",&board[i][j]);
  

  int b=bfs(M,N,board, C);
  
  printf("%d\n",b);

	return EXIT_SUCCESS;
}

int bfs(int M,int N,int board[M][N], int C){
  int shortest_path=-1;
  queue_t q;
  initQueue(&q);
  set_t my_set;
  initializeSet(&my_set);
  status_t root={.x=M-1,.y=0,.color=0,.lenght=0};
  addToSet(&my_set, root);
  enqueue(&q, root);
  while(! isEmpty(q)){
    status_t v=dequeue(&q);
    
    if(v.x==0 && v.y==N-1){ //got to the end
      //printf("%d %d %d\n",v.x,v.y,v.color);
      shortest_path=v.lenght;
      break;
    }
    for(size_t i=0; i<4;++i){
      int x=v.x + dx[i];
      int y=v.y + dy[i];
      //printf("%d %d %d\n",x>=0 && x<M,y>=0 && y<N,(board[x][y]== v.color || board[x][y]<=0));
      //printf("barvy: %d %d\n",board[x][y],v.color);
      if(x>=0 && x<M && y>=0 && y<N && (board[x][y]== v.color || board[x][y]<=0)){
        status_t element={.x=x, .y=y, .color=(board[x][y]<0)? abs(board[x][y]) : v.color, .lenght=v.lenght+1};
        //printf("jsem zde\n");
        if(addToSet(&my_set, element)){
          enqueue(&q, element);
          //printf("queue:%d %d %d\n",x,y,element.color);
          
        }
      }
    }
  }
  free(my_set.data);
  free_queue(&q);

  return shortest_path;
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

void initializeSet(set_t *set){
  set->data=malloc(sizeof(status_t)*setCap);
  set->size=0;
}

bool addToSet(set_t *set,status_t element){
  for(size_t i=0; i<set->size; ++i){
    if(set->data[i].x==element.x && set->data[i].y==element.y && set->data[i].color==element.color)
      return false;
  }
  if(set->size==setCap){
    status_t *tmp=realloc(set->data,sizeof(status_t)*setCap*2);
    /*
    if(tmp==NULL){
      free(set);
      exit(200);
    }
    */
    set->data=tmp;
    setCap*=2;
  }
  set->data[set->size]=element;
  set->size++;

  return true;
}

bool isInSet(set_t *set,status_t element){
  for(size_t i=0;i<setCap;++i)
    if(set->data[i].x==element.x && set->data[i].y==element.y && set->data[i].color==element.color)
      return false;
  return true;
}

void pPrint(int M,int N,int board[M][N]){
  for(size_t i=0;i<M;++i){
    for(size_t j=0;j<N;++j)
      printf("%d ",board[i][j]);
    printf("\n");
  }
}