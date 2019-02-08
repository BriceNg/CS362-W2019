#include <stdlib.h>
#include <stdio.h>
#include "assert.h"
#include "dominion.h"
#include "rngs.h"
#include <time.h>'

//Unit Test for buyCard

int main(){
	
	//Initalize variables
	struct gameState G;
	int s;
	int k[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	//Initalize game
	initializeGame(2, k, 2, &G);
	
	//Set number of buys to 0
	G.numBuys = 0;

	//Try to buy a card
	s = buyCard(5, &G);

	//Check if failure (cannot buy with 0 buys)
	assert(s == -1);

	//Set number of buys to 5
	G.numBuys = 5;

	//Set number of coins to 0
	G.coins = 0;

	//Try to buy a card
	s = buyCard(5, &G);

	//Check if failure (cannot buy with 0 coins)
	assert(s == -1);

	//Set number of coins to 30 (ensures they can buy)
	G.coins = 30;

	//Try to buy a card
	s = buyCard(5, &G);

	//Check if success (cannot buy with 0 coins)
	assert(s == 0);

	printf("buyCard test passed\n");
	return 0;
}