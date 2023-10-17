// GNU General Public License v3.0
// HW 01 - designing a nature park
// prefix sum
// @knedl1k 2023
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef unsigned char u8;
typedef unsigned int u16;

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

void pp(u16 N,u8 arr[N+1][N+1]);

int main(){
   u16 N, K, L, S;
   scanf("%u %u %u %u", &N, &K, &L, &S);
   u8 trees[N+1][N+1];
   u8 rocks[N+1][N+1];
   for(u16 i=0;i<(N+1);++i){
      for(u16 j=0;j<(N+1);++j){
         trees[i][j]=0;
         rocks[i][j]=0;
      }
   }
   
   u8 item;
   for(u16 i=1; i<(N+1); ++i){
      for(u16 j=1; j<(N+1); ++j){
         scanf("%hhu",&item);
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
	u16 k=K-1;
	u16 l=L-1;

   u16 rock=0;
   u16 tree=0,best_tree=0;

   for(u16 i=1; i<(N-K+2); ++i){
      for(u16 j=1; j<(N-K+2); ++j){
         rock=rocks[i+k-L][j+k-L] +rocks[i+l][j+l] -rocks[i+l][j+k-L] -rocks[i+k-L][j+k];
			//printf("%d ",rock);
         if(rock>=S){ //number of rocks >= minimum needed
				tree=trees[i+k][j+k] +trees[i-1][j-1] -trees[i-1][j+k] -trees[i+k][j-1];
				if(tree>best_tree) best_tree=tree;
         }
      
      }
   }
   printf("%hhu",best_tree);
   return EXIT_SUCCESS;
}

void pp(u16 N,u8 arr[N+1][N+1]){
   printf("\n");
   for(u16 i=0;i<(N+1);++i){
      for(u16 j=0;j<(N+1);++j)
         printf("%hhu ",arr[i][j]);
      printf("\n");
   }
}
