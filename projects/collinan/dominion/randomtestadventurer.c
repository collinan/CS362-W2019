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

//randomtestadventurer.c
//testing adventurer_func()
//Description: The adventurer card is a action card which allows you to filp throug
//your deck and keep (add them to your deck) the first two treaseure cards that are revealed.
//
int main(){
	struct gameState G;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};

	srand(time(0));	
	//set seed to a number larger that 0, so no user input is expected.
	seed = rand();
	

	int testpass=0;
	int testfail=0;
	

	
//initialize the Game
if (initializeGame(NUMPLAYERS, k, seed, &G) != 0){
printf("Error initializing game.\n");	
}

printf("\n*******************************Begin Testing*******************************\n");
int currentPlayer = whoseTurn(state);

	printf("Initial player hand count: %d\n",G.handCount[currentPlayer]);
	printf("Initial player deck count: %d\n",G.deckCount[currentPlayer]);



	return 0;

}

