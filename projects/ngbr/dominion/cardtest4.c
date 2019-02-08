#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

/*****************************************************/
/****************Card Test for Steward****************/
/*****************************************************/

int main(int argc, char** argv){
	
	//Initalize variables
	struct gameState G;
	int choice1 = 0;
	int choice2 = 0;
	int choice3 = 0;
	int temp;
	
	//Initalize cards in Kingdom
	int k[10] = {adventurer, smithy, minion, steward, village, mine, cutpurse, gardens, sea_hag, feast};
	
	//Initalize the game
	initializeGame(2, k, 7, &G);
	
	//Choose option 1: Draw 2 cards
	choice1 = 1;
	//Set temp to players hand
	temp = numHandCards(&G);
	cardEffect(steward, choice1, choice2, choice3, &G, NULL);
	
	//Check if passed
	//Assert it did its job
	assert(numHandCards(&G) == temp + 1);
	printf("Steward card passed test.\n");
}