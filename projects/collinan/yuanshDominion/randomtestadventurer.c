//Filename: randomtestadventurer.c
//Testing: adventurer card
//Description: The adventurer card is a action card which allows you to flip through
//your deck and keep (add them to your deck) the first two treasure cards that are revealed.
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
	long seed = rand();
	

	int testpass=0;
	int testfail=0;
	

int i,p,w; //loop variable	
unsigned int num_cards_add_to_playerdeck;
int who;
int card;
int yes_treasure=0;
	int initial_handCount;
	int initial_deckCount;
	int initial_discardCount;
	int handcountfail=0;
	int deckcountfail=0;
	int discardcountfail;


	printf("\n**************************Begin test for Adventure Card***************************\n");
/*******************************Begin Testing*******************************/
for(p=0;p<NUMTESTS;p++){
//initialize the Game
if (initializeGame(NUMPLAYERS, k, seed, &G) != 0){
printf("Error initializing game.\n");
exit(1);	
}

num_cards_add_to_playerdeck=rand()%501;
who=G.whoseTurn;

//printf("Adding %d cards to players hand\n",num_cards_add_to_playerdeck);
for(i=0;i<num_cards_add_to_playerdeck;i++){
		
		card=rand()%13;
	switch(card){
		case 0:
				gainCard(adventurer,&G,1,who);
				break;
		case 1:
				gainCard(gardens,&G,1,who);
				break;
		case 2:
				gainCard(embargo,&G,1,who);
				break;
		case 3:
				gainCard(village,&G,1,who);
				break;
		case 4:
				gainCard(minion,&G,1,who);
				break;
		case 5:
				gainCard(mine,&G,1,who);
				break;
		case 6:
				gainCard(cutpurse,&G,1,who);
				break;
		case 7:
				gainCard(sea_hag,&G,1,who);
				break;
		case 8:
				gainCard(tribute,&G,1,who);
				break;
		case 9:
				gainCard(smithy,&G,1,who);
				break;
		case 10:
				gainCard(copper,&G,1,who);
				break;
		case 11:
				gainCard(silver,&G,1,who);
				break;
		case 12:
				gainCard(gold,&G,1,who);
				break;
		
	}
	
}
shuffle(who,&G);//shuffling deck



//printf("\n*******************************Game initialized values*******************************\n");
//printf("Number of Players:%d\n",G.numPlayers);
//printf("Which player turn:%d\n",whoseTurn(&G));
//printf("\n*******************************Begin Testing*******************************\n");


//printf("*******************************Player %d info*******************************\n",0);
	//printf("Initial player hand count: %d\n",G.handCount[0]);
	//printf("Initial player deck count: %d\n",G.deckCount[0]);
	//printf("Initial player discard count %d\n",G.discardCount[0]);
	initial_handCount=G.handCount[0];
	initial_deckCount=G.deckCount[0];
	initial_discardCount=G.discardCount[0];
//printf("****************************************************************************\n");
	
	
	
/*---------------------------------------------------------------------------*/
	
	//printf("\n*******************************Call to cardEffect*******************************\n");
	if(cardEffect(adventurer,0,0,0,&G,0,0) != 0){
		
		testfail++;
		continue;
	
	}
	
	yes_treasure=0;
	//check to see if deck has two treasure
	for(w=0;w<G.deckCount[0];w++){
	if (G.deck[0][w] == copper || G.deck[0][w] == silver || G.deck[0][w] == gold){
		if(yes_treasure == 2){
			//printf("Found two treasures in deck.");
			break;
		}
		yes_treasure++;
	}
			
	}
	
	
//printf("*******************************Post Player %d info*******************************\n",0);
	//printf("Post player hand count: %d\n",G.handCount[0]);
	//printf("Post player deck count: %d\n",G.deckCount[0]);
	//printf("Post player discard count %d\n",G.discardCount[0]);
	
	
	
	//there were two treasures in deck but did not get added to player hand
	if((initial_handCount+2) != G.handCount[0] && yes_treasure == 2 ){//treasure adding error
		//printf("Error treasure adding\n");
		 handcountfail++;
		testfail++;
		continue;
	//there were one treasures in deck but did not get added to player hand
	}else if((initial_handCount+1) != G.handCount[0] && yes_treasure == 1 ){
		//printf("Error treasure adding\n");
	}else if((initial_discardCount+initial_deckCount+initial_handCount) !=(G.handCount[0]+G.deckCount[0]+G.discardCount[0]) ){
		testfail++;
		deckcountfail++;
		continue;
		
	}
	
	testpass++;

	
	}
	printf("Number of fails due to treasure not added to hand:%d\n",handcountfail);
	printf("Number of fails due to players deck count being off:%d\n",deckcountfail);
	printf("Tests Passed:%d\n",testpass);
	printf("Tests Failed:%d\n",testfail);
	printf("Total Tests:%d\n",NUMTESTS);
	printf("****************************************************************************\n",i);
	return 0;

}

