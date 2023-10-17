// GNU General Public License v3.0
// HW 01 - designing a nature park
// prefix sum
// @knedl1k 2023
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

void pp(size_t N,size_t arr[N+1][N+1]);

int main(){
   size_t N, K, L, S;
   scanf("%lu %lu %lu %lu", &N, &K, &L, &S);
   size_t trees[N+1][N+1];
   size_t rocks[N+1][N+1];

   for(size_t i=0;i<(N+1);++i){
      for(size_t j=0;j<(N+1);++j){
         trees[i][j]=0;
         rocks[i][j]=0;
      }
   }
   
   size_t item;
   for(size_t i=1; i<(N+1); ++i){
      for(size_t j=1; j<(N+1); ++j){
         scanf("%lu",&item);
         if(item==1){ //tree
            trees[i][j]=1;
            rocks[i][j]=0;
         }else if(item==2){ //rock
            rocks[i][j]=1;
            trees[i][j]=0;
         }
         trees[i][j]+=trees[i][j-1]+trees[i-1][j]-trees[i-1][j-1]; //!requires that all places in arr are set to 0 in default
         rocks[i][j]+=rocks[i][j-1]+rocks[i-1][j]-rocks[i-1][j-1]; //!faster approach would be the old + set just the minimum;
      }
   }

   //subconstants for better optimalization
   size_t k=K-1;
   size_t l=L-1;

   size_t rock=0;
   size_t tree=0,best_tree=0;

   for(size_t i=1; i<(N-K+2); ++i){
      for(size_t j=1; j<(N-K+2); ++j){
         rock=rocks[i+k-L][j+k-L] +rocks[i+l][j+l] -rocks[i+l][j+k-L] -rocks[i+k-L][j+k];
         //printf("%lu ",rock);
         if(rock>=S){ //number of rocks >= minimum needed
            tree=trees[i+k][j+k] +trees[i-1][j-1] -trees[i-1][j+k] -trees[i+k][j-1];
            if(tree>best_tree) best_tree=tree;
         }
      
      }
   }
   printf("%lu",best_tree);
   return EXIT_SUCCESS;
}

void pp(size_t N,size_t arr[N+1][N+1]){
   printf("\n");
   for(size_t i=0;i<(N+1);++i){
      for(size_t j=0;j<(N+1);++j)
         printf("%lu ",arr[i][j]);
      printf("\n");
   }
}

/**
 * 0 meadow
 * 1 woods
 * 2 rocks
 */ 

/**
 * N whole area
 * K area of the park we want
 * L distance of the edge of the central part from the edge of the park
 * S minimal num of rocks in the park
 */

/**
 * 1 ≤ N ≤ 3000
 * 1 ≤ K ≤ N
 * 0 ≤ 2*L < K
 * 1 ≤ S ≤ 15000
 */