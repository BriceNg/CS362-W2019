#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>


//testing smithy
int main() {
	
    struct gameState G;
    int seed = 1000;
    int numPlayers = 2;
    int currentPlayer = 0;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};  
    int deckSize;
    int handSize;
    int handPos;
    int deckBefore;
    int deckAfter;
    int handBefore;
    int handAfter;
    int discardBefore;
    int discardAfter;
    int i;
    int deckFailure = 0;
    int handFailure = 0;
    int discardFailure = 0;
    int testPassed = 0;
    int passed;
    
    srand(time(NULL));
   //randomize hand size
   
   printf("Running Random Smithy Test\n");
   
    for(i = 0; i < 1000000; i++){
        initializeGame(numPlayers, k, seed, &G);
        deckSize = rand() % (MAX_DECK + 1);
	//set handsize
        handSize = rand() % (deckSize + 1);
      
        
        G.deckCount[0] = deckSize - handSize;
        G.handCount[0] = handSize;
        
        handPos = G.hand[currentPlayer][G.handCount[currentPlayer] - 1];
        //personal checks
        deckBefore = G.deckCount[0];
        //printf("deck before %d\n", deckBefore);
        handBefore = G.handCount[0];
        //printf("Hand before %d\n",handBefore);
        discardBefore = G.playedCardCount;
        //printf("Discard before %d\n", discardBefore);
        
        
        playSmithy(currentPlayer, &G, handPos);
        
        deckAfter = G.deckCount[0];
        handAfter = G.handCount[0];
        discardAfter = G.playedCardCount;
        
        passed = 1;
        
        if(handAfter != (handBefore + 2)){
            printf("Smithy test failed: Didn't draw correctly\n");
            handFailure++;
            passed = 0;
        }
        
        if(deckAfter != (deckBefore - 3)){
            printf("Smithy test failed: Didn't remove from deck\n");
            deckFailure++;
            passed = 0;
        }
        
        if(discardAfter != (discardBefore + 1)){
            printf("Smithy test failed: Didn't discard\n");
            discardFailure++;
            passed = 0;
        }
        
        if(passed == 1){
            printf("Smithy tests passed.\n");
            testPassed++;
        }
        
    }
        
   printf("\n\n");
   printf("# of Tests Passed: %d\n", testPassed);
   printf("# of Cards Drawn To Hand Failed: %d\n", handFailure);
   printf("# of Smithy Discarded Fails: %d\n\n", discardFailure);        
   
   return 0;
}