// GNU General Public License v3.0
// HW 01 - designing a nature park
// prefix sum
// @knedl1k 2023
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/**
 * 1 ≤ N ≤ 3000
 * 1 ≤ K ≤ N
 * 0 ≤ 2*L < K
 * 1 ≤ S ≤ 15000
 */

int main(){
   unsigned short int N,K,L,S;
   scanf("%hu %hu %hu %hu", &N, &K, &L, &S);
   
   /* It won't fit on a stack. The allocation has to be dynamic, cuz data are stored on heap.

   unsigned short int trees[N+1][N+1];
   unsigned short int rocks[N+1][N+1];
   
   for(unsigned short int i=0;i<(N+1);++i){
      for(unsigned short int j=0;j<(N+1);++j){
         trees[i][j]=0;
         rocks[i][j]=0;
      }
   }
   */

   int **trees =(int **)calloc(N+1, sizeof(int *));
   int **rocks =(int **)calloc(N+1, sizeof(int *));
   /*
   if(trees==NULL || rocks==NULL){
      printf("Memory allocation failed. Exiting...");
      exit(1);
   }
   */
   for(int i = 0; i < N+1; ++i){
      trees[i] =(int *)calloc(N+1, sizeof(int));
      rocks[i] =(int *)calloc(N+1, sizeof(int));
      /*
      if(trees[i]==NULL || rocks[i]==NULL){
         printf("Memory allocation failed. Exiting...");
         exit(1);
      }
      */
   }

   for(unsigned short int i=1; i<(N+1); ++i){
      for(unsigned short int j=1; j<(N+1); ++j){
         unsigned char item;
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
   unsigned short int k=K-1;
   unsigned short int l=L-1;
   
   unsigned int rock;
   unsigned int tree,best_tree=0;

   for(unsigned short int i=1; i<(N-K+2); ++i){
      for(unsigned short int j=1; j<(N-K+2); ++j){
         rock=rocks[i+k-L][j+k-L] +rocks[i+l][j+l] -rocks[i+l][j+k-L] -rocks[i+k-L][j+k];
         if(rock>=S){ //number of rocks >= minimum needed
            tree=trees[i+k][j+k] +trees[i-1][j-1] -trees[i-1][j+k] -trees[i+k][j-1];
            if(tree>best_tree) best_tree=tree;
         }
      
      }
   }
   printf("%u",best_tree);

   for(int i = 0; i < N+1; i++){
      free(trees[i]);
      free(rocks[i]);
   }
   free(trees);
   free(rocks);
   return EXIT_SUCCESS;
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