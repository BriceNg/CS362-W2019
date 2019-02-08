#include <stdlib.h>
#include <stdio.h>
#include "assert.h"
#include "dominion.h"
#include "rngs.h"
#include <time.h>

/*****************************************************/
/***************Unit Test for whoseTurn***************/
/*****************************************************/
int main(){
	
	//Initalize variables
	struct gameState G;
	int turn = 0;
	int x = 0;
	int i;
	
	//For an arbitrary number of turns, check if whoseTurn works
	for(i = 0; i < 20; i++){
		
		//See whose turn it is
		G.whoseTurn = turn;
		x = whoseTurn(&G);
		assert(x == turn);
		
		//Increment turn
		turn++;
	}
	printf("whoseTurn passes the test\n");
	return 0;
}
