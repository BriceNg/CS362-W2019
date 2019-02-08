#include <stdlib.h>
#include <stdio.h>
#include "assert.h"
#include "dominion.h"
#include "rngs.h"
#include <time.h>

/*****************************************************/
/****************Unit Test for getCost****************/
/*****************************************************/

int main(){

	//Test cost of nothing
	assert(getCost(0) == 0);
	printf("getCost has passed cost of 0\n");

	//Test cost of Adventurer
	assert(getCost(adventurer) == 6);
	printf("getCost has passed cost of Adventurer\n");

	//Test cost of village
	assert(getCost(village) == 3);
	printf("getCost has passed cost of village\n");

	//Test cost of Baron
	assert(getCost(baron) == 4);
	printf("getCost has passed cost of baron\n");
	
	return 0;
}