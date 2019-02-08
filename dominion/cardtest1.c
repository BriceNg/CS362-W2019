#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

/******************************************************/
/***************Card Test for Adventurer***************/
/******************************************************/

int main(int argc, char** argv){
	
	//Initalize variables
	struct gameState G;
	int choice1 = 0;
	int choice2 = 0;
	int choice3 = 0;
	
	//Initalize cards in Kingdom
	int k[10] = {adventurer, smithy, minion, steward, village, mine, cutpurse, gardens, sea_hag, feast};
	
	//Initalize the game
	initializeGame(2, k, 7, &G);
	
	//Check if passed
	//Assert it did its job
	assert(cardEffect(adventurer, choice1, choice2, choice3, &G, NULL) == 0);
	//Output passed
	printf("Adventurer card passed test.\n");
	return 0;
}