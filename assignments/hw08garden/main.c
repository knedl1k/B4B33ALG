//GNU General Public License v3.0
//@knedl1k

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
  size_t attractivity;
  size_t length;
}field_t;

int8_t horiz[4]={1,0,-1,0};
int8_t verti[4]={0,-1,0,1};

#define MIN(a,b) ((a < b)? a:b)

static field_t maxAttractivity(field_t a, field_t b);

int main(void){
  int M, N;
  scanf("%d %d",&M, &N);

  size_t **garden=malloc(M * sizeof(size_t*));
  field_t **left=malloc(M * sizeof(field_t*));
  field_t **right=malloc(M * sizeof(field_t*));
  for(int i=0; i<M;++i){
    left[i]=malloc(N * sizeof(field_t));
    right[i]=malloc(N * sizeof(field_t));
    garden[i]=malloc(N * sizeof(size_t));
  }
  
  for(int i=0;i<M;++i)
    for(int j=0;j<N;++j){
      scanf("%zu",&garden[i][j]);
      if(garden[i][j] != 0){
        left[i][j].attractivity=right[i][j].attractivity=0; // we do not want to step on a flower
        left[i][j].length=right[i][j].length=M*N;
      }
    }

  //first row
  for(int i=0;i<1;++i){
    for(int j=0;j<N;++j){
      if(garden[i][j] == 0){
        field_t tmp={.attractivity=0, .length=0};
        for(uint8_t k=0;k<4;++k)
          if(i+verti[k]< M && j+horiz[k]< N && j+horiz[k]>=0 && i+verti[k]>=0)
            tmp.attractivity+=garden[i+verti[k]][j+horiz[k]];

        left[i][j].attractivity=0;
        left[i][j].length=0;
        if(j-1 >= 0 && left[i][j-1].attractivity > tmp.attractivity){
          left[i][j].attractivity=left[i][j-1].attractivity;
          left[i][j].length=left[i][j-1].length;
        }

        left[i][j].attractivity+=tmp.attractivity;
        left[i][j].length+=1;
      }
    }
    
    for(int j=N-1;j>=0;--j){
      if(garden[i][j] == 0){
        field_t tmp={.attractivity=0, .length=0};
        for(uint8_t k=0;k<4;++k)
          if(i+verti[k]< M && j+horiz[k]< N && j+horiz[k]>=0 && i+verti[k]>=0)
            tmp.attractivity+=garden[i+verti[k]][j+horiz[k]];
        
        right[i][j].attractivity=0;
        right[i][j].length=0;
        if(j+1 < N && right[i][j+1].attractivity > tmp.attractivity){
          right[i][j].attractivity=right[i][j+1].attractivity;
          right[i][j].length=right[i][j+1].length;
        }
        right[i][j].attractivity+=tmp.attractivity;
        right[i][j].length+=1;
      }
    }
  }

  for(int i=1;i<M;++i){
    for(int j=0;j<N;++j){
      if(garden[i][j]==0 && (left[i-1][j].length!=M*N || (j-1 >= 0 && left[i][j-1].length!=M*N) ) ){
        if(j-1 >= 0 && left[i][j-1].length == M*N && left[i-1][j].length == M*N){//unreachable
          left[i][j].attractivity=0;
          left[i][j].length=M*N;
          continue;
        }

        field_t tmp={.attractivity=0, .length=0};
        for(uint8_t k=0;k<4;++k)
          if(i+verti[k]< M && j+horiz[k]< N && j+horiz[k]>=0 && i+verti[k]>=0)
            tmp.attractivity+=garden[i+verti[k]][j+horiz[k]];
          
        field_t max=maxAttractivity(left[i-1][j], right[i-1][j]);
        left[i][j].attractivity=tmp.attractivity;
        left[i][j].length=1;
        if(j-1 >= 0 && garden[i][j-1] == 0 && (left[i][j-1].attractivity > max.attractivity || (left[i][j-1].attractivity == max.attractivity && left[i][j-1].length < max.length)) ){
          left[i][j].attractivity+=left[i][j-1].attractivity;
          left[i][j].length+=left[i][j-1].length;
        }else{
          left[i][j].attractivity+=max.attractivity;
          left[i][j].length+=max.length;
        }
      }
    }
    for(int j=N-1;j>=0;--j){
      if(garden[i][j]==0 && (right[i-1][j].length!=M*N || (j+1 < N && right[i][j+1].length!=M*N) ) ){
        if(j+1 < N && right[i][j+1].length == M*N && right[i-1][j].length == M*N){//unreachable
          right[i][j].attractivity=0;
          right[i][j].length=M*N;
          continue;
        }

        field_t tmp={.attractivity=0, .length=0};
        for(uint8_t k=0;k<4;++k)
          if(i+verti[k]< M && j+horiz[k]< N && j+horiz[k]>=0 && i+verti[k]>=0)
            tmp.attractivity+=garden[i+verti[k]][j+horiz[k]];

        field_t max=maxAttractivity(left[i-1][j], right[i-1][j]);
        right[i][j].attractivity=tmp.attractivity;
        right[i][j].length=1;
        if(j+1 < N && garden[i][j+1] == 0 && (right[i][j+1].attractivity > max.attractivity || (right[i][j+1].attractivity == max.attractivity && right[i][j+1].length < max.length)) ){
          right[i][j].attractivity+=right[i][j+1].attractivity;
          right[i][j].length+=right[i][j+1].length;
        }else{
          right[i][j].attractivity+=max.attractivity;
          right[i][j].length+=max.length;
        }
      }
    }

  }

  /*
  for(int i=0;i<M;++i){
    for(int j=0;j<N;++j){
      printf("%zu ",left[i][j].attractivity);
     //printf("%d ",right[i][j].attractivity);
    }
    printf("\n");
  }
  printf("\n\n");
  for(int i=0;i<M;++i){
    for(int j=0;j<N;++j){
      //printf("%d ",left[i][j].attractivity);
      printf("%zu ",right[i][j].attractivity);
    }
    printf("\n");
  }
  */

  field_t final={.attractivity=0, .length=M};
  for(int j=0;j<N;++j){
    if(left[M-1][j].attractivity > final.attractivity || (left[M-1][j].attractivity == final.attractivity && left[M-1][j].length < final.length) )
      final=left[M-1][j];
    if(right[M-1][j].attractivity > final.attractivity || (right[M-1][j].attractivity == final.attractivity && right[M-1][j].length < final.length) )
      final=right[M-1][j];
  }
  
  printf("%zu %zu\n",final.attractivity,final.length);

  for(int i=0; i<M; ++i){
    free(left[i]);
    free(right[i]);
    free(garden[i]);
  }
  free(left);
  free(right);
  free(garden);
       
  return 0;
}

static field_t maxAttractivity(field_t a, field_t b){
  if(a.attractivity > b.attractivity || (a.attractivity == b.attractivity && a.length < b.length))
    return a;
  else
   return b;
}
