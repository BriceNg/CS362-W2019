#include <stdlib.h>
#include <stdio.h>
#include "assert.h"
#include "dominion.h"
#include "rngs.h"
#include <time.h>

/******************************************************/
/***************Unit Test for isGameOver***************/
/******************************************************/

int main(){

	//Initalize variables
	struct gameState G;
	int s;
	
	//Initalize cards in Kingdom
	int k[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	//Initalize the game
	initializeGame(2, k, 2, &G);

	//Set # of provinces
	G.supplyCount[province] = 0;
	
	//Check if game is over
	s = isGameOver(&G);
	assert(s == 1);
	printf("isGameOver has passed\n");

	//Set # of propterties to 0 so game ends
	G.supplyCount[1] = 0;
	G.supplyCount[4] = 0;
	G.supplyCount[7] = 0;

	s = isGameOver(&G);

	assert(s == 1);
	printf("isGameOver has Passed\n");

	return 0;
}