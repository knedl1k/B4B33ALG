//GNU General Public License v3.0
//@knedl1k

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
  char op;
  int key;
}action_t;

typedef struct{
  action_t *data;
  int front,rear;
  int cap;
}queue_t;

typedef struct node_t{
  int key;
  struct node_t *left,*right;
  int height;
}node_t;

static void loadInput(queue_t *q,const size_t N);

void enqueue(queue_t *q,const action_t item);
action_t dequeue(queue_t *q);
static bool isEmpty(queue_t q);
void initQueue(queue_t *q,const size_t cap);
void freeQueue(queue_t *q);

node_t* createNode(size_t key);
node_t* rightRotate(node_t  *y);
node_t* leftRotate(node_t  *x); 
node_t* insertNode(node_t *node,int key,int max_height);
node_t* removeNode(node_t* root,int key,int max_height);
node_t* minValueNode(node_t* node);

void freeTree(node_t *root);

static void pPrint(node_t *root);
static int height(node_t *node);
static int max(int a,int b);
static int getBalance(node_t *node);

size_t changes=0;

int main(void){
  size_t K=0,N=0;
  scanf("%zu %zu",&K,&N);
  queue_t queue;
  initQueue(&queue,N);
  loadInput(&queue,N);
  int max_height=pow(2,K)-1;
  printf("nechci:%d\n",max_height);
  node_t *root=NULL;
  for(size_t i=0;i<N;++i){
    action_t action=dequeue(&queue);
    if(action.op=='I'){
      printf("I\n");
      root=insertNode(root,action.key,max_height);

    }
      
    else
      root=removeNode(root,action.key,max_height);
  }

  pPrint(root);

  freeQueue(&queue);
  freeTree(root);

  printf("\n%zu\n",changes);
  return 0;
}

node_t* insertNode(node_t *node,int key,int max_height){ 
  if(node==NULL) 
    return(createNode(key)); 
  
  if(key<node->key) 
    node->left =insertNode(node->left,key,max_height); 
  else if(key>node->key) 
    node->right=insertNode(node->right,key,max_height); 
  else //Equal keys are not allowed in BST 
    return node; 
  
  node->height=1+max(height(node->left),height(node->right)); 
  int balance=getBalance(node); 
  //printf("I balance: %d\n",balance);
  
  //Left Left Case 
  if(balance>max_height && key<node->left->key){
    printf("rotuju LL\n");
    return rightRotate(node); 
  }
  
  //Right Right Case 
  if(balance<-max_height && key>node->right->key){
    printf("rotuju RR\n");
    printf("problem %d u %d\n",balance, node->key);
    return leftRotate(node); 
  }
  
  //Left Right Case 
  if(balance>max_height && key>node->left->key){ 
    printf("rotuju LR\n");
    node->left= leftRotate(node->left); 
    return rightRotate(node); 
  }
  
  //Right Left Case 
  if(balance<-max_height && key<node->right->key){ 
    printf("rotuju RL\n");
    node->right=rightRotate(node->right); 
    return leftRotate(node); 
  }
  
  return node; 
}

node_t *rightRotate(node_t *y){ 
  node_t *x=y->left; 
  node_t *T2=x->right; 
  x->right=y; 
  y->left=T2; 
  y->height=max(height(y->left),height(y->right))+1; 
  x->height=max(height(x->left),height(x->right))+1; 
  changes++;
  return x; 
}

node_t *leftRotate(node_t *x){ 
  node_t *y=x->right; 
  node_t *T2=y->left; 
  y->left=x; 
  x->right=T2; 
  x->height=max(height(x->left),height(x->right))+1; 
  y->height=max(height(y->left),height(y->right))+1; 
  changes++;
  return y; 
}

node_t* removeNode(node_t* root,int key,int max_height){
  if(root==NULL) return root;
 
  if(key<root->key)
    root->left=removeNode(root->left,key,max_height);
  else if(key>root->key)
    root->right=removeNode(root->right,key,max_height);
  else{
    //node with only one child or no child
    if((root->left==NULL) || (root->right==NULL)){
      node_t *temp=(root->left)? root->left :root->right;
      if(temp==NULL){ //No child case
        temp=root;
        root=NULL;
      }else //One child case
        *root=*temp; //Copy the contents of
      //the non-empty child
      free(temp);
      }else{
        //node with two children: Get the inorder
        //successor (smallest in the right subtree)
        node_t* temp=minValueNode(root->right);
        //Copy the inorder successor's data to this node
        root->key=temp->key;
        //Delete the inorder successor
        root->right=removeNode(root->right,temp->key,max_height);
      }
  }

  //If the tree had only one node then return
  if(root==NULL)
    return root;
 
  root->height=1+max(height(root->left),height(root->right));
  int balance=getBalance(root);
  //printf("R balance: %d\n",balance);
 
  //Left Left Case
  if(balance>max_height && getBalance(root->left) >= 0){
    printf("rotuju LL\n");
    return rightRotate(root);
  }
  //Left Right Case
  if(balance>max_height && getBalance(root->left)<0){
    printf("rotuju LR\n");
    root->left= leftRotate(root->left);
    return rightRotate(root);
  }
 
  //Right Right Case
  if(balance<-max_height && getBalance(root->right) <= 0){
    printf("rotuju RR\n");
    printf("problem u %d\n",root->key);
    return leftRotate(root);
  }
    
 
  //Right Left Case
  if(balance<-max_height && getBalance(root->right)>0){
    printf("rotuju LR\n");
    root->right=rightRotate(root->right);
    return leftRotate(root);
  }
 
  return root;
}

node_t* minValueNode(node_t* node){
  node_t* current=node;
  while(current->left != NULL)
    current=current->left;
  return current;
}

static void loadInput(queue_t *q,size_t N){
  for(size_t i=0;i<N;++i){
    action_t action;
    scanf(" %c %d",&action.op,&action.key);
    enqueue(q,action);
  }
}

void enqueue(queue_t *q,action_t item){
  if(isEmpty(*q))
    q->front=q->rear=0;
  else{
    /*
    if(q->rear==q->cap-1){
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
  if(q->front==q->rear)
    q->front=q->rear=-1;
  else
    q->front++;
  return item;
}

static bool isEmpty(queue_t q){
  return q.front==-1;
}

void initQueue(queue_t *q,size_t cap){
  q->front=q->rear=-1;
  q->cap=cap;
  q->data=malloc(sizeof(queue_t) *cap);
}

void freeQueue(queue_t *q){
  free(q->data);
  q->front=0;
  q->rear=0;
  q->cap=0;
  q->data=NULL;
}

static int height(node_t *node){
  if(node==NULL) return 0;
  return node->height;
}

static int max(int a,int b){
  return (a>b)? a:b;
}

static int getBalance(node_t *node){
  if(node==NULL) return 0;
  printf("%d: L%d R%d\n",node->key,height(node->left),height(node->right));
  return height(node->left)-height(node->right);
}

node_t* createNode(size_t key){
  node_t *new_node=malloc(sizeof(node_t));
  new_node->key=key;
  new_node->left=new_node->right=NULL;
  new_node->height=1;
  return new_node;
}

static void pPrint(node_t *root){ //preorder print
  if(root==NULL)return;
  printf("%d ",root->key);
  pPrint(root->left);
  pPrint(root->right);
  
}

void freeTree(node_t *root){ //postorder free
  if(root==NULL)return;
  freeTree(root->left);
  freeTree(root->right);
  free(root);
}