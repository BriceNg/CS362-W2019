#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

/********************************************************/
/***************Card Test for Council Room***************/
/********************************************************/

int main(int argc, char** argv){
	
	//Initalize variables
	struct gameState G;
	int choice1 = 0;
	int choice2 = 0;
	int choice3 = 0;
	int temp;
	int buys;
	
	//Initalize cards in Kingdom
	int k[10] = {adventurer, smithy, minion, steward, village, mine, cutpurse, gardens, sea_hag, feast};
	
	//Initalize the game
	initializeGame(2, k, 7, &G);
	
	//Get number of player buys
	buys.G.numBuys;
	
	//Get temp hand for council room effect
	temp = numHandCards(&G);
	cardEffect(council_room, choice1, choice2, choice3, &G, NULL);
	
	//Check if passed
	//Assert it did its job
	assert(G.numbuys == buys + 1);
	assert(numHandCards(&G) == temp + 2);
	printf("Council Room card passed test.\n");
}