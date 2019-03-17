//Filename: randomtestcard1.c
//Testing: village card
//Description: 
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
	
	unsigned int num_cards_add_to_playerdeck;
	int who;
	
	int testpass=0;
	int testfail=0; 
	
	int initial_handCount;
	int initial_deckCount;
	int initial_discardCount;
	int initial_numActions;
	int addaction_fail=0;
	int add_rm_card_fail=0;
	int p,i;
	int card;
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



	 initial_handCount=G.handCount[0];
	 initial_deckCount=G.deckCount[0];
	 initial_discardCount=G.discardCount[0];
	 initial_numActions=G.numActions;
	 
	 if(cardEffect(village,0,0,0,&G,0,0) != 0){
		
		testfail++;
		continue;
	
	}
	 
	 //check number of actions increased
	 if((initial_numActions+2) != G.numActions){
		 printf("Adding actions failed\n");
		 addaction_fail++;
		 testfail++;
		 continue;
	 }
	 
	 //check numbers of cards in player hand
	 if(initial_handCount!=G.handCount[0] || (initial_discardCount)!=G.discardCount[0] ){
		 printf("Adding and removing card from hand failed\n");
		 testfail++;
		 add_rm_card_fail++;
		 continue;
	 }
	 
	 
	 testpass++;
	
}
	
	printf("Fails due to Actions:%d\n",addaction_fail);
	printf("Fails due Adding and removing card:%d\n",add_rm_card_fail);
	printf("Tests Passed:%d\n",testpass);
	printf("Tests Failed:%d\n",testfail);
	printf("Total Tests:%d\n",NUMTESTS);
	
	return 0;
}
