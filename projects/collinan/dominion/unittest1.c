#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


//testing int whoseTurn()


int main(){
	struct gameState* teststate = malloc(sizeof(struct gameState));
	int expected_value;
	int temp=0;//holds function reutn value or number corresponfin to whose turn it is currentls
int i;



	teststate->whoseTurn = 0;//initialize with player one 
	expected_value=0;//initialize with player one 

	for(i=0;i< MAX_PLAYERS;i++){

		teststate->whoseTurn =i;//set player number in game struct 
		expected_value=i;//	set expected player value whoseTurn should return
		temp=whoseTurn(teststate);
		if(temp == expected_value){//compare expected and returned value
			printf( "TEST PASSED: Values matched");
				printf("Expected value: %d   whoseTurn function return value: %d\n",expected_value,temp);
		}

	}


	return 0;
}
