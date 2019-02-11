#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


//testing numHandCards(struct gameState *state) 

int main(){
	
	
	struct gameState* teststate = malloc(sizeof(struct gameState));
	int expectedvalue;
	int temp;
	
	teststate->whoseTurn = 0;//initialize with player one 
	teststate->handCount[0]=4;
	expectedvalue=4;
	temp= numHandCards(teststate);
	
			if(temp == expectedvalue){//compare expected and returned value
			printf( "TEST PASSED: Values matched");
				printf("Expected value: %d   numHandCards function return value: %d\n",expectedvalue,temp);
		}else{
			printf( "TEST FAILED: Values do not match");
				printf("Expected value: %d   numHandCards function return value: %d\n",expectedvalue,temp);
		}

free(teststate);
	return 0;
}