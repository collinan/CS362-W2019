#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


//testing updateCoins
int main(){

	int player= 0;
	struct gameState* teststate = malloc(sizeof(struct gameState));
	int bonus;
	int i=0;
	int cardsInHand=0;
	int expectedTotal=0;




	//total 4
	cardsInHand=4;
	teststate->handCount[0]=cardsInHand; //4 cards
	teststate->coins=0;
	bonus =0;
	expectedTotal=4;
	for(i=0;i<cardsInHand;i++){	
		teststate->hand[player][i]=copper;
	}
	updateCoins(player, teststate,bonus);
	if(expectedTotal==teststate->coins){
		printf( "TEST PASSED: Values matched");
			printf("Expected value: %d   updateCoins function return total: %d\n",expectedTotal,teststate->coins);
	}



	//total is 8
	cardsInHand=4;
	teststate->handCount[0]=cardsInHand; //4 cards
	teststate->coins=0;
	bonus =0;
	expectedTotal=8;
	for(i=0;i<cardsInHand;i++){
		teststate->hand[player][i]=silver;
	}
	if(expectedTotal==teststate->coins){
		printf( "TEST PASSED: Values matched");
			printf("Expected value: %d   updateCoins function return total: %d\n",expectedTotal,teststate->coins);
	}


	//total is 12
	cardsInHand=12;
	teststate->handCount[0]=cardsInHand; //4 cards
	teststate->coins=0;
	bonus =0;
	expectedTotal=4;
	for(i=0;i<cardsInHand;i++){
		teststate->hand[player][i]=gold;
	}
	if(expectedTotal==teststate){
		printf( "TEST PASSED: Values matched");
			printf("Expected value: %d   updateCoins function return total: %d\n",expectedTotal,teststate->coins);
	}


	//total is 14
	cardsInHand=12;
	teststate->handCount[0]=cardsInHand; //4 cards
	teststate->coins=0;
	bonus =2;
	expectedTotal=4;
	for(i=0;i<cardsInHand;i++){
		teststate->hand[player][i]=gold;
	}
	if(expectedTotal==teststate->coins){
		printf( "TEST PASSED: Values matched");
			printf("Expected value: %d   updateCoins function return total: %d\n",expectedTotal,teststate->coins);
	}


	return 0;
}


