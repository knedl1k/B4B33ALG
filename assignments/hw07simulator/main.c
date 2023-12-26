//GNU General Public License v3.0
//@knedl1k

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool foundString(const char *s1,const char *s2);
static void pPrint(const size_t S, const size_t K, char allowed[S][K]);

static void power(const size_t S, size_t a[S][S], size_t n, size_t res[S][S]);
static void mul(const size_t S, size_t a[S][S], size_t b[S][S]);
static void one(const size_t S, size_t a[S][S]);

int main(void){
  size_t S, K, M;
  scanf("%zu %zu %zu",&S, &K, &M);
  printf("S: %zu, K:%zu, M:%zu\n",S,K,M);
  char allowed[S][K];
  for(size_t i=0;i<S;++i){
    for(size_t j=0;j<K;++j){
      scanf(" %c ",&allowed[i][j]);
      printf("%c",allowed[i][j]);
    }
    printf("<\n");
  }

  //pPrint(S, K, allowed);

  //bool v[S];
  //for(size_t i=0;i<S;++i)
  //  v[i]=true;

  size_t mat[S][S];

  
  char s1[K-1];
  char s2[K-1];
  printf("%zu\n",K-1);
  for(size_t i=0;i<S;++i){
    for(size_t k=1;k<K;++k)
      s1[k-1]=allowed[i][k];
    
    for(size_t j=0;j<S;++j){
      for(size_t k=0;k<K-1;++k)
        s2[k]=allowed[j][k];
      printf(">%s< >%s<\n", s1, s2);
      mat[i][j]=foundString(s1, s2);
    }
  }
  
  for(size_t i=0;i<S;++i){
    for(size_t j=0;j<S;++j)
      printf("%zu",mat[i][j]);
    printf("\n");
  }
  
  size_t res[S][S];
  power(S, mat, M-K, res);

  size_t final=0;
  for(size_t i=0;i<S;++i)
    for(size_t j=0;j<S;++j)
      final+=res[i][j];
    
  
  printf("final: %zu\n",final);
  return 0;
}

bool foundString(const char *s1,const char *s2){
  return(strcmp(s1, s2)==0)? true:false; 
}

//It's simple E matrix
// 1 0 ... 0
// 0 1 ... 0
// ....
// 0 0 ... 1
static void one(const size_t S, size_t a[S][S]){
  for(size_t i=0;i<S;++i)
    for(size_t j=0;j<S;++j)
      a[i][j]=(i == j);
}

//Multiply matrix a to matrix b and print result into a
static void mul(const size_t S, size_t a[S][S], size_t b[S][S]){
  size_t res[S][S];
  for(size_t i=0;i<S;++i)
    for(size_t j=0;j<S;++j)
      res[i][j]=0;
  
  for(size_t i=0;i<S;++i)
    for(size_t j=0;j<S;++j)
      for(size_t k=0;k<S;++k)
        res[i][j] += a[i][k] * b[k][j];
      
  for(size_t i=0;i<S;++i)
    for(size_t j=0;j<S;++j)
      a[i][j]=res[i][j];
}

//Caluclate a^n and print result into matrix res
static void power(const size_t S, size_t a[S][S], size_t n, size_t res[S][S]){
  one(S,res);

  while(n > 0){
    //printf("meow\n");
    if(n % 2 == 0){
      mul(S,a,a);
      n /= 2;
    }else{
      mul(S,res, a);
      --n;
    }
  }
}


static void pPrint(const size_t S, const size_t K, char allowed[S][K]){
  for(size_t i=0;i<S;++i){
    for(size_t j=0;j<K;++j){
      printf("%c",allowed[i][j]);
    }
    printf("\n");
  }
}