#include "dominion.h"
#include "rngs.h"
#include "dominion_helpers.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <time.h>

#define NUMTESTS 50
#define NUMPLAYERS 2 //game rules state players can be between 2 and 4, and since adventurer_funt does
//not deal with setting up players we can fix number of players


int main(){
	struct gameState G;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};
	
	srand(time(0));	
	//set seed to a number larger that 0, so no user input is expected.
	seed = rand();
	
	
	//initialize the Game
if (initializeGame(NUMPLAYERS, k, seed, &G) != 0){
printf("Error initializing game.\n");	
}
	
	return 0;
}