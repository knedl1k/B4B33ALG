// GNU General Public License v3.0
// HW 01 - designing a nature park
// @knedl1k 2023
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

int main(){
	unsigned int N, K, L, S;
	scanf("%u %u %u %u", &N, &K, &L, &S);
	unsigned char park[N][N];
	for(unsigned int i=0; i<N; ++i){
		for(unsigned int j=0; j<N; ++j){
			scanf("%hhu",&park[i][j]);
		}
	}

	
	return EXIT_SUCCESS;
}