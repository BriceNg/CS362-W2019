#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_TESTS 500

//Random test of Smithy

int main()
{
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};

	int i, j, n, players, player, handCount, deckCount, seed, address;
	//struct gameState state;
	struct gameState state;
	struct gameState stat;
	struct gameState sta;

	printf("Running Random Card Test #1 (Smithy)\n");
	players = 0;
	
	for (i = 0; i < MAX_TESTS; i++)
	{
		players = rand() % 4;
		seed = rand();
		//Initialize Game
		initializeGame(players, k, seed, &state);
		//Initiate valid state variables
		for(int player = 0; j < players; player++)
		{
			state.deckCount[player] = rand() % MAX_DECK; //Pick random deck size out of MAX DECK size
			state.discardCount[player] = rand() % MAX_DECK;
			state.handCount[player] = rand() % MAX_HAND;

			//Copy state variables
			handCount = state.handCount[player];
			deckCount = state.deckCount[player];
		}
		//1 in 3 chance of making empty deck for coverage
		if (seed % 3 == 0)
		{
			state.deckCount[player] = 0;
		}
		//Test Smithy card
		playCard(9, 1, 1, 1, &state);
	}

	for (i = 0; i < MAX_TESTS; i++)
	{
		players = rand() % 4;
		seed = rand();
		//Initialize Game
		initializeGame(players, k, seed, &state);
		//Initiate valid state variables
		for(int player = 0; j < players; player++)
		{
			state.deckCount[player] = rand() % MAX_DECK; //Pick random deck size out of MAX DECK size
			state.discardCount[player] = rand() % MAX_DECK;
			state.handCount[player] = rand() % MAX_HAND;

			//Copy state variables
			handCount = state.handCount[player];
			deckCount = state.deckCount[player];
		}
		//1 in 3 chance of making empty deck for coverage
		if (seed % 3 == 0)
		{
			state.deckCount[player] = 0;
		}
		//Test Smithy card
		playCard(9, 1, 1, 1, &state);
	}

	for (i = 0; i < MAX_TESTS; i++)
	{
		players = rand() % 4;
		seed = rand();
		//Initialize Game
		initializeGame(players, k, seed, &state);
		//Initiate valid state variables
		for(int player = 0; j < players; player++)
		{
			state.deckCount[player] = rand() % MAX_DECK; //Pick random deck size out of MAX DECK size
			state.discardCount[player] = rand() % MAX_DECK;
			state.handCount[player] = rand() % MAX_HAND;

			//Copy state variables
			handCount = state.handCount[player];
			deckCount = state.deckCount[player];
		}
		//1 in 3 chance of making empty deck for coverage
		if (seed % 3 == 0)
		{
			state.deckCount[player] = 0;
		}
		//Test Smithy card
		playCard(9, 1, 1, 1, &state);
	}

	printf("\nSmithy Tests Complete\n");
	return 0;
}