//GNU General Public License v3.0
//@knedl1k

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool foundString(const char *s1,const char *s2);

static void powerMatrix(const size_t S, size_t mat[S][S], size_t n, size_t result_mat[S][S]);
static void multiply(const size_t S, size_t a[S][S], size_t b[S][S]);
static void generateIdentity(const size_t S, size_t a[S][S]);

int main(void){
  size_t S, K, M;
  scanf("%zu %zu %zu",&S, &K, &M);
  char allowed[S][K];
  for(size_t i=0;i<S;++i)
    for(size_t j=0;j<K;++j)
      scanf(" %c ",&allowed[i][j]);

  size_t mat[S][S];

  char s1[K], s2[K];
  for(size_t i=0;i<S;++i){
    for(size_t k=1;k<K;++k)
      s1[k-1]=allowed[i][k];
    s1[K-1]='\0';

    for(size_t j=0;j<S;++j){
      for(size_t k=0;k<K-1;++k)
        s2[k]=allowed[j][k];
      s2[K-1]='\0';
      
      mat[i][j]=foundString(s1, s2);
    }
  }
  size_t res[S][S];
  powerMatrix(S, mat, M-K, res);

  size_t final=0;
  for(size_t i=0;i<S;++i)
    for(size_t j=0;j<S;++j)
      final+=res[i][j];
  
  printf("%zu\n",final);
  return 0;
}

bool foundString(const char *s1,const char *s2){
  return(strcmp(s1, s2)==0)? true:false; 
}

//caluclate mat^n and store result into result_mat
static void powerMatrix(const size_t S, size_t mat[S][S], size_t n, size_t result_mat[S][S]){
  generateIdentity(S,result_mat);

  while(n > 0){
    if(n % 2 == 0){
      multiply(S,mat,mat);
      n /= 2;
    }else{
      multiply(S,result_mat,mat);
      --n;
    }
  }
}

//multiply mat1 to mat2 and store result into mat1
static void multiply(const size_t S, size_t mat1[S][S], size_t mat2[S][S]){
  size_t tmp[S][S];
  for(size_t i=0;i<S;++i)
    for(size_t j=0;j<S;++j)
      tmp[i][j]=0;
  
  for(size_t i=0;i<S;++i)
    for(size_t j=0;j<S;++j)
      for(size_t k=0;k<S;++k)
        tmp[i][j] += mat1[i][k] * mat2[k][j];
      
  for(size_t i=0;i<S;++i)
    for(size_t j=0;j<S;++j)
      mat1[i][j]=tmp[i][j];
}

//E matrix
// 1 0 ... 0
// 0 1 ... 0
// ....
// 0 0 ... 1
static void generateIdentity(const size_t S, size_t mat[S][S]){
  for(size_t i=0;i<S;++i)
    for(size_t j=0;j<S;++j)
      mat[i][j]=(i == j);
}
