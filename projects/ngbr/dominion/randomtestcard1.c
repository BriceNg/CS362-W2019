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

	for (i = 0; i < MAX_TESTS; i++)
	{
		players = rand() % 4;
		seed = rand();
		//Initialize Game
		initializeGame(players, k, seed, &state);

		//Initiate valid state variables
		state.deckCount[player] = rand() % MAX_DECK;
		state.discardCount[player] = rand() % MAX_DECK;
		state.handCount[player] = rand() % MAX_HAND;

		//Copy state variables
		handCount = state.handCount[player];
		deckCount = state.deckCount[player];
		printf("%d\n", i);
		//Test smithy
		cardEffect(smithy, 1, 1, 1, &state);
		printf("%dB\n", i);
	}

	for (i = 0; i < MAX_TESTS; i++)
	{
		printf("Before\n");
		//initialize new Gamestate
		initializeGame(players, k, seed, &stat);
		printf("After\n");
		
		//Initiate valid state variables
		stat.deckCount[player] = rand() % MAX_DECK;
		stat.discardCount[player] = rand() % MAX_DECK;
		stat.handCount[player] = rand() % MAX_HAND;

		//Copy state variables
		handCount = stat.handCount[player];
		deckCount = stat.deckCount[player];
		printf("%d\n", i);
		//Test smithy
		cardEffect(smithy, 1, 1, 1, &stat);
		printf("%dB\n", i);
	}

	for (i = 0; i < MAX_TESTS; i++)
	{
		printf("Before2\n");
		//initialize Gamestate
		initializeGame(players, k, seed, &sta);
	  	printf("After2\n");

		//Initiate valid state variables
		sta.deckCount[player] = rand() % MAX_DECK; //Pick random deck size out of MAX DECK size
		sta.discardCount[player] = rand() % MAX_DECK;
		sta.handCount[player] = rand() % MAX_HAND;

		//Copy state variables
		handCount = sta.handCount[player];
		deckCount = sta.deckCount[player];
		printf("%d\n", i);
		//Test smithy
		cardEffect(smithy, 1, 1, 1, &sta);

		printf("%dB\n", i);
	}

	printf("\nSmithy Tests Complete\n");
	return 0;
}